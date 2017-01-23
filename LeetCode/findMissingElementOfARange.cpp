#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <iterator>

typedef std::map<int, bool> IntBoolMapType;
typedef std::pair<int, bool> IntBoolPairType;

void printMissingElementOfARange(int comparedArray[], int numberOfElementsInArray, int lowThreshold, int highThreshold) {
	IntBoolMapType intBoolMap;
	std::vector<int> finalResult;

	for (int i = 0; i < numberOfElementsInArray; ++i)
	{
		intBoolMap.insert(IntBoolPairType(comparedArray[i], true));
	}

	// for(auto const& value: comparedArray) {
	// 	intBoolMap.insert(IntBoolPairType(value, true))
	// }

	for (int elementToBeChecked = lowThreshold; elementToBeChecked <= highThreshold; elementToBeChecked++) {
		if ( !intBoolMap[elementToBeChecked] ) {
			finalResult.push_back(elementToBeChecked);
		}
	}

	for (std::vector<int>::iterator iter = finalResult.begin(); iter != finalResult.end(); ++iter) {
		std::cout << *iter << " "<<std::endl;
	}
}

int main() {
	int comparedArray[] = {1, 14, 11, 51, 15};
	int numberOfElementsInArray = sizeof(comparedArray) / sizeof(comparedArray[0]);
	printMissingElementOfARange(comparedArray, numberOfElementsInArray, 50, 55);
	return 0;
}