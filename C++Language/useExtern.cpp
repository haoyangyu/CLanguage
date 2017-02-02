#include <iostream>

extern void externDef();
extern int globalValue;

int main() {
	//externDef();
	std::cout<<globalValue<<std::endl;
	return 0;
}