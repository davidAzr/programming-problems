// The Best Gift
// https://codeforces.com/contest/609/problem/B

#include <iostream>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

void computeAnswer(const std::vector<unsigned int>& booksPerGenre) {
    auto combinations = 0;
    for(auto i = 0; i < booksPerGenre.size(); ++i) {
        for(auto t = i + 1; t < booksPerGenre.size(); ++t) {
            combinations += booksPerGenre.at(i) * booksPerGenre.at(t);
        }          
    }
    std::cout << combinations << '\n';
}

int main()
{
    unsigned int nBooks, nGenres, bookGenre;
	std::cin >> nBooks >> nGenres;
	std::vector<unsigned int> booksPerGenre;
    booksPerGenre.resize(nGenres);
    std::fill(std::begin(booksPerGenre), std::end(booksPerGenre), 0);
	for (auto i = 0; i < nBooks; ++i) {
        std::cin >> bookGenre;
        ++booksPerGenre.at(bookGenre - 1);
    }
	computeAnswer(booksPerGenre);
}