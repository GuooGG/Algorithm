#include<iostream>
#include"PrimeAlgo.h"
int main() {
	PrimeAlgo* p = new PrimeAlgo();
	std::vector<int> v = p->sieve();
	for (int i : v) {
		std::cout << i << std::endl;
	}
	return 0;
}