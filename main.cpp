#include<iostream>
#include"PrimeAlgo.h"
#include"MonotonicStack.h"
#include"Sort.h"
int main() {
	std::vector<int> v{14,52,4,6,2,7,8,13,41, 6,1,65, 16, 22, 52, 19, 23, 89, 76, 11, 1, 30, 60, 65, 61, 77, 10, 3, 9, 64, 5, 16, 89, 91, 18, 46, 38, 57, 11, 98, 88, 48, 52, 19, 89, 53, 78, 80, 36, 23, 54, 0 };
	Sort::mergeSort(v,0,v.size()-1);
	for (int i : v) {
		std::cout << i << std::endl;
	}
}