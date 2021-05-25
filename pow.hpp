#ifndef POW_HPP_
#define POW_HPP_

#include "base.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

using namespace std;
class Pow : public Base{
	private:
		Base* lhs;
		Base* rhs;
	public:
		Pow(Base* left, Base* right) : Base() {
			if(left==nullptr || right == nullptr){throw std::invalid_argument("Null argument passed into Pow.");}
                        if(left->evaluate() < 0 && (right->evaluate()<1)){throw std::invalid_argument("Imaginary number.");}
			lhs = left;
			rhs = right;
		}
		double evaluate() {
			return pow(lhs->evaluate(), rhs->evaluate());
		}
		string stringify(){
			return "(" + lhs->stringify() + "**" + rhs->stringify() + ")";
		}
		int number_of_children(){
			int num = 0;
			if(lhs != NULL){
				num += 1;
			}
			if(rhs != NULL){
				num += 1;
			}
			return num;
		}
		Base* get_child(int i){
			if(i == 0){
				return lhs;
			}
			if(i == 1){
				return rhs;
			}	
		}

		void accept(Visitor* visitor, int index) {
			if(index == 0) { 
				visitor->visit_pow_begin(this);  
			}	
			else if(index == 1) { 
				visitor->visit_pow_middle(this); 
			}
			else {
				visitor->visit_pow_end(this); 
			}	
		}
		virtual string print(){
			return "**";
		}
};

#endif
