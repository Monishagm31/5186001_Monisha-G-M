#include "stdio.h"
#include "swap.h"
#include "unity.h"

void setUp() {}
void tearDown() {}

void test_swap() {
    int a = 10, b = 20;
    num_swap(&a, &b);
    TEST_ASSERT_EQUAL_INT(10, b);
    TEST_ASSERT_EQUAL_INT(20, a);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_swap);
    return UNITY_END();
}
