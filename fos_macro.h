#ifndef __FOS_MACRO_H__
#define __FOS_MACRO_H__

#include "fos_bsp.h"

#define AddrSize    sizeof(addrtype)

#ifndef NULL
#define NULL    ((void *)0)
#endif

#ifndef true
#define true    (1==1)
#define false   (!true)
#endif

#define STRER(s)     #s

#define CONCAT2(s1, s2)         s1##s2
#define CONCAT3(s1, s2, s3)     s1##s2##s3

#define MIN(a, b)       ((a) < (b) ? (a) : (b))
#define MAX(a, b)       ((a) < (b) ? (b) : (a))

#define TypeAt(type, addr)      ((type)(*((type *)(addr)))) 
#define Uint8At(addr)       TypeAt(uint8, addr)
#define Uint16At(addr)      TypeAt(uint16, addr)
#define Uint32At(addr)      TypeAt(uint32, addr)
#define Uint64At(addr)      TypeAt(uint64, addr)

#define FPOS(type, field)       ((addrtype)&(((type *)0)->field)
#define FSIZE(type, field)      (sizeof(((type *)0)->field))
#define Bytes2Word(b1, b2)      ((uint16)((((uint16)b1)<<8)+b2))
#define Words2DWord(w1, w2)     ((uint32)((((uint32)w1)<<16)+w2))
#define DWords2QDWord(w1, w2)   ((uint64)((((uint64)w1)<<32)+w2))

#define ALIGN_SIZE(x, size)     (((x)+(size-1)/size*size)

#define ARRLEN(x)               (sizeof((x))/sizeof(x[0]))

#endif
