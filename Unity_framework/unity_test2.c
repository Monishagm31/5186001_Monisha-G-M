#include "leapyear.h"
#include "unity.h"

void setUp() {}
void tearDown() {}

void test_leap() {
    TEST_ASSERT_EQUAL(1, is_leapyear(2000));   // divisible by 400 → leap
    TEST_ASSERT_EQUAL(1, is_leapyear(2012));   // divisible by 4 (not 100) → leap
}

void test_nonleap() {
    TEST_ASSERT_EQUAL(0, is_leapyear(1999));   // not divisible by 4 → non-leap
    TEST_ASSERT_EQUAL(0, is_leapyear(1900));   // divisible by 100 (not 400) → non-leap
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_leap);
    RUN_TEST(test_nonleap);
    return UNITY_END();
}
