// Candies
// https://codeforces.com/problemset/problem/1343/A

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unordered_map>

std::pair<unsigned int, unsigned int> computeAnswer(unsigned int n) {
	unsigned int k, x;
	bool answerFound = false;
	k = 2;
	std::unordered_map<unsigned int, std::pair<unsigned int, unsigned int>> prevk;
	while (!answerFound) {
		auto currentCandies = 0, currentCandiesPrev = 0;

		auto a = 0;
		auto b = n / 3;
		x = b / 2 + 1;
		bool found = false;
		while (!found) {
			{
				auto previousValue = prevk.find(x);
				auto previousValuePrev = prevk.find(x - 1);
				if (previousValue == end(prevk)) {
					currentCandies = x;
					for (auto i = 1; i < k; ++i) {
						currentCandies += pow(2, i) * x;
					}
					prevk.insert({ x, std::make_pair(k,currentCandies)});
				}
				else {
					if (previousValue->second.first != k) {
						currentCandies = previousValue->second.second + x * pow(2, k - 1);
						prevk[x] = std::make_pair(k, currentCandies);
					}
					else {
						currentCandies = previousValue->second.second;
					}
				}
				if (previousValuePrev == end(prevk)) {
					currentCandiesPrev = x-1;
					for (auto i = 1; i < k; ++i) {
						currentCandiesPrev += pow(2, i) * (x-1);
					}
					prevk.insert({ x-1, std::make_pair(k,currentCandiesPrev) });
				}
				else {
					if (previousValuePrev->second.first != k) {
						currentCandiesPrev = previousValuePrev->second.second + (x - 1) * pow(2, k - 1);
						prevk[x - 1] = std::make_pair(k, currentCandiesPrev);
					}
					else {
						currentCandiesPrev = previousValuePrev->second.second;
					}
				}
			}
			if (currentCandies < n) {
				a = x;
				x = a + (b - a) / 2 + 1;
			}
			else if (currentCandies >= n) {
				if (currentCandiesPrev < n) {
					found = true;
				}
				else {
					b = x;
					x = x/2;
				}
			}
		}

		if (currentCandies == n) {
			return std::make_pair(x, k);
		}

		++k;
	}
	return std::make_pair(x, k);
}

int main()
{
	std::string testCasesStr, testNStr;
	int testCases;
	std::cin >> testCases;
	
	for (auto i = 0; i < testCases; ++i) {
		int testN;
		std::cin >> testN;
		auto result = computeAnswer(testN);
		std::cout << result.first << '\n';
	}
}