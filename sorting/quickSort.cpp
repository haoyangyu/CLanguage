#include <iostream>
#include <vector>

int partition(std::vector<int> &v, int begin, int end, int pivotIndex) {
	int storageIndex = begin;

	for (int index = begin; index < end; ++index) {
		if (v[index]<v[pivotIndex])	{	
			std::swap(v[index], v[storageIndex]);
			storageIndex++;
		}
	}
	std::swap(v[storageIndex], v[end]);
	return storageIndex;
}

void quickSort(std::vector<int> &v, int begin, int end) {
	if (begin < end) {
		//the most important function is partition
		int storageIndex = partition(v, begin, end, end);
		quickSort(v, begin, storageIndex-1);
		quickSort(v, storageIndex+1, end);
	}
}

void printVector(std::vector<int> &v) {
	std::vector<int>::iterator iterBegin = v.begin();
	std::vector<int>::iterator iterEnd = v.end();

	for (std::vector<int>::iterator index = iterBegin; index != iterEnd; ++index) {
		std::cout<<*index<<" ";
	}
	std::cout<<""<<std::endl;
}

int main() {
	std::vector<int> vet = {2,3,5,93,12,35,88,234,21,2,34,57,43};
	printVector(vet);
	quickSort(vet, 0, vet.size()-1);
	printVector(vet);
	return 0;
}