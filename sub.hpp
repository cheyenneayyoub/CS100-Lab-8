#ifndef SUB_HPP_
#define SUB_HPP_

#include "base.hpp"

using namespace std;

class Sub : public Base{
	private:
		Base* lhs;
		Base* rhs;
	public:
		Sub(Base* left, Base* right) : Base() {
			lhs = left;
			rhs = right;
		}
		double evaluate() {
			return (lhs->evaluate() - rhs->evaluate());
		}
		string stringify(){
			return "(" + lhs->stringify() + "-" + rhs->stringify() + ")";
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

		void accept(Visitor* visitor, int index){
			if(index == 0) { 
				visitor->visit_sub_begin(this);  
			}	
			else if(index == 1) { 
				visitor->visit_sub_middle(this); 
			}
			else {
				visitor->visit_sub_end(this); 
			}	
		}
		virtual string print(){
			return "-";
		}
};

#endif
