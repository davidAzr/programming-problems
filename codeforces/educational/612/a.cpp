// The Text Splitting
// https://codeforces.com/contest/612/problem/A

#include <iostream>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

void computeAnswer(const std::string& s, unsigned int n, unsigned int p, unsigned int q) {
    unsigned int a, b, c, i, j;
    i = 0;
    bool found = false;
    while(i <= n && !found) {
        // binary search
        found = false;
        a = 0;
        b = n + 1;
        c = b/2 + 1;
        while(1) {
            auto res1 = p*i + q*c, res2 = p*i + q*(c-1);
            if(res1 == n) {
                found = true;
                break;
            } else if (a == c){
                break;
            }
            else if(res1 > n && res2 < n) {
                // Con esta i no se puede encontrar
                break;
            } else if (res1 > n) {
                b = c;
                c /= 2;
            } else if (res2 < n) {
                a = c;
                c = c + (b-a)/2;
            }
        }
        if(!found) {
            ++i;
        }
    }
    if(i == n+1) {
        std::cout << "-1" << '\n';
    }
    else {
        //std::cout << i << " " << c << '\n';
        std::cout << i + c << '\n';
        auto itr = 0;
        for(auto t = 0; t < i; ++t, itr += p) {
            std::cout << s.substr(itr, p);
            std::cout << '\n';
        }
        for(auto t = 0; t < c; ++t, itr += q) {
            std::cout << s.substr(itr, q);
            std::cout << '\n';
        }
    }
}

int main()
{
    unsigned int n, p, q;
    std::string s;
	std::cin >> n >> p >> q;
    std::cin >> s;
	computeAnswer(s, n, p, q);
}