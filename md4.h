#pragma once

#include "hash.h"

/* MD4Transform function */
void md4_transform(uint32 state[4], uint32 x[16]);

struct md4_hash : public hasher {
	md4_hash(char* buf, uint64 len) : hasher(hash_type::MD4) {hashset(buf,len);}
	md4_hash(FILE *in) : hasher(hash_type::MD4) {hashset(in);}
	md4_hash(md4_hash& y) : hasher(y) {}
	md4_hash() : hasher(hash_type::MD4) {hashset(NULL, 0);}

	virtual void hash_first(hash_ctr &ctr)
	{
		ctr.hash[0] = 0x67452301;
		ctr.hash[1] = 0xefcdab89;
		ctr.hash[2] = 0x98badcfe;
		ctr.hash[3] = 0x10325476;

		hash_transform = md4_transform;
	}
};

/* Constants for MD4Transform routine. */
#define MD4_S11 3
#define MD4_S12 7
#define MD4_S13 11
#define MD4_S14 19
#define MD4_S21 3
#define MD4_S22 5
#define MD4_S23 9
#define MD4_S24 13
#define MD4_S31 3
#define MD4_S32 9
#define MD4_S33 11
#define MD4_S34 15

/* MD4 auxiliary functions. */
#define MD4_F(x, y, z) ( (z) ^ ( (x) & ( (y) ^ (z) ) ) )
#define MD4_G(x, y, z) ( (x) & (y) | ( (z) & ( (x) | (y) ) ) )
#define MD4_H(x, y, z) ( (x) ^ (y) ^ (z) )

/* MD4_FF, MD4_GG, MD4_HH, and MD4_II transformations for rounds 1, 2 and 3.
 * Rotation is separate from addition to prevent recomputation.
 */
#define MD4_FF(a, b, c, d, x, s) { \
	(a) += MD4_F((b), (c), (d)) + (x); \
	(a) = WORD_ROL((a), (s)); \
}

#define MD4_GG(a, b, c, d, x, s) { \
	(a) += MD4_G((b), (c), (d)) + (x) + (uint32)0x5A827999; \
	(a) = WORD_ROL((a), (s)); \
}

#define MD4_HH(a, b, c, d, x, s) { \
	(a) += MD4_H((b), (c), (d)) + (x) + (uint32)0x6ED9EBA1; \
	(a) = WORD_ROL((a), (s)); \
}
