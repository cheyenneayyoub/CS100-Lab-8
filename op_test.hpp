#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

//old tests from lab3

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
	delete test;
}

TEST(OpTest, OpEvaluateZero){
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
	delete test;
}

TEST(OpTest, OpEvaluateNegative){
        Op* test = new Op(-1);
        EXPECT_EQ(test->evaluate(), -1);
	delete test;
}

TEST(OpTest, OpStringNonZero){
        Op* test = new Op(8);
        EXPECT_EQ(test->stringify(), "8.000000");
	delete test;
}

TEST(OpTest, OpStringZero){
        Op* test = new Op(0);
        EXPECT_EQ(test->stringify(), "0.000000");
	delete test;
}

TEST(OpTest, OpStringNegative){
        Op* test = new Op(-1);
        EXPECT_EQ(test->stringify(), "-1.000000");
	delete test;
}

// new tests

TEST(OpTest, getChild){
	Base* opn = nullptr;
	opn = new Op(2);
	EXPECT_EQ(opn->get_child(0),nullptr);
	delete opn;
}

TEST(OpTest, GetChildNULL) {
	Base* opn = nullptr;
	opn = new Op(12);
	EXPECT_EQ(opn->get_child(5), nullptr);
	delete opn;
}


TEST(OpTest, numChildren){
	Base* opn = new Op(2);
	EXPECT_EQ(opn->number_of_children(),0);
	delete opn;
}
#endif
