#include <iostream>
#include <time.h>
#include <chrono>    // chrono 헤더
#include <vector>
#include <stdlib.h>
#include <random>    // 난수엔진 헤더
#include <algorithm>
#include <windows.h>
#include <stdio.h>

const int INT_RANGE = 100;
//struct timeval start_point, end_point;
LARGE_INTEGER liCounter1, liCounter2, liFrequency;
double operating_time;
int main() {
	std::default_random_engine randEngine;
	std::uniform_int_distribution<int> randRange(1,INT_RANGE);
	std::uniform_real_distribution<double> randRange2(0, 1);
	std::vector<int> make;
	float f3[8 * 1024] = {0,};//random이나 초기화하여 8*1024로 바꿔서
	float f2[8 * 1024] = {0,};//
	float f1[8 * 1024] = {0,};
	make.reserve(8 * 1024);
	int i ;
	srand(time(NULL));
	for (i = 0; i < 8*1024; i++) {
		f3[i] = randRange2(randEngine);
		f2[i] = randRange2(randEngine);
		//std::cout << f3[i]<<std::endl;
		if (randRange(randEngine) < 50)
			make.push_back(0);
		else
			make.push_back(1);
		//make.push_back(randRange(randEngine));
	}
	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&liCounter1);
//	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	for (i = 0; i < 8 * 1024; i++) {
		f1[i] = make[i] * f2[i] * f3[i];
		//std::cout << make[i] << std::endl;
	}
	QueryPerformanceCounter(&liCounter2);
	//std::chrono::system_clock::time_point stop = std::chrono::system_clock::now();    //현재 시간
	//std::chrono::duration<double, std::nano> d = stop - start;
	/// 시간 출력
	printf("수행 시간 = %f 초\n", (double)(liCounter2.QuadPart - liCounter1.QuadPart) / (double)liFrequency.QuadPart);
	return 0;
}
