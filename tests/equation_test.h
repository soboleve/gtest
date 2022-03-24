#ifndef EQUATION_TEST_H
#define EQUATION_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C"
{
    #include "equation.h"
}

#define result(a, b, c) \
    double x1, x2; \
    int ret = solveQuadraticEquation(a, b, c, &x1, &x2);

/*Позитивные тесты*/

TEST(equationTest, ret2)
{
result(1, 1, -2);
ASSERT_EQ(ret,2);
ASSERT_TRUE(x1 == -2 && x2 == 1);
}

TEST(equationTest, ret0)
{
result(1, 1, 1);
ASSERT_EQ(ret, 0);
}

TEST(equationTest, ret1)
{
result(1, 2, 1);
ASSERT_EQ(ret, 1);
ASSERT_TRUE(x1 == -1);
}

/*Негативные тесты*/

TEST(equationTest, aEq0)
{
    result(0, 1, 2);
    ASSERT_EQ(ret, -1);
}

TEST(equationTest, bEq0)
{
result(1, 0, -1);
ASSERT_EQ(ret, 2);
ASSERT_TRUE(x1== -1 && x2 == 1);
}

TEST(equationTest, cEq0)
{
result(1, 7, 0);
ASSERT_EQ(ret, 2);
ASSERT_TRUE(x1== -7 && x2 == 0);
}

TEST(equationTest, bcEq0)
{
result(1, 0, 0);
ASSERT_EQ(ret, 1);
ASSERT_EQ(x1, 0);
}

#endif // EQUATION_TEST_H
