#ifndef _RANDTEST_HPP_
#define _RANDTEST_HPP

#include "gtest/gtest.h"
#include "base.hpp"
#include "rand.hpp"
#include <iostream>
#include <string>


using namespace std;

TEST(RandTest, RandCheckLE) {
	Rand* test = new Rand ();
	EXPECT_LE(test->evaluate(), 100);
}

TEST(RandTest, RandCheckGE) {
        Rand* test = new Rand ();
        EXPECT_GE(test->evaluate(), 0);
}  

TEST(RandTest, RandCheckString) {
        Rand* test = new Rand ();
        EXPECT_NE(test->evaluate(), -1);
}
//new tests 

TEST(RandTest, NumOfChildren){
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* randn = new Add(val1,val2);
	EXPECT_EQ(randn->number_of_children(),2);
}

TEST(RandTest, getChild){
	Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
	Base* randn = new Rand(val1,val2);
	EXPECT_EQ(randn->get_child(0),val1);
	EXPECT_EQ(randn->get_child(1),val2);
}
#endif

