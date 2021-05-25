#ifndef _DIV_TEST_HPP
#define _DIV_TEST_HPP

#include "gtest/gtest.h"
#include "div.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "op.hpp"

using namespace std;

	TEST(DivTest, DivEval1_1) {
		Op* num1 = new Op(1);
		Op* num2 = new Op(1);
		Div* Dtest = new Div(num1, num2);
		EXPECT_EQ(Dtest->evaluate(), 1);
		delete num1;delete num2;delete Dtest;
}

	 TEST(DivTest, DivEvalN18_3) {
                Op* num1 = new Op(-18);
                Op* num2 = new Op(3);
                Div* Dtest = new Div(num1, num2);
                EXPECT_EQ(Dtest->evaluate(),-6 );
		delete num1;delete num2;delete Dtest;
}

	TEST(DivTest, DivEval30_3) {
                Op* num1 = new Op(30);
                Op* num2 = new Op(3);
                Div* Dtest = new Div(num1, num2);
                EXPECT_EQ(Dtest->stringify(), "(30.000000/3.000000)");
		delete num1;delete num2;delete Dtest;
}

	TEST(DivTest, DivEval100_10) {
                Op* num1 = new Op(100);
                Op* num2 = new Op(10);
                Div* Dtest = new Div(num1, num2);
                EXPECT_EQ(Dtest->evaluate(), 10);
		delete num1;delete num2;delete Dtest;
}

	TEST(DivTest, DivEvalSub) {
                Op* num1 = new Op(100);
                Op* num2 = new Op(10);
		Sub* num3 = new Sub(num1, num2); //90
		Op* num4 = new Op(9);
                Div* Dtest = new Div(num3, num4);
                EXPECT_EQ(Dtest->evaluate(), 10);
		delete num1;delete num2;delete Dtest;delete num3;delete num4;
}

	TEST(DivTest, DivByZero){
		Op* num1 = new Op(10.0);
		Op* num2 = new Op(0.0);
		EXPECT_THROW(Div(num1,num2), invalid_argument); 
		delete num1;delete num2;
}

	TEST(DivTest, DivMany){
		Op* num1 = new Op(3.0);
		Op* num2 = new Op(5.0);
		Op* num3 = new Op(2.0);
		Op* num4 = new Op(1.0);
		Op* num5 = new Op(4.0);
		Mult* mul = new Mult(num1, num2);
		Add* addn = new Add(mul, num4);
		Div* divn = new Div(addn, num5);
		EXPECT_EQ(divn->evaluate(), 4.0);
		delete num1;delete num2;delete num3;delete num4;delete num5;delete mul;delete addn;delete divn;
}

	TEST(DivTest, DivStringMany){
		Base* num1 = new Op(3);
                Base* num2 = new Op(5);
                Base* num3 = new Op(2);
                Base* num4 = new Op(1);
                Base* num5 = new Op(4);
                Base* subn = new Sub(num2, num1);
		Base* pw = new Pow(subn,num1);
                Base* divn = new Div(pw, num5);
                EXPECT_EQ(divn->stringify(), "(((5.000000-3.000000)**3.000000)/4.000000)");		
		delete num1;delete num2;delete num3;delete num4;delete num5;delete subn;delete pw;delete divn;
}

TEST(DivTest, stringify_THREE){
	Base *num1 = new Op(7), *num2 = new Op(5), *num3 = new Op(1);
	Base *left = new Mult(num1, num2), *test = new Div(left, num3);
	EXPECT_EQ("((7.000000*5.000000)/1.000000)", test->stringify());
	delete num1;delete num2;delete num3;delete left;delete test;
}

TEST(DivTest, numchildrentest) {
	Base* val1 = new Op(2.0);
	Base* val2 = new Op(1.0);
	Base* divn = new Div(val1,val2);
	EXPECT_EQ(divn->number_of_children(),2);
	delete val1;delete val2;delete divn;
}

TEST(DivTest, getChild){
	Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
	Base* divn = new Div(val1,val2);
	EXPECT_EQ(divn->get_child(0),val1);
	EXPECT_EQ(divn->get_child(1),val2);
	delete val1;delete val2;delete divn;
}
#endif 
