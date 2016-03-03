#pragma once

#include <cstdio>
#include <sys/stat.h>

#include <string>
#include <vector>

#include "types.h"
#include "utils.h"

#ifndef ED2K_PARTFILE_SIZE
#define ED2K_PARTFILE_SIZE 9728000
#endif

enum class hash_type {INVALID = 0xFF, MD4 = 0x14, MD5 = 0x15,
	SHA1 = 0x21, SHA224 = 0x22, SHA256 = 0x23,
	SHA384 = 0x24, SHA512 = 0x25};

struct hash_ctr {
	hash_ctr(hash_type flag)
	{
		switch(flag) {
		case hash_type::MD4:
		case hash_type::MD5:
			block_len = 64;
			hash_len = 16;
			break;
		case hash_type::SHA1:
			block_len = 64;
			hash_len = 20;
			break;
		case hash_type::SHA224:
		case hash_type::SHA256:
			block_len = 64;
			hash_len = 32;
			break;
		case hash_type::SHA384:
		case hash_type::SHA512:
			block_len = 128;
			hash_len = 32;
			break;
		default:
			break;
		}

		block = new uint8[block_len];
		hash = new uint32[hash_len/4];
	}

	~hash_ctr()
	{
		delete[] block;
		delete[] hash;
	}

	uint64 bit_count;
	uint8 block_len;
	uint8 hash_len;
	uint8 *block;
	uint32 *hash;
};

/* Abstract parent class for MD4, MD5, SHA-1 and SHA-2 */
struct hasher {
	hasher(hash_type flag) : type(flag) {}
	hasher(hasher& y) : type(y.type), hash(y.hash) {}

	virtual ~hasher() {clear();}

	hasher& operator=(hasher &y)
	{
		this->hash = y.hash;
		this->type = y.type;
		return *this;
	}

	inline bool operator==(hasher &y)
	{
		return this->type == y.type && this->hash == y.hash;
	}

	inline bool operator!=(hasher &y)
	{
		return !(this->type == y.type && this->hash == y.hash);
	}

	bool hashset(char *buf, uint64 len);
	bool hashset(FILE *in);

	bool is_md4()
	{
		if (type == hash_type::MD4)
			return true;
		return false;
	}

	bool is_md5()
	{
		if (type == hash_type::MD5)
			return true;
		return false;
	}

	bool is_sha1()
	{
		if (type == hash_type::SHA1)
			return true;
		return false;
	}

	bool is_valid()
	{
		if (type == hash_type::INVALID)
			return false;
		return true;
	}

	std::string to_string()
	{
		if (type == hash_type::INVALID)
			return NULL;

		std::string s;

		for (size_t i = 0; i < hash.size(); i++) {
			uint d = hash[i];
			char nh = (d & 0xf0) >> 4;
			char nl = d & 0x0f;

			if (nh < 10)
				nh += 0x30;
			else
				nh += 87;

			if (nl < 10)
				nl += 0x30;
			else
				nl += 87;

			s.push_back(nh);
			s.push_back(nl);
		}

		return s;
	}

	void clear()
	{
		hash.clear();
		type = hash_type::INVALID;
	}

	bool hash_init(uint64 len, hash_ctr &ctr);

	virtual void hash_first(hash_ctr &ctr) {return;}
	void hash_updating(char *buf, uint64 len, hash_ctr &ctr);
	void hash_last(hash_ctr &ctr);

	typedef void (*hasher_loop)(uint32 *state, uint32 *x);
	hasher_loop hash_transform;

	hash_type type;

	/* The hash is Big-Endian */
	std::vector<uint8> hash;
};
