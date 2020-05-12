// Road to Zero
// https://codeforces.com/problemset/problem/1342/A

#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>

void computeAnswer(long long x, long long y, long long a, long long b) {
    unsigned long long totalCost = 0;
    if (b > 2*a) totalCost = a * (x + y);
    else {
        auto c = abs(x - y);
        totalCost = a * c + b * (std::max(x, y) - c);
    }

    std::cout << totalCost << '\n';
}

int main()
{
	std::string input;
	std::cin >> input;
	auto testCases = atoi(input.c_str());
    std::cin.ignore();
	long x, y, a, b;
	for (auto i = 0; i < testCases; ++i) {
        std::getline(std::cin, input);
        std::stringstream buffer(input);
        buffer >> x;
        buffer >> y;
        std::getline(std::cin, input);
        buffer = std::stringstream(input);
        buffer >> a;
        buffer >> b;
        computeAnswer(x, y, a, b);
	}
}