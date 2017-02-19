//https://www.lintcode.com/en/problem/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        //solve the edge case
        int vecLength = nums.size();
        int count, minCount;
        if (vecLength == 0) {
            return -1;
        } else if(vecLength == 1) {
            if (nums[0] < s) {
                return -1;
            } else {
                return 1;
            }
        }
        //normal case, the size of array larger than 2
        else {
            int i = 0;
            int j = 1;
            int sum = nums[i] + nums[j];
            count = 2;
            minCount = INT_MAX;
            for (i; i < nums.size(); ++i) {
                while (j < nums.size()) {
                    if (sum < s) {
                        j++;
                        count++;
                        sum += nums[j];
                        
                    } else {
                        //record the smallest count
                        minCount = min(minCount, count);
                        sum -= nums[i];
                        count--;
                        break;
                    }
                }
                if (sum < s and i == 0 and j == nums.size()) return -1;
            }
            return minCount;
        }
    }
};

int main() {
    vector<int> vec = {9,1,8,2,7,3,6,4,5,10};
    int s = 55;
    
    Solution *solution = new Solution();
    cout<<solution->minimumSize(vec, s)<<endl;
    return 0;
}
