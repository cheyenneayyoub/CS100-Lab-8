#include "gtest/gtest.h"
#include "sub.hpp"
#include "add.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "mult.hpp"

using namespace std;

//old tests
TEST(SubTest, SubEvalPos){
	Op* val1 = new Op(2.8);
	Op* val2 = new Op(1.0);
	Sub* test = new Sub(val1, val2);
	EXPECT_DOUBLE_EQ(test->evaluate(),1.8);
}

TEST(SubTest, SubEvalNeg){
        Op* val1 = new Op(-2.8);
        Op* val2 = new Op(-1.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_DOUBLE_EQ(test->evaluate(),-1.8);
}

TEST(SubTest, SubEvalZero){
        Op* val1 = new Op(0.0);
        Op* val2 = new Op(0.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->evaluate(),0.0);
}

TEST(SubTest, SubEvalAdd){
        Op* val1 = new Op(2.8);
        Op* val2 = new Op(1.0);
	Op* val3 = new Op(5.0);
        Add* num  = new Add(val1, val2);
	Sub* test = new Sub(val3, num);
        EXPECT_DOUBLE_EQ(test->evaluate(),1.2);
}

TEST(SubTest, SubStringPos){
        Op* val1 = new Op(2.8);
        Op* val2 = new Op(1.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->stringify(), "(2.800000-1.000000)");
}

TEST(SubTest, SubStringNeg){
        Op* val1 = new Op(-2.8);
        Op* val2 = new Op(-1.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->stringify(), "(-2.800000--1.000000)");
} 

TEST(SubTest, SubStringZero){
        Op* val1 = new Op(0.0);
        Op* val2 = new Op(0.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->stringify(), "(0.000000-0.000000)");
}

TEST(SubTest, SubStringAdd){
        Op* val1 = new Op(2.8);
        Op* val2 = new Op(1.0);
        Op* val3 = new Op(5.0);
        Add* num  = new Add(val1, val2);
        Sub* test = new Sub(val3, num);
        EXPECT_EQ(test->stringify(), "(5.000000-(2.800000+1.000000))");
}

TEST(SubTest, SubEvalMany){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Div* divn = new Div(val1,val1);
	Mult* multn = new Mult(divn, val2);
	Pow* pw = new Pow(multn,val2);
	Sub* subn = new Sub(pw,val1);
	EXPECT_EQ(subn->evaluate(),1.0);
}

TEST(SubTest, SubStrMany){
        Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
        Div* divn = new Div(val1,val1);
        Mult* multn = new Mult(divn, val2);
        Pow* pw = new Pow(multn,val2);
        Sub* subn = new Sub(pw,val1);
        EXPECT_EQ(subn->stringify(),"((((3.000000/3.000000)*2.000000)**2.000000)-3.000000)");
}
//new tests

TEST(SubTest, numchildrentest){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* Sub = new Sub(val1,val2);
	EXPECT_EQ(Sub->number_of_children(),2);
}

TEST(SubTest, getChild){
	Base* val1 = new Op(5.0);
        Base* val2 = new Op(10.0);
	Base* subn = new Sub(val1,val2);
	EXPECT_EQ(subn->get_child(0),val1);
	EXPECT_EQ(subn->get_child(1),val2);
}
