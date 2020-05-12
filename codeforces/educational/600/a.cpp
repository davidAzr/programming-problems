// Extract numbers
// https://codeforces.com/contest/600/problem/A

#include <iostream>
#include <math.h>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>

bool isDigit(const char& c) {
    if (c >= '0' && c <= '9') return true;
    else return false;
}

void computeAnswer(const std::string& input) {
    std::string nextToken, a, b;
    bool isWord = false, first = true;
    for(const auto& c : input) {
        if (c == ',' || c == ';') {
            if((isWord || nextToken.size() == 0) && nextToken != "0") {
                b.append(nextToken);
                b.append(",");
            } else {
                a.append(nextToken);
                a.append(",");
            }
            nextToken = "";
            isWord = false;
            first = true;
        } else {
            nextToken += c;
            if(isWord) continue;
            else if(first && isDigit(c)) {
                if(c == '0') isWord = true;
                first = false;
            } else {
                if(!isDigit(c)) {
                    isWord = true;
                    continue;
                }
            }
        }
    }
    if((isWord || nextToken.size() == 0) && nextToken != "0") {
        b.append(nextToken);
        b.append(",");
    } else {
        a.append(nextToken);
        a.append(",");
    }

    if(a.size() > 0) {
        std::cout << "\"" + a.substr(0, a.size() - 1) + "\"" << '\n';    
    } else {
        std::cout << "-" << '\n';
    }
    if(b.size() > 0) {
        std::cout << "\"" + b.substr(0, b.size() - 1) + "\"" << '\n';    
    } else {
        std::cout << "-" << '\n';
    }
}

int main()
{
	std::string input;
	std::cin >> input;
	computeAnswer(input);
}