//const.cpp is for understanding 
//1. const parameters
//2. const return value
//3. const function
#include <iostream>

class Dog {
	int age;
	string name;
public:
	Dog():age(3), name("dummy");
	// const parameters
	void setAge(const int a) { age = a; }
	void setAge(int a) { age = a;}
	void setAge (const int& a) {age = a;} //because of const reference parameter is widly used

	// const return value
	const string& getName() {return name;} // This make sure the return value will not be changed
	const string getName() {return name;} //Does not make sure, cuz return a temparory value

	// const function
	// it will not change the any member value of this class
	// const function can only call another const function
	void printDogName const { cout<<getName()<<endl; }
	// it will be called based on the const object
	void printDogName { cout<<getName()<<endl; }

	~Dog();
	
};