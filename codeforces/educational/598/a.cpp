// Tricky Sum
// https://codeforces.com/contest/598/problem/A

#include <iostream>
#include <math.h>
#include <chrono>


void computeAnswer(unsigned long long n) {
    long long accumulated = (n * (n + 1)) / 2;
    auto i = 1;
    while (i <= n) {
        i = i << 1;
        accumulated -= i;
    }
    
    std::cout << accumulated << '\n'; 
}

int main()
{
	std::string input;
	std::cin >> input;
	auto testCases = atoi(input.c_str());
	
	for (auto i = 0; i < testCases; ++i) {
        std::cin >> input;
		auto testN = atoi(input.c_str());
		computeAnswer(testN);
	}
}