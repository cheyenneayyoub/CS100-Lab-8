#include "gtest/gtest.h"
/*
#include "div.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
*/
#include "add.hpp"


TEST(AddTest, AddEvalPositive){
	Op* val1 = new Op(1.0);
	Op* val2 = new Op(2.8);
	Add* test = new Add(val1, val2);
	EXPECT_EQ(test->evaluate(),3.8);
}

TEST(AddTest, AddEvalZero){
        Op* val1 = new Op(0.0);
        Op* val2 = new Op(0.0);
        Add* test = new Add(val1, val2);
        EXPECT_EQ(test->evaluate(),0.0);
}

TEST(AddTest, AddEvalNegative){
        Op* val1 = new Op(-1.0);
        Op* val2 = new Op(-2.8);
        Add* test = new Add(val1, val2);
        EXPECT_EQ(test->evaluate(),-3.8);
}

TEST(AddTest, AddStringPos){
	Op* val1 = new Op(1.0);
	Op* val2 = new Op(2.8);
	Add* test = new Add(val1, val2);
	EXPECT_EQ(test->stringify(), "(1.000000+2.800000)");
}

TEST(AddTest, AddStringNeg){
        Op* val1 = new Op(-1.0);
        Op* val2 = new Op(-2.8);
        Add* test = new Add(val1, val2);
        EXPECT_EQ(test->stringify(), "(-1.000000+-2.800000)");
}

TEST(AddTest, AddStringZero){
        Op* val1 = new Op(0.0);
        Op* val2 = new Op(0.0);
        Add* test = new Add(val1, val2);
        EXPECT_EQ(test->stringify(), "(0.000000+0.000000)");
}

/*
TEST(AddTest, AddEvalMany){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Div* divn = new Div(val1,val1);
	Mult* multn = new Mult(divn, val2);
	Pow* pw = new Pow(multn,val2);
	Add* addn = new Add(pw,val1);
	EXPECT_EQ(addn->evaluate(),7.0);
}

TEST(AddTest, AddStrMany){
        Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
        Div* divn = new Div(val1,val1);
        Mult* multn = new Mult(divn, val2);
        Pow* pw = new Pow(multn,val2);
        Add* addn = new Add(pw,val1);
        EXPECT_EQ(addn->stringify(),"((((3.000000/3.000000)*2.000000)**2.000000)+3.000000)");
}
*/

TEST(AddTest, NumOfChildren){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* addn = new Add(val1,val2);
	EXPECT_EQ(addn->number_of_children(),2);
}

TEST(AddTest, getChild){
	Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
	Base* addn = new Add(val1,val2);
	EXPECT_EQ(addn->get_child(0),val1);
	EXPECT_EQ(addn->get_child(1),val2);
}
