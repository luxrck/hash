#pragma once

#include "hash.h"

/* MD5Transform function */
void md5_transform(uint32 state[4], uint32 x[16]);

struct md5_hash : public hasher {
	md5_hash(char *buf, uint64 len) : hasher(hash_type::MD5) {hashset(buf,len);}
	md5_hash(FILE *in) : hasher(hash_type::MD5) {hashset(in);}
	md5_hash(md5_hash& y) : hasher(y) {}
	md5_hash() : hasher(hash_type::MD5) {hashset(NULL, 0);}

	virtual void hash_first(hash_ctr &ctr)
	{
		ctr.hash[0] = 0x67452301;
		ctr.hash[1] = 0xefcdab89;
		ctr.hash[2] = 0x98badcfe;
		ctr.hash[3] = 0x10325476;

		hash_transform = md5_transform;
	}
};

/* Constants for MD5Transform routine. */
#define MD5_S11 7
#define MD5_S12 12
#define MD5_S13 17
#define MD5_S14 22
#define MD5_S21 5
#define MD5_S22 9
#define MD5_S23 14
#define MD5_S24 20
#define MD5_S31 4
#define MD5_S32 11
#define MD5_S33 16
#define MD5_S34 23
#define MD5_S41 6
#define MD5_S42 10
#define MD5_S43 15
#define MD5_S44 21

/* MD5 auxiliary functions */
#define MD5_F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | (~z)))

/* MD5_FF, MD5_GG, MD5_HH, and MD5_II transformations for rounds 1, 2, 3, and 4.
 * Rotation is separate from addition to prevent recomputation.
 */
#define MD5_FF(a, b, c, d, x, s, ac) { \
	(a) += MD5_F ((b), (c), (d)) + (x) + (uint32)(ac); \
	(a) = WORD_ROL ((a), (s)); \
	(a) += (b); \
}

#define MD5_GG(a, b, c, d, x, s, ac) { \
	(a) += MD5_G ((b), (c), (d)) + (x) + (uint32)(ac); \
	(a) = WORD_ROL ((a), (s)); \
	(a) += (b); \
}

#define MD5_HH(a, b, c, d, x, s, ac) { \
	(a) += MD5_H ((b), (c), (d)) + (x) + (uint32)(ac); \
	(a) = WORD_ROL ((a), (s)); \
	(a) += (b); \
}

#define MD5_II(a, b, c, d, x, s, ac) { \
	(a) += MD5_I ((b), (c), (d)) + (x) + (uint32)(ac); \
	(a) = WORD_ROL ((a), (s)); \
	(a) += (b); \
}
