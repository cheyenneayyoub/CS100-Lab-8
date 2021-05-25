#ifndef _MULT_HPP_
#define _MULT_HPP_

#include "base.hpp"
#include "op.hpp"
#include <iostream>
#include <string>

using namespace std;

class Mult : public Base {
    private:
	Base *lnode; 
	Base *rnode;
    public:
        Mult(Base* left, Base* right) : Base() {
            if(left == nullptr || right == nullptr) 
		{	
			throw invalid_argument("Null argument.");
	}
		   lnode = left; rnode = right;
        }

        double evaluate() {
           return lnode->evaluate() * rnode->evaluate();
        }

        string stringify() {
            return '(' + lnode->stringify() + "*" + rnode->stringify() + ')';
        }
        
	int number_of_children(){
		int num = 0;
		if(lnode != NULL){
			num += 1;
		}
		if(rnode != NULL){
			num += 1;
		}
		return num;
	}
	Base* get_child(int i){
		if(i == 0) {
			return lnode;
		}
		if(i == 1){
			return rnode;
		}
	}
	void accept(Visitor* visitor, int index) {
		if(index == 0) {
			visitor->visit_mult_begin(this);  
		}	
		else if(index == 1) { 
			visitor->visit_mult_middle(this); 
		}
		else {
			visitor->visit_mult_end(this); 
		}	
	}
	virtual string print() {
		return "*";
	}
};

#endif
