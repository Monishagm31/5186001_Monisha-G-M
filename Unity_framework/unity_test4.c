#include "stdio.h"
#include "unity.h"
#include "arr.h"

void setUp(){}
void tearDown(){}

void test_avg(){
    int arr[] = {1, 2, 3, 4, 5};

    // Expected average = (1+2+3+4+5)/5 = 3.0
    TEST_ASSERT_FLOAT_WITHIN(0.0, 3.0, arr_average(arr, 5)); // exact 3.0
    TEST_ASSERT_FLOAT_WITHIN(0.21, 2.8, arr_average(arr, 5)); // within 0.21
    TEST_ASSERT_FLOAT_WITHIN(0.5, 2.5, arr_average(arr, 5));  // within 0.5
    TEST_ASSERT_FLOAT_WITHIN(0.0, 0.0, arr_average(arr, 0));  // size=0 → 0
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_avg);
    return UNITY_END();
}
