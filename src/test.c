#include <stdio.h>
#include <CUnit/CUnit.h>

void testAddition() {
    CU_ASSERT_EQUAL(2 + 2, 4);
}

void testSubtraction() {
    CU_ASSERT_EQUAL(5 - 3, 2);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Math Tests", NULL, NULL);
    CU_add_test(suite, "testAddition", testAddition);
    CU_add_test(suite, "testSubtraction", testSubtraction);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();

    return CU_get_error();
}
