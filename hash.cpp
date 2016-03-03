#include "hash.h"

bool hasher::hashset(char *buf, uint64 len)
{
	hash_ctr ctr(type);

	if (hash_init(len, ctr)) {
		hash_updating(buf, len, ctr);
		hash_last(ctr);
		return true;
	}

	clear();
	return false;
}

bool hasher::hashset(FILE *in)
{
#define CACHE_SIZE	16384

	fseek(in,0,SEEK_SET);

	struct stat64 in_stat;
	int in_fd = fileno(in);
	if(!in || in_fd == -1) {
		clear();
		return false;
	}

	fstat64(in_fd, &in_stat);
	uint64 len = in_stat.st_size;

	hash_ctr ctr(type);

	if (!hash_init(len, ctr)) {
		clear();
		return false;
	}

	char cache[CACHE_SIZE] = {0};

	uint64 ld = len / CACHE_SIZE;
	for (uint64 i=0; i<ld; i++) {
		fread(cache, CACHE_SIZE, 1, in);
		hash_updating(cache, CACHE_SIZE, ctr);
	}

	fread(cache, len % CACHE_SIZE, 1, in);
	hash_updating(cache, len % CACHE_SIZE, ctr);

	hash_last(ctr);

	fclose(in);

	return true;
}

bool hasher::hash_init(uint64 in_len, hash_ctr &ctr)
{
	/* bit_size update. */
	/* We assume that the files are always less than 2^61 bytes. */
	if (in_len >> 61) {
		clear();
		return false;
	}

	ctr.bit_count = in_len << 3;

	hash_first(ctr);

	return true;
}

void hasher::hash_updating(char *buf, uint64 len, hash_ctr &ctr)
{
	/* We assume that len%64 = 0 */
	uint8  lm = len & (ctr.block_len-1);
	uint64 lt = len - lm;
	//char *bte = buf + lt;

	//while (buf < bte) {
	for (uint64 i=0; i<lt; i += ctr.block_len)
		hash_transform(ctr.hash, (uint32*)(buf+i));

	/* If len%64 != 0, we consider it's the last piece of input blocks */
	if (lm) memcpy(ctr.block, buf+len-lm, lm);
}

void hasher::hash_last(hash_ctr &ctr)
{
	//uint32 *bit_count = &ctr.bit_count;

	uint32 last		= (ctr.bit_count >> 3) & (ctr.block_len-1);
	//uint32 padding		= last < 56 ? 56 - last : 120 - last;

	memset(ctr.block+last,0x80,1);
	memset(ctr.block+last+1,0,ctr.block_len-last-1);

	/* In SHA, we should change the Endian of bit_count(an 8 byte word) */
	uint8 *bit_count = (uint8*)&ctr.bit_count;

	if ( type == hash_type::MD4 || type == hash_type::MD5)
		memcpy(ctr.block+ctr.block_len-8,bit_count,8);
	else {
		for(int i=0; i<8; i++)
			(ctr.block+ctr.block_len-8)[i] = (bit_count)[7-i];

		for(int i=0; i<ctr.hash_len/4; i++)
			ctr.hash[i] = WORD_CHANGE_ENDIAN(ctr.hash[i]);
	}

	hash_transform(ctr.hash, (uint32*)(ctr.block));

	for (int i=0; i<ctr.hash_len; i++)
		hash.push_back(((uint8*)ctr.hash)[i]);
}
