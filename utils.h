#pragma once

#include <memory.h>

/* word size: 4 bytes */
#define WORD_SHR(data,n) ((data) >> (n))
#define WORD_ROR(data,n) (((data) >> (n)) | ((uint32)(data) << (32-(n))))
#define WORD_ROL(data,n) (((data) << (n)) | ((uint32)(data) >> (32-(n))))

#define WORD_CHANGE_ENDIAN(n) (((n) << 24) | (((n) & 0xff00) << 8) | (((n) >> 8) & 0xff00) | ((n) >> 24))
