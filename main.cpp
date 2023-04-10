#include<iostream>
#include"PrimeAlgo.h"
#include"MonotonicStack.h"
int main() {
	MonotonicStack solution;
	std::vector<int> v{ 1,2,3,4,5,5,1,2,3,7 };
	v = solution.theNextBiggerElement(v);
	for (int i : v) {
		std::cout << i << std::endl;
	}
}