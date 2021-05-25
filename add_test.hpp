#include "gtest/gtest.h"
/*
#include "div.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
*/
#include "add.hpp"
#include "op.hpp"

TEST(AddTest, AddEvalPositive){
	Op *val1 = nullptr, *val2 = nullptr;
	val1 = new Op(1.0);
	val2 = new Op(2.8);
	Add *test = nullptr;
	test = new Add(val1, val2);
	EXPECT_EQ(test->evaluate(),3.8);
	delete val1; delete val2; delete test;
}

TEST(AddTest, AddEvalZero){
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(0.0);
        val2 = new Op(0.0);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->evaluate(),0.0);
	delete val1;delete  val2; delete test;
}

TEST(AddTest, AddEvalNegative){
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(-1.0);
        val2 = new Op(-2.8);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->evaluate(),-3.8);
	delete val1;delete val2; delete test;
}


TEST(AddTest, AddStringPos){
	Op *val1 = nullptr, *val2 = nullptr;
	val1 = new Op(1.0);
	val2 = new Op(2.8);
	Add *test = nullptr;
	test = new Add(val1, val2);
	EXPECT_EQ(test->stringify(), "(1.000000+2.800000)");
	delete val1;delete val2;delete test;
}


TEST(AddTest, AddStringNeg){
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(-1.0);
        val2 = new Op(-2.8);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->stringify(), "(-1.000000+-2.800000)");
	delete val1;delete val2;delete test;
}

TEST(AddTest, AddStringZero){
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(0.0);
        val2 = new Op(0.0);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->stringify(), "(0.000000+0.000000)");
	delete val1;delete val2;delete test;
}

TEST(AddTest, NumOfChildren){
	Base *val1 = nullptr, *val2 = nullptr;	
	val1 = new Op(3.0);
	val2 = new Op(2.0);
	Base* addn = nullptr;
	addn = new Add(val1,val2);
	EXPECT_EQ(addn->number_of_children(),2);
	delete val1;delete val2;delete addn;
}

TEST(AddTest, getChild){
	Base *val1 = nullptr, *val2 = nullptr, *addn = nullptr;
	val1 = new Op(3.0);
        val2 = new Op(2.0);
	addn = new Add(val1,val2);
	EXPECT_EQ(addn->get_child(0),val1);
	EXPECT_EQ(addn->get_child(1),val2);
	delete val1;delete val2;delete addn;
}
