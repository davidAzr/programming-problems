// Balanced Array
// https://codeforces.com/problemset/problem/1343/B

#include <iostream>

void computeAnswer(unsigned int arraySize) {
    if( arraySize >> 1 & 1 ) {
        std::cout << "NO" << '\n';
    }
    else {
        std::cout << "YES" << '\n';
        auto initializer = 2, sumLeft = 0, sumRight = 0;
        for(auto i = 0; i < arraySize / 2; ++i) {
            std::cout << initializer << ' ';
            sumLeft += initializer;
            initializer += 2;
        }
        initializer = 1;
        for(auto i = arraySize / 2; i < arraySize - 1; ++i) {
            std::cout << initializer << ' ';
            sumRight += initializer;
            initializer += 2;
        }

        std::cout << sumLeft - sumRight << '\n';
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