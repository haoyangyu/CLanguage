//source: http://www.lintcode.com/en/problem/number-of-airplanes-in-the-sky/

#include <iostream>
#include <vector>

using namespace std;

struct TimeSpot {
	int time;
	int state;

	bool operator < (const TimeSpot& spot) const {
        if ( time != spot.time)
    		return (time < spot.time);
    	//must sort on state based on time
    	//cuz the algo record the maximum number in air, if we do not sort by two attributes in TimeSpot
    	//The flight number in air will not be affected, but the maximum will be affected
  		return (state < spot.state);
    }
};

class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

class Solution {
private:
	vector<TimeSpot> timeSpotVector;
	int numsOnSky, maxNumsOnSky;
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        //transform the vector into sorted self-defined array
    	for (vector<Interval>::iterator itr = airplanes.begin(); itr != airplanes.end(); ++itr) {
    		TimeSpot timeSpotStart = {itr->start, 1};
    		timeSpotVector.push_back(timeSpotStart);
    		TimeSpot timeSpotEnd = {itr->end, 0};
    		timeSpotVector.push_back(timeSpotEnd);
    	}

    	//sort the timeSpotVector
    	sort(timeSpotVector.begin(), timeSpotVector.end());
    	numsOnSky = 0;
    	maxNumsOnSky= 0;
    	//calculate the planes in sky
    	for (vector<TimeSpot>::iterator itr = timeSpotVector.begin(); itr != timeSpotVector.end(); ++itr) {
    		if (itr->state) {
    			numsOnSky++;
    			if (maxNumsOnSky < numsOnSky) maxNumsOnSky = numsOnSky;
    		} else {
    			numsOnSky--;
    		}
    	}
    	return maxNumsOnSky;
	}
};

int main() {
	vector<Interval> nums = {{12,19},{84,89},{42,46},{89,94},{96,98},{38,47},{13,22},{98,99},{3,11},{28,38},{96,98},{79,81},{91,98},{37,42},{24,28},{8,10},{18,20},{1,7},{80,83},{84,85},{13,21},{17,19},{37,39},{58,65},{3,11},{25,31},{46,50},{92,99},{38,40},{73,81},{85,95},{30,38},{23,32},{98,101},{60,64},{81,85},{86,92},{64,69},{27,28},{54,59},{90,94},{5,15},{78,79},{98,102},{39,45},{88,90},{89,97},{23,25},{57,67},{13,21},{4,7},{95,105},{93,100},{55,61},{18,21},{29,35},{22,25},{14,16},{52,57},{56,60},{82,89},{99,100},{78,87},{42,46},{24,26},{61,68},{56,63},{98,99},{32,36},{5,12},{76,80},{91,100},{89,94},{28,36},{35,44},{70,76},{43,52},{43,50},{70,73},{8,16},{79,81},{89,91},{98,105},{36,41},{93,99},{52,59},{70,71},{86,90},{31,33},{3,11}};
	Solution *solution = new Solution();
    int result = solution->countOfAirplanes(nums);
    
    cout<< result <<endl;
    return 0;
}