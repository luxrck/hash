#include "md5.h"

void md5_transform(uint32 state[4], uint32 x[16])
{
	uint32 a = state[0];
	uint32 b = state[1];
	uint32 c = state[2];
	uint32 d = state[3];

	/* Round 1 */
	MD5_FF (a, b, c, d, x[ 0], MD5_S11, 0xd76aa478); /* 1 */
	MD5_FF (d, a, b, c, x[ 1], MD5_S12, 0xe8c7b756); /* 2 */
	MD5_FF (c, d, a, b, x[ 2], MD5_S13, 0x242070db); /* 3 */
	MD5_FF (b, c, d, a, x[ 3], MD5_S14, 0xc1bdceee); /* 4 */
	MD5_FF (a, b, c, d, x[ 4], MD5_S11, 0xf57c0faf); /* 5 */
	MD5_FF (d, a, b, c, x[ 5], MD5_S12, 0x4787c62a); /* 6 */
	MD5_FF (c, d, a, b, x[ 6], MD5_S13, 0xa8304613); /* 7 */
	MD5_FF (b, c, d, a, x[ 7], MD5_S14, 0xfd469501); /* 8 */
	MD5_FF (a, b, c, d, x[ 8], MD5_S11, 0x698098d8); /* 9 */
	MD5_FF (d, a, b, c, x[ 9], MD5_S12, 0x8b44f7af); /* 10 */
	MD5_FF (c, d, a, b, x[10], MD5_S13, 0xffff5bb1); /* 11 */
	MD5_FF (b, c, d, a, x[11], MD5_S14, 0x895cd7be); /* 12 */
	MD5_FF (a, b, c, d, x[12], MD5_S11, 0x6b901122); /* 13 */
	MD5_FF (d, a, b, c, x[13], MD5_S12, 0xfd987193); /* 14 */
	MD5_FF (c, d, a, b, x[14], MD5_S13, 0xa679438e); /* 15 */
	MD5_FF (b, c, d, a, x[15], MD5_S14, 0x49b40821); /* 16 */

	/* Round 2 */
	MD5_GG (a, b, c, d, x[ 1], MD5_S21, 0xf61e2562); /* 17 */
	MD5_GG (d, a, b, c, x[ 6], MD5_S22, 0xc040b340); /* 18 */
	MD5_GG (c, d, a, b, x[11], MD5_S23, 0x265e5a51); /* 19 */
	MD5_GG (b, c, d, a, x[ 0], MD5_S24, 0xe9b6c7aa); /* 20 */
	MD5_GG (a, b, c, d, x[ 5], MD5_S21, 0xd62f105d); /* 21 */
	MD5_GG (d, a, b, c, x[10], MD5_S22,  0x2441453); /* 22 */
	MD5_GG (c, d, a, b, x[15], MD5_S23, 0xd8a1e681); /* 23 */
	MD5_GG (b, c, d, a, x[ 4], MD5_S24, 0xe7d3fbc8); /* 24 */
	MD5_GG (a, b, c, d, x[ 9], MD5_S21, 0x21e1cde6); /* 25 */
	MD5_GG (d, a, b, c, x[14], MD5_S22, 0xc33707d6); /* 26 */
	MD5_GG (c, d, a, b, x[ 3], MD5_S23, 0xf4d50d87); /* 27 */
	MD5_GG (b, c, d, a, x[ 8], MD5_S24, 0x455a14ed); /* 28 */
	MD5_GG (a, b, c, d, x[13], MD5_S21, 0xa9e3e905); /* 29 */
	MD5_GG (d, a, b, c, x[ 2], MD5_S22, 0xfcefa3f8); /* 30 */
	MD5_GG (c, d, a, b, x[ 7], MD5_S23, 0x676f02d9); /* 31 */
	MD5_GG (b, c, d, a, x[12], MD5_S24, 0x8d2a4c8a); /* 32 */

	/* Round 3 */
	MD5_HH (a, b, c, d, x[ 5], MD5_S31, 0xfffa3942); /* 33 */
	MD5_HH (d, a, b, c, x[ 8], MD5_S32, 0x8771f681); /* 34 */
	MD5_HH (c, d, a, b, x[11], MD5_S33, 0x6d9d6122); /* 35 */
	MD5_HH (b, c, d, a, x[14], MD5_S34, 0xfde5380c); /* 36 */
	MD5_HH (a, b, c, d, x[ 1], MD5_S31, 0xa4beea44); /* 37 */
	MD5_HH (d, a, b, c, x[ 4], MD5_S32, 0x4bdecfa9); /* 38 */
	MD5_HH (c, d, a, b, x[ 7], MD5_S33, 0xf6bb4b60); /* 39 */
	MD5_HH (b, c, d, a, x[10], MD5_S34, 0xbebfbc70); /* 40 */
	MD5_HH (a, b, c, d, x[13], MD5_S31, 0x289b7ec6); /* 41 */
	MD5_HH (d, a, b, c, x[ 0], MD5_S32, 0xeaa127fa); /* 42 */
	MD5_HH (c, d, a, b, x[ 3], MD5_S33, 0xd4ef3085); /* 43 */
	MD5_HH (b, c, d, a, x[ 6], MD5_S34,  0x4881d05); /* 44 */
	MD5_HH (a, b, c, d, x[ 9], MD5_S31, 0xd9d4d039); /* 45 */
	MD5_HH (d, a, b, c, x[12], MD5_S32, 0xe6db99e5); /* 46 */
	MD5_HH (c, d, a, b, x[15], MD5_S33, 0x1fa27cf8); /* 47 */
	MD5_HH (b, c, d, a, x[ 2], MD5_S34, 0xc4ac5665); /* 48 */

	/* Round 4 */
	MD5_II (a, b, c, d, x[ 0], MD5_S41, 0xf4292244); /* 49 */
	MD5_II (d, a, b, c, x[ 7], MD5_S42, 0x432aff97); /* 50 */
	MD5_II (c, d, a, b, x[14], MD5_S43, 0xab9423a7); /* 51 */
	MD5_II (b, c, d, a, x[ 5], MD5_S44, 0xfc93a039); /* 52 */
	MD5_II (a, b, c, d, x[12], MD5_S41, 0x655b59c3); /* 53 */
	MD5_II (d, a, b, c, x[ 3], MD5_S42, 0x8f0ccc92); /* 54 */
	MD5_II (c, d, a, b, x[10], MD5_S43, 0xffeff47d); /* 55 */
	MD5_II (b, c, d, a, x[ 1], MD5_S44, 0x85845dd1); /* 56 */
	MD5_II (a, b, c, d, x[ 8], MD5_S41, 0x6fa87e4f); /* 57 */
	MD5_II (d, a, b, c, x[15], MD5_S42, 0xfe2ce6e0); /* 58 */
	MD5_II (c, d, a, b, x[ 6], MD5_S43, 0xa3014314); /* 59 */
	MD5_II (b, c, d, a, x[13], MD5_S44, 0x4e0811a1); /* 60 */
	MD5_II (a, b, c, d, x[ 4], MD5_S41, 0xf7537e82); /* 61 */
	MD5_II (d, a, b, c, x[11], MD5_S42, 0xbd3af235); /* 62 */
	MD5_II (c, d, a, b, x[ 2], MD5_S43, 0x2ad7d2bb); /* 63 */
	MD5_II (b, c, d, a, x[ 9], MD5_S44, 0xeb86d391); /* 64 */

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
}
