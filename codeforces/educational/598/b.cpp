// Queries on a String
// https://codeforces.com/contest/598/problem/B

#include <iostream>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>

void computeAnswer(std::string& inputStr, unsigned int l, unsigned int r, unsigned int k) {
    auto sub = r - l, erase = r; 
    --l, --r;
    if(sub == 0) return;
    std::string str;
    str.resize(sub+1);
    k = k % (sub + 1);
    auto leftSize = sub + 1 - k;
    str.replace(0, k, inputStr.substr(r - k + 1, k));
    str.replace(k , leftSize, inputStr.substr(l, leftSize));
    inputStr.replace(l, sub + 1, str);
}

int main()
{

	std::string inputString, input;
    unsigned int nQueries, l, r, k;
	std::cin >> inputString;
    std::cin >> nQueries;
	
	for (auto i = 0; i < nQueries; ++i) {
        std::cin >> l >> r >> k;
		computeAnswer(inputString, l, r, k);
    }

    std::cout << inputString << '\n';

}