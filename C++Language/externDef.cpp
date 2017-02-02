#include <iostream>

int globalValue = 100;
void externDef() {
	std::cout<<globalValue<<std::endl;
}