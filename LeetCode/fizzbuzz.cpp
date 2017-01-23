#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
	std::vector<std::string> stringRepresentation(n);

	for (int interationPtr = 1; interationPtr <= n; ++interationPtr) {
		if (interationPtr % 3 == 0) {
			stringRepresentation[interationPtr-1] += std::string("Fizz");
		}  
		if (interationPtr % 5 == 0) {
			stringRepresentation[interationPtr-1] += std::string("Buzz");
		} 
		if (stringRepresentation[interationPtr-1] == "") {
			stringRepresentation[interationPtr-1] += std::to_string(interationPtr);
		}
	}

	return stringRepresentation;
}

int main() {
	std::vector<std::string> fizzBuzzVector = fizzBuzz(15);
	std::vector<std::string>::iterator it;
	for(it = fizzBuzzVector.begin(); it != fizzBuzzVector.end(); ++it) {
		std::cout<<*it<<std::endl;
	}
}