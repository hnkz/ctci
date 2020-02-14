#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>


bool solve2(std::string s) {
    std::bitset<128> bs(0);
    for(char &c: s) {
        int index = (int)c;
        if(bs[index]) {
            return false;
        } else {
            bs[index] = 1;
        }
    }
    return true;
}

bool solve1(std::string s) {
    std::sort(s.begin(), s.end());
    bool ans = true;
    char bef = s[0];
    for(auto i = 1; i < s.size(); i++) {
        if(bef == s[i]) {
            ans = false;
            break;
        }
        bef = s[i];
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    if(solve2(s)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

}
