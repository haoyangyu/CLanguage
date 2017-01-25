#include <iostream>
#include <vector>

using namespace std;

int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        int vector_size = nums.size();
        int startPosition = 0;
        int returnPairs = 0;
        for (int iterationPointer = startPosition; iterationPointer < vector_size; ++iterationPointer) {
        	int aimedValue = target - nums[iterationPointer];
        	for (int innerIterationPointer = iterationPointer + 1; innerIterationPointer < vector_size; ++innerIterationPointer) {
        		if (nums[innerIterationPointer] > aimedValue) {
        			returnPairs++;
        		}
        	}
        }
        return returnPairs;
}

int main() {
	vector<int> vec = {2, 7, 11, 15};
	cout<<twoSum2(vec, 24);
	return 0;
}

