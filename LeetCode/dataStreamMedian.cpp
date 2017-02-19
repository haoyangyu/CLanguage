#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	int numsOfValue = 0;
	priority_queue<int> maxHeap, minHeap;
	vector<int> result;

public:
	//minHeap maintains the max half of the full vector
	//maxHeap maintains the min half of the full vector
	void getAdd(int currentValue) {
		maxHeap.push(currentValue);
		//seperate the value equally into both maxHeap and minHeap
		//even value move it to maxHeap directly
		if (numsOfValue % 2 == 0) {
			//minHeap is emply, solve the initial phase
			if (minHeap.empty()) {} 
			//if minHeap is not empty, we need to compare the top of maxHeap and minHeap
			else {
				if (maxHeap.top() > (-1) * minHeap.top()) {
					minHeap.push((-1) * maxHeap.top());
					maxHeap.pop();
					maxHeap.push((-1) * minHeap.top());
					minHeap.pop();

				}
			}
		} 
		//odd value move it to minHeap from maxHeap
		else {
			minHeap.push((-1) * maxHeap.top());
			maxHeap.pop();

		}
		++numsOfValue;
		return;
	}

	int getMedian() {
		return maxHeap.top();
	}

	vector<int> medianII(vector<int> &nums) {
		int sizeOfNums = nums.size();
		for (int numsIterator = 0; numsIterator < sizeOfNums; ++numsIterator) {
			getAdd(nums[numsIterator]);
			result.push_back(getMedian());
		}
		return result;
	}
};

int main() {
	vector<int> nums = {1,2,3,4,5};
	Solution *solution = new Solution();
    vector<int> result = solution->medianII(nums);
    
    for (vector<int>::iterator itr = result.begin(); itr != result.end(); ++itr) {
        cout << *itr <<endl;
    }
    
    return 0;
}