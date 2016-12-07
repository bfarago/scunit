// Example unit

#include "scunit.h"     //UnitTest

inline char utraceBitsNeed(unsigned long dif){
       if (!dif) return 0;
       if (!(dif & 0xFFFFFFFE)) return  1;
       if (!(dif & 0xFFFFFFF0)) return  4;
       if (!(dif & 0xFFFFFF00)) return  8;
       if (!(dif & 0xFFFF0000)) return 16;
       if (!(dif & 0xFF000000)) return 24;
       return 32;
}
inline char utraceBitsCode(unsigned long dif){
    //most csak 8bitenkent...
       if (!dif) return 0;
       if (!(dif & 0xFFFFFF00)) return 1;
       if (!(dif & 0xFFFF0000)) return 2;
       if (!(dif & 0xFF000000)) return 3;
       return 4;
}


//----------------------------------------------------------
#ifdef UNITTESTFIXTURE_ENABLE_Utrace
TEST_BEGIN(Utrace, utraceBitsNeed){
    CHECK_EQUAL(0, utraceBitsNeed(0));
    CHECK_EQUAL(1, utraceBitsNeed(1));
    CHECK_EQUAL(4, utraceBitsNeed(2));
    CHECK_EQUAL(4, utraceBitsNeed(3));
	//etc
    TEST_END();
}
TEST_BEGIN(Utrace, utraceBitsCode){
    CHECK_EQUAL(0, utraceBitsCode(0));

    CHECK_EQUAL(1, utraceBitsCode(1));
    CHECK_EQUAL(1, utraceBitsCode(2));
    CHECK_EQUAL(1, utraceBitsCode(3));

    CHECK_EQUAL(1, utraceBitsCode((1<<8)-1));
    CHECK_EQUAL(2, utraceBitsCode((1<<8)));
    CHECK_EQUAL(2, utraceBitsCode((1<<8)+1));

    CHECK_EQUAL(2, utraceBitsCode((1<<16)-1));
    CHECK_EQUAL(3, utraceBitsCode((1<<16)));
    CHECK_EQUAL(3, utraceBitsCode((1<<16)+1));

    CHECK_EQUAL(3, utraceBitsCode((1<<24)-1));
    CHECK_EQUAL(4, utraceBitsCode((1<<24)));
    CHECK_EQUAL(4, utraceBitsCode((1<<24)+1));
    TEST_END();
}
#endif
