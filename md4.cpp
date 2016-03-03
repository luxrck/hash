#include "md4.h"

void md4_transform(uint32 state[4], uint32 x[16])
{
	uint32 a = state[0];
	uint32 b = state[1];
	uint32 c = state[2];
	uint32 d = state[3];

	/* Round 1 */
	MD4_FF(a, b, c, d, x[ 0], MD4_S11); // 01
	MD4_FF(d, a, b, c, x[ 1], MD4_S12); // 02
	MD4_FF(c, d, a, b, x[ 2], MD4_S13); // 03
	MD4_FF(b, c, d, a, x[ 3], MD4_S14); // 04
	MD4_FF(a, b, c, d, x[ 4], MD4_S11); // 05
	MD4_FF(d, a, b, c, x[ 5], MD4_S12); // 06
	MD4_FF(c, d, a, b, x[ 6], MD4_S13); // 07
	MD4_FF(b, c, d, a, x[ 7], MD4_S14); // 08
	MD4_FF(a, b, c, d, x[ 8], MD4_S11); // 09
	MD4_FF(d, a, b, c, x[ 9], MD4_S12); // 10
	MD4_FF(c, d, a, b, x[10], MD4_S13); // 11
	MD4_FF(b, c, d, a, x[11], MD4_S14); // 12
	MD4_FF(a, b, c, d, x[12], MD4_S11); // 13
	MD4_FF(d, a, b, c, x[13], MD4_S12); // 14
	MD4_FF(c, d, a, b, x[14], MD4_S13); // 15
	MD4_FF(b, c, d, a, x[15], MD4_S14); // 16

	/* Round 2 */
	MD4_GG(a, b, c, d, x[ 0], MD4_S21); // 17
	MD4_GG(d, a, b, c, x[ 4], MD4_S22); // 18
	MD4_GG(c, d, a, b, x[ 8], MD4_S23); // 19
	MD4_GG(b, c, d, a, x[12], MD4_S24); // 20
	MD4_GG(a, b, c, d, x[ 1], MD4_S21); // 21
	MD4_GG(d, a, b, c, x[ 5], MD4_S22); // 22
	MD4_GG(c, d, a, b, x[ 9], MD4_S23); // 23
	MD4_GG(b, c, d, a, x[13], MD4_S24); // 24
	MD4_GG(a, b, c, d, x[ 2], MD4_S21); // 25
	MD4_GG(d, a, b, c, x[ 6], MD4_S22); // 26
	MD4_GG(c, d, a, b, x[10], MD4_S23); // 27
	MD4_GG(b, c, d, a, x[14], MD4_S24); // 28
	MD4_GG(a, b, c, d, x[ 3], MD4_S21); // 29
	MD4_GG(d, a, b, c, x[ 7], MD4_S22); // 30
	MD4_GG(c, d, a, b, x[11], MD4_S23); // 31
	MD4_GG(b, c, d, a, x[15], MD4_S24); // 32

	/* Round 3 */
	MD4_HH(a, b, c, d, x[ 0], MD4_S31); // 33
	MD4_HH(d, a, b, c, x[ 8], MD4_S32); // 34
	MD4_HH(c, d, a, b, x[ 4], MD4_S33); // 35
	MD4_HH(b, c, d, a, x[12], MD4_S34); // 36
	MD4_HH(a, b, c, d, x[ 2], MD4_S31); // 37
	MD4_HH(d, a, b, c, x[10], MD4_S32); // 38
	MD4_HH(c, d, a, b, x[ 6], MD4_S33); // 39
	MD4_HH(b, c, d, a, x[14], MD4_S34); // 40
	MD4_HH(a, b, c, d, x[ 1], MD4_S31); // 41
	MD4_HH(d, a, b, c, x[ 9], MD4_S32); // 42
	MD4_HH(c, d, a, b, x[ 5], MD4_S33); // 43
	MD4_HH(b, c, d, a, x[13], MD4_S34); // 44
	MD4_HH(a, b, c, d, x[ 3], MD4_S31); // 45
	MD4_HH(d, a, b, c, x[11], MD4_S32); // 46
	MD4_HH(c, d, a, b, x[ 7], MD4_S33); // 47
	MD4_HH(b, c, d, a, x[15], MD4_S34); // 48

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
}
