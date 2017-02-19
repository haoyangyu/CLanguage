#include <iostream>
#include <vector>

using namespace std;

class ConnectingGraph {
private:
	vector<int> ascenster;

public:
    ConnectingGraph(int n) {
        // initialize your data structure here.
        for(int i = 0; i <= n; ++i) {
        	ascenster.push_back(0);
        }
    }
    
    //implement find function to find the root value    
    int find(int x) {
    	if (ascenster[x] == 0) {
    		return x;
    	}

    	ascenster[x] = find(ascenster[x]);
    	return ascenster[x];
    }

    void connect(int a, int b) {
        // Write your code here
    	int root_a = find(a);
    	int root_b = find(b);

    	//point b to a
    	if(root_a != root_b) {
    		ascenster[root_b] = root_a;
    	}
    }

    bool query(int a, int b) {
        // Write your code here
    	int root_a = find(a);
    	int root_b = find(b);

    	return root_a == root_b;
    }
};

int main() {
	ConnectingGraph *connectingGraph =  new ConnectingGraph(5);

	cout<< connectingGraph->query(1,2) << endl;
	connectingGraph->connect(1,2);
	cout<< connectingGraph->query(1,3) << endl;
	connectingGraph->connect(2,4);
	cout<< connectingGraph->query(1,4) << endl;
}

