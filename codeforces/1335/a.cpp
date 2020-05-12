// Candies and two sisters
// https://codeforces.com/problemset/problem/1335/A

#include <iostream>

void computeAnswer(unsigned int candies) {
    auto result = 0;
    if (candies < 2) {
        std::cout << '0' << '\n';
    }
    else {
        result = (candies % 2 == 0) ? candies / 2 - 1 : candies / 2;
        std::cout << result << '\n';
    }
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