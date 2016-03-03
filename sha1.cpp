#include "sha1.h"

void sha1_transform(uint32 state[5], uint32 x[16])
{
	uint32 a = state[0];
	uint32 b = state[1];
	uint32 c = state[2];
	uint32 d = state[3];
	uint32 e = state[4];

	uint32 buf[80] = {0};

	for(int i=0; i<16; i++)
		buf[i] = WORD_CHANGE_ENDIAN(x[i]);

	SHA1_R( a, b, c, d, e, SHA1_F1, SHA1_K1, buf[ 0] );
	SHA1_R( e, a, b, c, d, SHA1_F1, SHA1_K1, buf[ 1] );
	SHA1_R( d, e, a, b, c, SHA1_F1, SHA1_K1, buf[ 2] );
	SHA1_R( c, d, e, a, b, SHA1_F1, SHA1_K1, buf[ 3] );
	SHA1_R( b, c, d, e, a, SHA1_F1, SHA1_K1, buf[ 4] );
	SHA1_R( a, b, c, d, e, SHA1_F1, SHA1_K1, buf[ 5] );
	SHA1_R( e, a, b, c, d, SHA1_F1, SHA1_K1, buf[ 6] );
	SHA1_R( d, e, a, b, c, SHA1_F1, SHA1_K1, buf[ 7] );
	SHA1_R( c, d, e, a, b, SHA1_F1, SHA1_K1, buf[ 8] );
	SHA1_R( b, c, d, e, a, SHA1_F1, SHA1_K1, buf[ 9] );
	SHA1_R( a, b, c, d, e, SHA1_F1, SHA1_K1, buf[10] );
	SHA1_R( e, a, b, c, d, SHA1_F1, SHA1_K1, buf[11] );
	SHA1_R( d, e, a, b, c, SHA1_F1, SHA1_K1, buf[12] );
	SHA1_R( c, d, e, a, b, SHA1_F1, SHA1_K1, buf[13] );
	SHA1_R( b, c, d, e, a, SHA1_F1, SHA1_K1, buf[14] );
	SHA1_R( a, b, c, d, e, SHA1_F1, SHA1_K1, buf[15] );
	SHA1_R( e, a, b, c, d, SHA1_F1, SHA1_K1, SHA1_M(buf, 16) );
	SHA1_R( d, e, a, b, c, SHA1_F1, SHA1_K1, SHA1_M(buf, 17) );
	SHA1_R( c, d, e, a, b, SHA1_F1, SHA1_K1, SHA1_M(buf, 18) );
	SHA1_R( b, c, d, e, a, SHA1_F1, SHA1_K1, SHA1_M(buf, 19) );
	SHA1_R( a, b, c, d, e, SHA1_F2, SHA1_K2, SHA1_M(buf, 20) );
	SHA1_R( e, a, b, c, d, SHA1_F2, SHA1_K2, SHA1_M(buf, 21) );
	SHA1_R( d, e, a, b, c, SHA1_F2, SHA1_K2, SHA1_M(buf, 22) );
	SHA1_R( c, d, e, a, b, SHA1_F2, SHA1_K2, SHA1_M(buf, 23) );
	SHA1_R( b, c, d, e, a, SHA1_F2, SHA1_K2, SHA1_M(buf, 24) );
	SHA1_R( a, b, c, d, e, SHA1_F2, SHA1_K2, SHA1_M(buf, 25) );
	SHA1_R( e, a, b, c, d, SHA1_F2, SHA1_K2, SHA1_M(buf, 26) );
	SHA1_R( d, e, a, b, c, SHA1_F2, SHA1_K2, SHA1_M(buf, 27) );
	SHA1_R( c, d, e, a, b, SHA1_F2, SHA1_K2, SHA1_M(buf, 28) );
	SHA1_R( b, c, d, e, a, SHA1_F2, SHA1_K2, SHA1_M(buf, 29) );
	SHA1_R( a, b, c, d, e, SHA1_F2, SHA1_K2, SHA1_M(buf, 30) );
	SHA1_R( e, a, b, c, d, SHA1_F2, SHA1_K2, SHA1_M(buf, 31) );
	SHA1_R( d, e, a, b, c, SHA1_F2, SHA1_K2, SHA1_M(buf, 32) );
	SHA1_R( c, d, e, a, b, SHA1_F2, SHA1_K2, SHA1_M(buf, 33) );
	SHA1_R( b, c, d, e, a, SHA1_F2, SHA1_K2, SHA1_M(buf, 34) );
	SHA1_R( a, b, c, d, e, SHA1_F2, SHA1_K2, SHA1_M(buf, 35) );
	SHA1_R( e, a, b, c, d, SHA1_F2, SHA1_K2, SHA1_M(buf, 36) );
	SHA1_R( d, e, a, b, c, SHA1_F2, SHA1_K2, SHA1_M(buf, 37) );
	SHA1_R( c, d, e, a, b, SHA1_F2, SHA1_K2, SHA1_M(buf, 38) );
	SHA1_R( b, c, d, e, a, SHA1_F2, SHA1_K2, SHA1_M(buf, 39) );
	SHA1_R( a, b, c, d, e, SHA1_F3, SHA1_K3, SHA1_M(buf, 40) );
	SHA1_R( e, a, b, c, d, SHA1_F3, SHA1_K3, SHA1_M(buf, 41) );
	SHA1_R( d, e, a, b, c, SHA1_F3, SHA1_K3, SHA1_M(buf, 42) );
	SHA1_R( c, d, e, a, b, SHA1_F3, SHA1_K3, SHA1_M(buf, 43) );
	SHA1_R( b, c, d, e, a, SHA1_F3, SHA1_K3, SHA1_M(buf, 44) );
	SHA1_R( a, b, c, d, e, SHA1_F3, SHA1_K3, SHA1_M(buf, 45) );
	SHA1_R( e, a, b, c, d, SHA1_F3, SHA1_K3, SHA1_M(buf, 46) );
	SHA1_R( d, e, a, b, c, SHA1_F3, SHA1_K3, SHA1_M(buf, 47) );
	SHA1_R( c, d, e, a, b, SHA1_F3, SHA1_K3, SHA1_M(buf, 48) );
	SHA1_R( b, c, d, e, a, SHA1_F3, SHA1_K3, SHA1_M(buf, 49) );
	SHA1_R( a, b, c, d, e, SHA1_F3, SHA1_K3, SHA1_M(buf, 50) );
	SHA1_R( e, a, b, c, d, SHA1_F3, SHA1_K3, SHA1_M(buf, 51) );
	SHA1_R( d, e, a, b, c, SHA1_F3, SHA1_K3, SHA1_M(buf, 52) );
	SHA1_R( c, d, e, a, b, SHA1_F3, SHA1_K3, SHA1_M(buf, 53) );
	SHA1_R( b, c, d, e, a, SHA1_F3, SHA1_K3, SHA1_M(buf, 54) );
	SHA1_R( a, b, c, d, e, SHA1_F3, SHA1_K3, SHA1_M(buf, 55) );
	SHA1_R( e, a, b, c, d, SHA1_F3, SHA1_K3, SHA1_M(buf, 56) );
	SHA1_R( d, e, a, b, c, SHA1_F3, SHA1_K3, SHA1_M(buf, 57) );
	SHA1_R( c, d, e, a, b, SHA1_F3, SHA1_K3, SHA1_M(buf, 58) );
	SHA1_R( b, c, d, e, a, SHA1_F3, SHA1_K3, SHA1_M(buf, 59) );
	SHA1_R( a, b, c, d, e, SHA1_F4, SHA1_K4, SHA1_M(buf, 60) );
	SHA1_R( e, a, b, c, d, SHA1_F4, SHA1_K4, SHA1_M(buf, 61) );
	SHA1_R( d, e, a, b, c, SHA1_F4, SHA1_K4, SHA1_M(buf, 62) );
	SHA1_R( c, d, e, a, b, SHA1_F4, SHA1_K4, SHA1_M(buf, 63) );
	SHA1_R( b, c, d, e, a, SHA1_F4, SHA1_K4, SHA1_M(buf, 64) );
	SHA1_R( a, b, c, d, e, SHA1_F4, SHA1_K4, SHA1_M(buf, 65) );
	SHA1_R( e, a, b, c, d, SHA1_F4, SHA1_K4, SHA1_M(buf, 66) );
	SHA1_R( d, e, a, b, c, SHA1_F4, SHA1_K4, SHA1_M(buf, 67) );
	SHA1_R( c, d, e, a, b, SHA1_F4, SHA1_K4, SHA1_M(buf, 68) );
	SHA1_R( b, c, d, e, a, SHA1_F4, SHA1_K4, SHA1_M(buf, 69) );
	SHA1_R( a, b, c, d, e, SHA1_F4, SHA1_K4, SHA1_M(buf, 70) );
	SHA1_R( e, a, b, c, d, SHA1_F4, SHA1_K4, SHA1_M(buf, 71) );
	SHA1_R( d, e, a, b, c, SHA1_F4, SHA1_K4, SHA1_M(buf, 72) );
	SHA1_R( c, d, e, a, b, SHA1_F4, SHA1_K4, SHA1_M(buf, 73) );
	SHA1_R( b, c, d, e, a, SHA1_F4, SHA1_K4, SHA1_M(buf, 74) );
	SHA1_R( a, b, c, d, e, SHA1_F4, SHA1_K4, SHA1_M(buf, 75) );
	SHA1_R( e, a, b, c, d, SHA1_F4, SHA1_K4, SHA1_M(buf, 76) );
	SHA1_R( d, e, a, b, c, SHA1_F4, SHA1_K4, SHA1_M(buf, 77) );
	SHA1_R( c, d, e, a, b, SHA1_F4, SHA1_K4, SHA1_M(buf, 78) );
	SHA1_R( b, c, d, e, a, SHA1_F4, SHA1_K4, SHA1_M(buf, 79) );

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
}
