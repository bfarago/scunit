/* scunit.h
 Small computer Unit Tester enviroment
 Writed by Barna Farago 2009.03.

 Limitations and rules:
 -test functions declaration and deffinitions must have the same name!
  ie: myinterface.c, myinterface.h
 -

*/
#ifndef _SCUNIT_H_
#define _SCUNIT_H_

#include "scunit_config.h"

typedef struct {
    unsigned int line;
    char* file;
    char* fixture;
    char* function;
    unsigned int required;
    unsigned int result;
    unsigned int iter;
    unsigned int countRun, countFailed;
} tScResult;


#define UNITTEST_REPORT_FNFAIL(r)\
printf("%s(%i) : error in test_%s_%s() req=%04x, result=%04x (i:%i)\n",\
 ScResult.file, ScResult.line, ScResult.fixture, ScResult.function, ScResult.required, ScResult.result, ScResult.iter );

#define UNITTEST_CALL(TestFixtureName, TestName) \
 if (test_##TestFixtureName##_##TestName(&ScResult) ) UNITTEST_REPORT_FNFAIL(ScResult)

#define UNITTEST_INIT() tScResult ScResult; ScResult.countFailed=ScResult.countRun=0

#define UNITTEST_REPORT() \
 if (ScResult.countFailed){         \
    printf("Test failed. (%i / %i)\n", ScResult.countFailed, ScResult.countRun );\
 }else{  \
    printf("All test OK. (%i)\n", ScResult.countRun ); \
 }

#define UNITTEST_RESULT  (ScResult.countFailed)

#define TEST_FUNCTION(TestFixtureName, TestName) \
 int test_##TestFixtureName##_##TestName(tScResult* pScResult)

#define TEST_BEGIN(TestFixtureName, TestName)                           \
 int test_##TestFixtureName##_##TestName(tScResult* pScResult){         \
 pScResult->file=__FILE__; pScResult->countRun++; pScResult->iter=0;    \
 pScResult->fixture= #TestFixtureName; pScResult->function= #TestName;  \

#define TEST_END()  \
 }return 0;          \


#define TEST_BAD(req, res) \
 {pScResult->line=__LINE__; pScResult->required=req; pScResult->result=res; pScResult->countFailed++; return 1;}

#define CHECK(condition) if (!(condition)) TEST_BAD(0,0)

#define CHECK_EQUAL(req,res) if ((req)!=(res)) TEST_BAD(req, res)
#define UNITTEST_ITERATIVE(aniter) pScResult->iter=aniter
#endif

