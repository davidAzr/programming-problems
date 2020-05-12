// USB Flash Drives
// https://codeforces.com/contest/609/problem/A

#include <iostream>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void computeAnswer(std::vector<unsigned int>& drivesSizes, unsigned int fileSize) {
    std::sort(begin(drivesSizes), end(drivesSizes), [](auto elem1, auto elem2) { return elem1 > elem2; });
    auto accumulated = 0;
    for(auto i = 0; i < drivesSizes.size(); ++i){
        accumulated += drivesSizes.at(i);
        if(accumulated >= fileSize) {
            std::cout << i + 1 << '\n';
            break;
        }
    }
}

int main()
{
    unsigned int nFlashDrives, fileSize, driveSize;
    std::vector<unsigned int> drivesSizes;
	std::cin >> nFlashDrives;
    std::cin >> fileSize;
	
	for (auto i = 0; i < nFlashDrives; ++i) {
        std::cin >> driveSize;
        drivesSizes.push_back(driveSize);
    }

	computeAnswer(drivesSizes, fileSize);

}