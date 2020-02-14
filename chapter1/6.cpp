#include <iostream>
#include <string>
#include <deque>
#include <chrono>

class StringBuilder {
    std::deque<std::string> d;
    std::string::size_type size;
public:
    StringBuilder(const std::string &s) {
        if(!s.empty()) {
            d.push_back(s);
        }
        size += s.length();
    }
    
    void append(const std::string &s) {
        if(!s.empty()) {
            d.push_back(s);
        }
        size += s.length();
    }

    void append(const char &c) {
        const std::string s(1, c);
        d.push_back(s);
        size += 1;
    }

    std::string toString() const {
        std::string result;
        result.reserve(size + 1);
        for(auto iter = d.begin(); iter != d.end(); iter++) {
            result += *iter;
        }
        return result;
    }

};

void solve1(std::string s) {
    int num = 1;
    char bef = 0;
    StringBuilder ans = StringBuilder("");
    for(int i = 0 ; i < s.size(); i++) {
        if(bef == s[i]) {
            num += 1;
        } else {
            if(num == 1) {
                ans.append(bef);
            } else {
                ans.append(bef);
                ans.append(std::to_string(num));
                num = 1;
            }
        }
        bef = s[i];
    }

    if(num == 1) {
        ans.append(bef);
    } else {
        ans.append(bef);
        ans.append(std::to_string(num));
    }

}

void solve2(std::string s) {
    int num = 1;
    char bef = 0;
    std::string ans = "";
    for(int i = 0 ; i < s.size(); i++) {
        if(bef == s[i]) {
            num += 1;
        } else {
            if(num == 1) {
                ans += bef;
            } else {
                ans += bef;
                ans += std::to_string(num);
                num = 1;
            }
        }
        bef = s[i];
    }

    if(num == 1) {
        ans += bef;
    } else {
        ans += bef;
        ans += std::to_string(num);
    }
}

int main() {
    std::string s;
    std::cin >> s;

    std::chrono::system_clock::time_point start1 = std::chrono::system_clock::now();
    solve1(s);
    std::chrono::system_clock::time_point end1 = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point start2 = std::chrono::system_clock::now();
    solve2(s);
    std::chrono::system_clock::time_point end2 = std::chrono::system_clock::now();

    std::cout << "StringBuilder = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1-start1).count() << "msec.\n";
    std::cout << "string        = " << std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2).count() << "msec.\n";
}
