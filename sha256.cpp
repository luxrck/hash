#include "sha256.h"

/* Constants defined in FIPS-180-2, section 4.2.2 */
static const uint32 K[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
	0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
	0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
	0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
	0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
	0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
	0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
	0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_transform(uint32 state[8], uint32 x[16])
{
	uint32 a,b,c,d,e,f,g,h;
	uint32 t1,t2;
	uint32 buf[64];
	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	e = state[4];
	f = state[5];
	g = state[6];
	h = state[7];

	for (int i = 0; i < 16; i++)
		buf[i] = WORD_CHANGE_ENDIAN(x[i]);

	for (int i = 16; i < 64; i++)
		buf[i] = buf[i-7] + buf[i-16] + SHA256_sigma1(buf[i-2]) + SHA256_sigma0(buf[i-15]);

	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[ 0], buf[ 0] );
  	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[ 1], buf[ 1] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[ 2], buf[ 2] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[ 3], buf[ 3] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[ 4], buf[ 4] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[ 5], buf[ 5] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[ 6], buf[ 6] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[ 7], buf[ 7] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[ 8], buf[ 8] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[ 9], buf[ 9] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[10], buf[10] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[11], buf[11] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[12], buf[12] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[13], buf[13] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[14], buf[14] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[15], buf[15] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[16], buf[16] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[17], buf[17] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[18], buf[18] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[19], buf[19] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[20], buf[20] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[21], buf[21] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[22], buf[22] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[23], buf[23] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[24], buf[24] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[25], buf[25] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[26], buf[26] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[27], buf[27] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[28], buf[28] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[29], buf[29] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[30], buf[30] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[31], buf[31] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[32], buf[32] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[33], buf[33] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[34], buf[34] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[35], buf[35] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[36], buf[36] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[37], buf[37] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[38], buf[38] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[39], buf[39] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[40], buf[40] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[41], buf[41] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[42], buf[42] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[43], buf[43] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[44], buf[44] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[45], buf[45] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[46], buf[46] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[47], buf[47] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[48], buf[48] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[49], buf[49] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[50], buf[50] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[51], buf[51] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[52], buf[52] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[53], buf[53] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[54], buf[54] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[55], buf[55] );
	SHA256_R( a, b, c, d, e, f, g, h, t1, t2, K[56], buf[56] );
	SHA256_R( h, a, b, c, d, e, f, g, t1, t2, K[57], buf[57] );
	SHA256_R( g, h, a, b, c, d, e, f, t1, t2, K[58], buf[58] );
	SHA256_R( f, g, h, a, b, c, d, e, t1, t2, K[59], buf[59] );
	SHA256_R( e, f, g, h, a, b, c, d, t1, t2, K[60], buf[60] );
	SHA256_R( d, e, f, g, h, a, b, c, t1, t2, K[61], buf[61] );
	SHA256_R( c, d, e, f, g, h, a, b, t1, t2, K[62], buf[62] );
	SHA256_R( b, c, d, e, f, g, h, a, t1, t2, K[63], buf[63] );

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	state[5] += f;
	state[6] += g;
	state[7] += h;
}
