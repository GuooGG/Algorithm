#include<iostream>
#include"PrimeAlgo.h"
#include"MonotonicStack.h"
#include"Sort.h"
int main() {
	std::vector<int> v{ 6,1,2,7,3,4,16,11,5,1,2,3,7 };
	Sort::insertionSort(v);
	for (int i : v) {
		std::cout << i << std::endl;
	}
}