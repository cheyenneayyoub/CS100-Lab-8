nclude "base.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"

using namespace std;

TEST(PowTest, NoBase){
	Base* val1 = NULL;
	Base* val2 = new Op(1.0);
	EXPECT_THROW(Pow(val1,val2),invalid_argument);
	
}

TEST(PowTest, NoPower){
	Base* val2 = NULL;
        Base* val1 = new Op(1.0);
        EXPECT_THROW(Pow(val1,val2),invalid_argument);
    
}

TEST(PowTest, NoArgument){
        Base* val2 = NULL;
        Base* val1 = NULL;
        EXPECT_THROW(Pow(val1,val2),invalid_argument);
}

TEST(PowTest, PowEvalPos){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* test = new Pow(val1,val2);
	EXPECT_EQ(test->evaluate(), 9.0);
}

TEST(PowTest, PowEvalNegBase){
        Base* val1 = new Op(-3.0);
        Base* val2 = new Op(2.0);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->evaluate(), 9.0);
}

TEST(PowTest, PowEvalFractionPow){
        Base* val1 = new Op(9.0);
        Base* val2 = new Op(0.5);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->evaluate(), 3.0);
}

TEST(PowTest, PowEvalAddSub){
	Base* val1 = new Op(2.0);
        Base* val2 = new Op(2.0);
	Base* val3 = new Op(3.0);
	Add* sum = new Add(val1,val2);
	Sub* sub = new Sub(sum,val3);
	Base* test = new Pow(sub,val1);
        EXPECT_EQ(test->evaluate(), 1.0);
}

TEST(PowTest, PowStrPos){
        Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->stringify(), "(3.000000**2.000000)");
}

TEST(PowTest, PowStrFractionPow){
        Base* val1 = new Op(9.0);
        Base* val2 = new Op(0.5);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->stringify(), "(9.000000**0.500000)");
}

TEST(PowTest, PowStrAddSub){
        Base* val1 = new Op(2.0);
        Base* val2 = new Op(2.0);
        Base* val3 = new Op(3.0);
        Add* sum = new Add(val1,val2);
        Sub* sub = new Sub(sum,val3);
        Base* test = new Pow(sub,val1);
        EXPECT_EQ(test->stringify(), "(((2.000000+2.000000)-3.000000)**2.000000)");
}

TEST(PowTest, PowEvalMany){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Div* divn = new Div(val1,val1);
	Mult* multn = new Mult(divn, val2);
	Pow* pw = new Pow(multn,val2);
	EXPECT_EQ(pw->evaluate(),4.0);
}

TEST(PowTest, PowStrMany){
        Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
        Div* divn = new Div(val1,val1);
        Mult* multn = new Mult(divn, val2);
        Pow* pw = new Pow(multn,val2);
    	EXPECT_EQ(pw->stringify(), "(((3.000000/3.000000)*2.000000)**2.000000)");
}
//new tests 

TEST(PowTest, NumOfChildren){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* pown = new Add(val1,val2);
	EXPECT_EQ(pown->number_of_children(),2);
}

TEST(PowTest, getChild){
	Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
	Base* pown = new Add(val1,val2);
	EXPECT_EQ(pown->get_child(0),val1);
	EXPECT_EQ(pown->get_child(1),val2);
}
