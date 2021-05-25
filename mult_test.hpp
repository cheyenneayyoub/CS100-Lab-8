#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "add.hpp"
#include "op.hpp"

using namespace std;

	TEST(MultTest, MultEval1_1) {
		Op* num1 = new Op(1.0);
		Op* num2 = new Op(1.0);
		Mult* Mtest = new Mult(num1, num2);
		EXPECT_EQ(Mtest->evaluate(), 1.0);
}

	 TEST(MultTest, MultEvalN2_3) {
                Op* num1 = new Op(-2);
                Op* num2 = new Op(3);
                Mult* Mtest = new Mult(num1, num2);
                EXPECT_EQ(Mtest->evaluate(), -6);
}

	TEST(MultTest, MultEval3_50) {
                Op* num1 = new Op(3);
                Op* num2 = new Op(50);
                Mult* Mtest = new Mult(num1, num2);
                string res = "(3.000000*50.000000)";
		EXPECT_EQ(Mtest->stringify(), res);
}

	TEST(MultTest, MultEvalZ_10) {
                Op* num1 = new Op(0);
                Op* num2 = new Op(10);
                Mult* Mtest = new Mult(num1, num2);
                EXPECT_EQ(Mtest->evaluate(), 0);
}


        TEST(MultTest, MultEvalAdd) {
                Op* num1 = new Op(1);
                Op* num2 = new Op(2);
		Add* num3 = new Add(num1, num2);
		Op* num4 = new Op(3);
                Mult* Mtest = new Mult(num3, num4);
                EXPECT_EQ(Mtest->evaluate(), 9);
}


	TEST(MultTest, MultMany){
		Op* num1 = new Op(3.0);
		Op* num2 = new Op(5.0);
		Op* num3 = new Op(2.0);
		Op* num4 = new Op(1.0);
		Op* num5 = new Op(4.0);

		Add* addn = new Add(num3,num4);
		Pow* pw = new Pow(addn,num3);
		Mult* multn = new Mult(pw, num3);
		EXPECT_EQ(multn->evaluate(), 18.0);
}

	TEST(MultTest, MultStrMany){
                Op* num1 = new Op(3.0);
                Op* num2 = new Op(5.0);
                Op* num3 = new Op(2.0);
                Op* num4 = new Op(1.0);
                Op* num5 = new Op(4.0);

                Add* addn = new Add(num3,num4);
                Pow* pw = new Pow(addn,num3);
                Mult* multn = new Mult(pw, num3);
                EXPECT_EQ(multn->stringify(), "(((2.000000+1.000000)**2.000000)*2.000000)");
}

//new tests
TEST(MultTest, NumOfChildren){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* multn = new Mult(val1,val2);
	EXPECT_EQ(multn->number_of_children(),2);
}

TEST(MultTest, getChild){
	Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
	Base* multn = new Mult(val1,val2);
	EXPECT_EQ(multn->get_child(0),val1);
	EXPECT_EQ(multn->get_child(1),val2);
}

#endif
