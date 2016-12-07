#ifndef typeDefsH
#define typeDefsH


#ifndef _SHORT_TYPE_NAMES
#define _SHORT_TYPE_NAMES
typedef long int           INT32;
typedef unsigned long int  UINT32;
typedef int                INT16;
typedef unsigned int       UINT16;
typedef char               INT8;
typedef unsigned char      UINT8;
#endif // _SHORT_TYPE_NAMES

#ifndef _BOOL_IN_C
#define _BOOL_IN_C
#define BOOL    unsigned char
#define FALSE   0
#define TRUE    1
#endif //_BOOL_IN_C

#define NULL    0

#define ABS(x)                  ( (x)>=0  ? (x):-(x) )
#define MIN(a,b)                ( (a)<(b) ? a:b )
#define MAX(a,b)                ( (a)>(b) ? a:b )
#define TEST_RANGE(x,min,max)   ( ((x>=min)&&(x<=max)) ? TRUE:FALSE )
#define TEST_MAXDIF(x,base,dif) ( TEST_RANGE(x,(base-dif),(base+dif)) )

#endif // typeDefsH
