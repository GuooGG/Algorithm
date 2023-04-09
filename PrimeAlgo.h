#pragma once
#include<algorithm>
#include<bitset>
#include<vector>
#include<iostream>
class PrimeAlgo
{
private:
	//问题范围
	static const int maxn = 1e4 + 10;
	std::bitset<maxn> bitmap;
public:
	PrimeAlgo() = default;
	//内联限定符的作用？
	inline bool isprime(int x);
	//朴素筛法
	std::vector<int> sieve(int n = maxn);
	//埃氏筛
	std::vector<int> sieveOfEratosthenes(int n = maxn);
	//欧拉筛
	std::vector<int> sieveOfEuler(int n = maxn);
};

