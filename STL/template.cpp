//introduction to templates

//The reason why do we need to bring function template
// int square (int x) {
// 	return x*x;
// }

// double square (double x) {
// 	return x*x;
// }

#include <iostream>
#include <vector>

//function template
template <typename T>
T square(T x) {
	return x*x;
}

//class template
template<typename T>
class HaoVector {
	T array[100];
	int size;
public:
	HaoVector():size(0) {}
	void push(T x) {array[size] = x; ++size;}
	T getByIndex(int i) const {return array[i];}
	int getSize() const {return size;}
	void print() const {for (int i=0; i<size; ++i) {std::cout<<array[i]<<std::endl;}} 
};

//operator overloading
//*: vector multiple operation
template<typename T>
HaoVector<T> operator*(const HaoVector<T>& rhs1, HaoVector<T>& rhs2) {
	HaoVector<T> ret;
	for (int i=0; i<rhs1.getSize(); ++i) {
		ret.push(rhs1.getByIndex(i)*rhs2.getByIndex(i));
	}
	return ret;
}

int main() {  //Code bloat
	std::cout << square<int>(5) << std::endl;
	std::cout << square<double>(5.5) << std::endl;

	HaoVector<int> vec;
	vec.push(2);
	vec.push(5);
	vec.push(8);
	std::cout <<"Self defined print" <<std::endl;
	vec = square(vec);
	vec.print();
}