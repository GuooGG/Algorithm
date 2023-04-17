#include<iostream>
#include"PrimeAlgo.h"
#include"MonotonicStack.h"
#include"Sort.h"
int main() {
	std::vector<int> v{14,52,4,6,2,7,8,13,41, 6,1 };
	Sort::quickSort(v,0,v.size()-1);
	for (int i : v) {
		std::cout << i << std::endl;
	}
}