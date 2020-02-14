#include <iostream>
#include <iostream>

bool replace(std::string s1, std::string s2) {
    bool op = false;
    for(auto i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) {
            if(op) {
                return false;
            }
            op = true;
        }
    }
    return true;
}

bool edit(std::string s1, std::string s2) {
    int ia = 0;
    int ib = 0;
    while(ia < s1.size() && ib < s2.size()) {
        if(s1[ia] != s2[ib]) {
            if(ia != ib) {
                return false;
            }
            ib += 1;
        } else {
            ia += 1;
            ib += 1;
        }
    }
    return true;
}

bool solve1(std::string s1, std::string s2) {
    if(s1.size() == s2.size()) {
        return replace(s1, s2);
    } else if(s1.size()+1 == s2.size()) {
        return edit(s1, s2);
    } else if(s1.size() == s2.size()+1) {
        return edit(s2, s1);
    }
    return false;
}


int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if(solve1(s1, s2))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}
