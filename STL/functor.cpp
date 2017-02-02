//Function Object (Functor)
//Parameterized Function
#include <iostream>

class X {
public:
	void operator() (std::string str) {
		std::cout << "Calling functor X with parameter "<<str<<std::endl;
	}
};

int main() {
	X x;
	x("Hi");
}