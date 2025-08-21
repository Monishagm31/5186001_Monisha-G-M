#include "stdio.h"
#include "demo.h"
#include "unity.h"

void setUp() {
    printf("Before going into test case\n");
    printf("------------------------------\n");
}
void tearDown() {
    printf("After completing the test case\n");
    printf("------------------------------\n");
}

void test_sum() {
    TEST_ASSERT_EQUAL(5, sum(2, 3));
    TEST_ASSERT_EQUAL(6, sum(3, 3));
}
void test_square() {
    TEST_ASSERT_EQUAL(9, square(3));
    TEST_ASSERT_EQUAL(4, square(2));
}

int main() {
    int a = 10, b = 15, c = 0;
    c = sum(a, b);
    printf("The sum of two numbers is %d\n", c);
    c = square(a);
    printf("The square of the number is %d\n", c);

    UNITY_BEGIN();
    RUN_TEST(test_sum);
    RUN_TEST(test_square);
    return UNITY_END();
}
