#ifndef __VISITOR_LATEX_TEST_HPP__
#define __VISITOR_LATEX_LATEX_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "rand.hpp"

#include "iterator.hpp"
#include "visitor_latex.hpp"

using namespace std;

TEST(VisitorLaTeXTest, OpCount) {   
    Base* num[8] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7) };

    VisitorLaTeX* latex = new VisitorLaTeX();
    string out = "${0.000000}$\n";    
    EXPECT_EQ(latex->PrintLaTeX(num[0]), out);
}

TEST(VisitorLaTeXTest, AllOperators) {
    Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
    Base *add, *sub, *mult, *div, *ans;
    Base *neg = new Op(-6);

    add   = new Add(neg, num[12]);   
    sub   = new Sub(num[8], add);      
    mult  = new Mult(neg, sub);      
    div   = new Div(mult, num[4]);   
    ans  = new Pow(div, num[4]);  // $(\\frac{-6}

    VisitorLaTeX* latex = new VisitorLaTeX();
    string out = "$((\\frac{({-6}\\cdot({8}-({-6}+{-6})))}{{-4})^{4})$\n";
    EXPECT_EQ(latex->PrintLaTeX(ans), out);

    for (auto i : num) delete i;
    delete latex, ans;
    delete add, sub, mult, div;
}

TEST(VisitLaTeXTest, multiple1) {
	Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
       
           Base* left = new Mult(num[2], num[2]); // 2*2 = 4
           Base* right = new Pow(num[2], num[2]); // 2**2 = 4
           Base* ans = new Div(left , right);
           
	VisitorLaTeX* latex = new VisitorLaTeX();
        string out = "$(\\frac{({2}\\cdot{2})}{({2}^{2}))$\n";
        EXPECT_EQ(latex->PrintLaTeX(ans), out);

        for (auto i : num) delete i;
    	    delete latex, left, right, ans;
}

TEST(VisitLaTeXTest, Multiple2) {
        Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9) };
       
        Base* x = new Sub(num[8], num[0]); // 8-0= 8
        Base* ans1 = new Add(num[0], x); //0+(8-0)=8
        //Base* ans = new Sub(left , right);
           
        VisitorLaTeX* latex = new VisitorLaTeX();
        string out = "$({0}+{8}-{0}))$\n";
        EXPECT_EQ(latex->PrintLaTeX(ans1), out);
    
        for (auto i : num) delete i;
            delete latex, x, ans1;
}

#endif
