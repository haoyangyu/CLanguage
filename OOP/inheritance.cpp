
#include <stdio.h>
#include <iostream>

using namespace std;

class Sphere {
public:
	Sphere() {
		printf("%s\n", "void");
	}

	Sphere(double initialRadius) {
		setRadius(initialRadius);
		printf("%s\n", "Parent");
	}

	double getRadius() {
		return theRadius;	
	}
	void setRadius(double newRadius) {
		theRadius = newRadius;
	}

private:
	double theRadius;
};

class Ball : public Sphere {
public:
	Ball() {
	}

	Ball(string initialName, double initialRadius) {
		Sphere::setRadius(initialRadius);
		setName(initialName);
		printf("%s\n", "Son");
	}

	string getName() {
		return theName;
	}

	void setName(string newName) {
		theName = newName;
	}

private:
	string theName;
};

int main() {
	Sphere sphere(5.0);
	printf("%f\n", sphere.getRadius());

	Ball ball("Hao", 10.0);
	printf("%f\n", ball.getRadius());
	return 0;
}