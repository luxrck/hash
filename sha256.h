#pragma once

#include "hash.h"

/* Public SHA macros for SHA224/256/284/512 */
#define SHA_CH(x, y, z) ((x & y) ^ ((~x) & z))
#define SHA_MAJ(x, y, z) ((x & y) ^ (y & z) ^ (x & z))

/* SHA1Transform function */
void sha256_transform(uint32 state[8], uint32 x[16]);

struct sha256_hash : public hasher {
	sha256_hash(char *buf, uint64 len) : hasher(hash_type::SHA256) {hashset(buf, len);}
	sha256_hash(FILE *in) : hasher(hash_type::SHA256){hashset(in);}
	sha256_hash(sha256_hash& y) : hasher(y) {}
	sha256_hash() : hasher(hash_type::SHA256){hashset(NULL, 0);}
/*
	virtual void hash_first(hash_ctr &ctr)
	{
		ctr.hash[0] = 0xc1059ed8;
		ctr.hash[1] = 0x367cd507;
		ctr.hash[2] = 0x3070dd17;
		ctr.hash[3] = 0xf70e5939;
		ctr.hash[4] = 0xffc00b31;
		ctr.hash[5] = 0x68581511;
		ctr.hash[6] = 0x64f98fa7;
		ctr.hash[7] = 0xbefa4fa4;
	}
*/
	virtual void hash_first(hash_ctr &ctr)
	{
		ctr.hash[0] = 0x6A09E667;
		ctr.hash[1] = 0xBB67AE85;
		ctr.hash[2] = 0x3C6EF372;
		ctr.hash[3] = 0xA54FF53A;
		ctr.hash[4] = 0x510E527F;
		ctr.hash[5] = 0x9B05688C;
		ctr.hash[6] = 0x1F83D9AB;
		ctr.hash[7] = 0x5BE0CD19;

		hash_transform = sha256_transform;
	}
};

/* Define the SHA224/256 SIGMA and sigma macros */
#define SHA256_SIGMA0(word) \
	(WORD_ROR(word,2) ^ WORD_ROR(word,13) ^ WORD_ROR(word,22))
#define SHA256_SIGMA1(word) \
	(WORD_ROR(word,6) ^ WORD_ROR(word,11) ^ WORD_ROR(word,25))
#define SHA256_sigma0(word) \
	(WORD_ROR(word,7) ^ WORD_ROR(word,18) ^ WORD_SHR(word,3))
#define SHA256_sigma1(word) \
	(WORD_ROR(word,17) ^ WORD_ROR(word,19) ^ WORD_SHR(word,10))


#define SHA256_R(a,b,c,d,e,f,g,h,t0,t1,K,M) \
	(t0 = SHA256_SIGMA0(a) + SHA_MAJ(a,b,c), \
	t1 = SHA256_SIGMA1(e) + SHA_CH(e,f,g) + h + K + M, \
	d += t1, h = t0 + t1)

/*
#define SHA256_R(A,B,C,D,E,F,G,H,t0,t1,K,M)  do { t0 = SHA256_SIGMA0(A) + SHA_MAJ(A,B,C); \
				     t1 = H + SHA256_SIGMA1(E)  \
				      + SHA_CH(E,F,G)     \
				      + K             \
				      + M;            \
				     D += t1;  H = t0 + t1; \
			       } while(0)
*/
