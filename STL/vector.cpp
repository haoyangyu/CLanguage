#include <iostream>
#include <vector>

int main(){
	std::vector<int> vec; //Dynamic allocated array stored in heap
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);

	std::vector<int>::iterator itr1 = vec.begin();
	std::vector<int>::iterator itr2 = vec.end();

	for (std::vector<int>::iterator itr = itr1; itr != itr2; itr++) {
		std::cout << *itr << " ";
	}

	sort(itr1, itr2);
}
