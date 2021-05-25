#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

//old tests from lab3

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero){
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegative){
        Op* test = new Op(-1);
        EXPECT_EQ(test->evaluate(), -1);
}

TEST(OpTest, OpStringNonZero){
        Op* test = new Op(8);
        EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpStringZero){
        Op* test = new Op(0);
        EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpStringNegative){
        Op* test = new Op(-1);
        EXPECT_EQ(test->stringify(), "-1.000000");
}

// new tests

TEST(OpTest, getChild){
	Base* opn = nullptr;
	opn = new Op(2);
	EXPECT_EQ(opn->get_child(0),nullptr);

}

TEST(OpTest, GetChildNULL) {
	Base* opn = nullptr;
	opn = new Op(12);
	EXPECT_EQ(opn->get_child(5), nullptr);
}


TEST(OpTest, numChildren){
	Base* opn = new Op(2);
	EXPECT_EQ(opn->number_of_children(),0);
}
#endif
