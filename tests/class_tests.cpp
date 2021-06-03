//
// Created by Gabriel on 06/05/2021.
//

#include "test_utilities.h"
#include "../CarType.h"
#include "../CarSales.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

#define NUMBER_TESTS 2

bool testCarType(){
    bool result = true;
    CarType type1 = CarType();
    CarType type2 = CarType(3, 8);
    CarType type3(type2);

    ASSERT_TEST(type1.getSales() == -1, returnLabel);
    ASSERT_TEST(type1.getTypeId() == -1, returnLabel);

    ASSERT_TEST(type2.getSales() == 8, returnLabel);
    ASSERT_TEST(type2.getTypeId() == 3, returnLabel);

    ASSERT_TEST(type3.getSales() == 8, returnLabel);
    ASSERT_TEST(type3.getTypeId() == 3, returnLabel);

    ASSERT_TEST(type2 == type3, returnLabel);
    ASSERT_TEST(!(type2 == type1), returnLabel);

    ASSERT_TEST(!(type2 < type1), returnLabel);
    ASSERT_TEST(type1 < type2, returnLabel);
    ASSERT_TEST(!(type1 > type2), returnLabel);
    ASSERT_TEST(type2 > type1, returnLabel);

    type1 = type2;

    ASSERT_TEST(type1.getSales() == 8, returnLabel);
    ASSERT_TEST(type1.getTypeId() == 3, returnLabel);
    returnLabel:
    return result;

}

bool testCarSales(){
    bool result = true;
    CarSales type1 = CarSales();
    CarSales type2 = CarSales(3, 8);
    CarSales type3(type2);

    ASSERT_TEST(type1.getSales() == -1, returnLabel);
    ASSERT_TEST(type1.getTypeId() == -1, returnLabel);

    ASSERT_TEST(type2.getSales() == 8, returnLabel);
    ASSERT_TEST(type2.getTypeId() == 3, returnLabel);

    ASSERT_TEST(type3.getSales() == 8, returnLabel);
    ASSERT_TEST(type3.getTypeId() == 3, returnLabel);

    ASSERT_TEST(type2 == type3, returnLabel);
    ASSERT_TEST(!(type2 == type1), returnLabel);

    ASSERT_TEST(!(type2 < type1), returnLabel);
    ASSERT_TEST(type1 < type2, returnLabel);
    ASSERT_TEST(!(type1 > type2), returnLabel);
    ASSERT_TEST(type2 > type1, returnLabel);

    type1 = type2;

    ASSERT_TEST(type1.getSales() == 8, returnLabel);
    ASSERT_TEST(type1.getTypeId() == 3, returnLabel);

    returnLabel:
    return result;
}
/* bool test(){
    bool result = true;

returnLabel:
    return result;
} */

bool (*tests[]) (void) = {
        testCarType,
        testCarSales
};

const char* testNames[] = {
        "testCarType",
        "testCarSales"

};

int main(int argc, char *argv[]) {
    if (argc == 1) {
        for (int test_idx = 0; test_idx < NUMBER_TESTS; test_idx++) {
            RUN_TEST(tests[test_idx], testNames[test_idx]);
        }
        return 0;
    }
    if (argc != 2) {
        fprintf(stdout, "Usage: priority_queue_tests <test index>\n");
        return 0;
    }

    int test_idx = strtol(argv[1], NULL, 10);
    if (test_idx < 1 || test_idx > NUMBER_TESTS) {
        fprintf(stderr, "Invalid test index %d\n", test_idx);
        return 0;
    }

    RUN_TEST(tests[test_idx - 1], testNames[test_idx - 1]);
    return 0;
}
