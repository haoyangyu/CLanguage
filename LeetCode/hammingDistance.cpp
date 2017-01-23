#include <iostream>
using std::cout;
using std::endl;

int hammingDistance(int x, int y) {
        int valueAfterXOR = x ^ y;
        int iterationTime = 32;
        int hammingDistance = 0;
        
        for (int iterationPtr = 0; iterationPtr < iterationTime; iterationPtr++) {
            int examBit = valueAfterXOR & 1;
            if (examBit == 1) hammingDistance++;
            valueAfterXOR >>= 1;
        }
    return hammingDistance;
  }

  int main(){
  	std::cout<<hammingDistance(2, 4)<<std::endl;
  }