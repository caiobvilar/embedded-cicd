#include "CppUTest/TestHarness.h"

extern "C"
{
	/*
	 * Add your c-only include files here
	 */   
}

TEST_GROUP(sample)
{
    void setup()
    {

    }

    void teardown()
    {
    }
};

TEST(sample, fail)
{
//    FAIL("The harness is working! \r\n Now edit sample.cpp and make the test pass!");
    CHECK_FALSE(false);    
}
