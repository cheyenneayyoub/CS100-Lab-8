#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"

class Add : public Base{

	private:
		Base* lhs;
		Base* rhs;
	public:
		Add(Base* left, Base* right){
			lhs = left;
			rhs = right;
		}
		double evaluate() {
			return lhs->evaluate() + rhs->evaluate();
		}
		string stringify(){
			return "(" + lhs->stringify() + "+" + rhs->stringify() + ")";
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
				visitor->visit_add_begin(this);  
			}	
			else if(index == 1) { 
				visitor->visit_add_middle(this); 
			}
			else {
				visitor->visit_add_end(this); 
			}	
		}
		virtual string print(){
			return "+";
		}
};

#endif
