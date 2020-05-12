// Alternating Subsequence
// https://codeforces.com/problemset/problem/1343/C

#include <iostream>
#include <sstream>
#include <math.h>

void computeAnswer(unsigned short aLength , std::stringstream& aElems) {
    long currentMax = 0, currentElem = 0, prevElem = 0;
    long long accumulated = 0;
    aElems >> prevElem;
    currentMax = prevElem;
    while(aElems >> currentElem) {
        if(std::signbit(currentElem) != std::signbit(prevElem)){
            accumulated += currentMax;
            currentMax = currentElem;
        }
        else {
            currentMax = std::max(currentMax, currentElem);
        }
        prevElem = currentElem;
    }

    accumulated += currentMax;

    std::cout << accumulated << '\n';
}

int main()
{
	std::string input;
	std::cin >> input;
	auto testCases = atoi(input.c_str());
	
	for (auto i = 0; i < testCases; ++i) {
        std::cin >> input;
		auto aLength = atoi(input.c_str());
        std::cin.ignore();
        std::getline(std::cin, input);
        std::stringstream aElems(input);
        computeAnswer(aLength, aElems);
	}
}