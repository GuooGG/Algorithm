#include<iostream>
#include"PrimeAlgo.h"
#include"MonotonicStack.h"
#include"Sort.h"
int main() {
	std::vector<int> v{14,52,4,6,2,7,8,13,41, 6,1,2,7,3,4,16,11,5,1,2,3,7,5,66,77,22,99,44,88,33,14 };
	Sort::mergeSort(v,0,v.size()-1);
	for (int i : v) {
		std::cout << i << std::endl;
	}
}