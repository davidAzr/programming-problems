// HDD is Outdated Technology
// https://codeforces.com/contest/612/problem/B

#include <iostream>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

void computeAnswer(const std::vector<int>& sectors) {
  long long time = 0;
  for(auto i = 1; i < sectors.size(); ++ i) {
      time += abs(sectors.at(i) - sectors.at(i-1));
  }
  std::cout << time << '\n';
}

int main()
{
    unsigned int n, ifragment;
    std::cin >> n;
    std::vector<int> sectors;
    sectors.resize(n);
    for(auto i=0; i<n; ++i) {
        std::cin >> ifragment;
        sectors[ifragment - 1] = i + 1;
    }
	computeAnswer(sectors);
}