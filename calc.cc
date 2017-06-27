#ifndef CALC_CC
#define CALC_CC
#include <iostream>
#include "calc.h"

    Calc::Calc()
	:display{0}, oper{'\0'}, result{0},
	memory{0}, error{false}{}
	
    Calc::Calc(const Calc &other)
	:display{other.display}, oper{other.oper}, result{other.result},
	memory{other.memory}, error{other.error}{}

    void Calc::digit(int digit) {
		if(error) return;
		if((digit <= 9) && (digit >= 0)) {
			if(display >= 0) {
				this->display = this->display * 10 + digit;
			} else {
				this->display = this->display * 10 - digit;
			}
		}
    }
  
    void Calc::op(char oper) {
		if(error) return;
		if(this->oper == '+') {
			result += display;
		} else if (this->oper == '-') {
			result -= display;
		} else if(this->oper == '*') {
			result *= display;
		} else if(this->oper == '/') {
			if(display == 0) {
				result = 0;
				error = true;
			} else {
				result = result / display;
			}
		} else if(this->oper == '\0') {
			result = display;
		}
		this->oper = oper;
		display = 0;
    }
  
    void Calc::equals(){
		if(error) return;
		if(this->oper == '+') {
			result += display;
		} else if (this->oper == '-') {
			result -= display;
		} else if(this->oper == '*') {
			result *= display;
		} else if(this->oper == '/') {
			if(display == 0) {
				result = 0;
				error = true;
			} else {
				result = result / display;
			}
		} else if(this->oper == '\0') {
			result = display;
		}
		display = result;
		oper = '\0';
	}
    void Calc::memPlus(){
		if(error) return;
		memory += display;
	}
    void Calc::memClear(){
		if(error) return;
		memory = 0;
	}
    void Calc::memRecall(){
		if(error) return;
		display = memory;
	}
    bool Calc::isError() const{
		return error;
	}
    void Calc::allClear() {
		error = false;
		display = 0;
		oper = '\0';
		result = 0;
		memory = 0;
	}


std::ostream &operator<<(std::ostream &out, const Calc &c) {
	if(c.memory == 0) {
		out << c.display;
	} else {
		out << c.display << " M: " << c.memory;
	}
	if(c.error) {
		out << " E";
	}
	return out;
}

#endif

