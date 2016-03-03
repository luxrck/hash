#pragma once

#include "hash.h"

/* SHA1Transform function */
void sha1_transform(uint32 state[5], uint32 x[16]);

struct sha1_hash : public hasher {
	sha1_hash(char *buf, uint64 len) : hasher(hash_type::SHA1) {hashset(buf, len);}
	sha1_hash(FILE *in) : hasher(hash_type::SHA1) {hashset(in);}
	sha1_hash(sha1_hash& y) : hasher(y) {}
	sha1_hash() : hasher(hash_type::SHA1) {hashset(NULL, 0);}

	virtual void hash_first(hash_ctr &ctr)
	{
		ctr.hash[0] = 0x67452301;
		ctr.hash[1] = 0xefcdab89;
		ctr.hash[2] = 0x98badcfe;
		ctr.hash[3] = 0x10325476;
		ctr.hash[4] = 0xc3d2e1f0;

		hash_transform = sha1_transform;
	}
};

#define SHA1_K1 0x5a827999
#define SHA1_K2 0x6ed9eba1
#define SHA1_K3 0x8f1bbcdc
#define SHA1_K4 0xca62c1d6

#define SHA1_F1(b,c,d) ((b & c) | ((~b) & d))
#define SHA1_F2(b,c,d) (b xor c xor d)
#define SHA1_F3(b,c,d) ((b & c) | (d & (b | c)))
#define SHA1_F4(b,c,d) (b xor c xor d)

#define SHA1_M(buf,i) \
	(buf[i] = WORD_ROL((buf[i-3] xor buf[i-8] xor buf[i-14] xor buf[i-16]), 1))

#define SHA1_R(a,b,c,d,e,f,k,m) \
	( (e += WORD_ROL(a,5) + f(b,c,d) + k + m),  \
	(b = WORD_ROL(b,30)) )
