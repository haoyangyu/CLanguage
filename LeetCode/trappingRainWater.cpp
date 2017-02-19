//https://www.lintcode.com/en/problem/trapping-rain-water/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        vector<int> leftHigh = {0}, rightHigh = {0};
		int leftHighValue = 0, rightHighValue = 0, trapRainWater = 0;
        //solve edge case for size of heights equals 0
        if (!heights.size()) return trapRainWater;
        //record the max of left of this point
        for (int i = 0; i < heights.size()-1; ++i) {
        	if (heights[i] > leftHighValue) leftHighValue = heights[i];	
        	leftHigh.push_back(leftHighValue);
        }

        //record the max of right of this point
        for (int i = heights.size()-1; i > 0; --i) {
        	if (heights[i] > rightHighValue) rightHighValue = heights[i];
        	rightHigh.push_back(rightHighValue);
        }

        //reverse the right high vector
        reverse(rightHigh.begin(), rightHigh.end());

        for (int i = 0; i < heights.size(); ++i) {
        	int relativeMin = min(leftHigh[i], rightHigh[i]);
        	if (relativeMin > heights[i]) trapRainWater += relativeMin - heights[i];
        }
        return trapRainWater;
    }
};

int main() {
	//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
	vector<int> vect = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution *solution = new Solution();
	cout<< solution->trapRainWater(vect);
	return 0;
}