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
	std::cout << "find el = 4, index = " << bf_v.find(mass, size, 4) << std::endl;
	//---
	// пример работы алгоритма задачи о рюкзаке
	alg::Backpack bp;

	std::vector<int> w{2, 4, 4, 7};
	std::vector<int> c{2, 5, 5, 9};
	int W = 8;

	std::cout << "best price = " << bp.best_price(w, c, W) << std::endl;
	//---
	// пример работы алгоритма здача о 8ми ферзях
	alg::Queens queens8;

	queens8.setQueen(8);
	queens8.showBoard();

	//---
	// пример рабты метод хука-дживса
	alg::JeevesHook jh;
	jh.start();

	//--
	// пример работы задачи о башни
	std::cout << "TowerOfHanoi: ";
	alg::TowerOfHanoi th;
	th.start();

	return 0;
}