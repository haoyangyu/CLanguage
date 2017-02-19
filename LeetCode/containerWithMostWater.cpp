#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int maxarea;    
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int sizeOfVector = heights.size();
        int start = 0;
        int end = sizeOfVector - 1;

        //need to take care of the edge cases
        if (sizeOfVector == 0) {
            return 0;
        } else {
           end = sizeOfVector - 1; 
        }

        maxarea = min(heights[start], heights[end]) * (end-start);
        while (start < end) {
            if (maxarea < min(heights[start], heights[end]) * (end-start)) {
                maxarea = min(heights[start], heights[end]) * (end-start);
            }

            if (heights[start] < heights[end]) {
                start++;
            }
            else{
                end--;
            }
        }
        return maxarea;
    }
};

int main() {
    vector<int> vect = {1,3,2};
    Solution *solution = new Solution;
    cout << solution->maxArea(vect) << endl;
}