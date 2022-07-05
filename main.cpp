#include<iostream>
#include<vector>
#include"alg.h"
#include "alg.inl"

int main(void)
{
	// пример работы бинарного поиска ---
	alg::BF bf_v;

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6 ,10 ,22, 30 };
	const int size = 6;
	int mass[size] = { 1, 2, 3, 4, 5, 6 };
	
	std::cout << "find el = 5, index = " << bf_v.find(vec, 5) << std::endl;
	std::cout << "find el = 4, index = " << bf_v.find(mass, size, 4);
	//---

	return 0;
}