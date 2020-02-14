#include <iostream>
#include <iostream>

bool replace(std::string s1, std::string s2) {
    bool op = false;
    for(auto i = 0; i < s1.length(); i++) {
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
    while(ia < s1.length() && ib < s2.length()) {
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

bool solve2(std::string first, std::string second) {
    if(first.length() - second.length() > 1) {
        return false;
    }
    int ia = 0;
    int ib = 0;

    std::string s1 = first.length() > second.length() ? second : first;
    std::string s2 = first.length() > second.length() ? first : second;

    bool operated = false;
    while(ia < s1.length() && ib < s2.length()) {
        if(s1[ia] != s2[ib]) {
            if(operated) return false;
            operated = true;
            if(s1.length() == s2.length()) {
                ia += 1;
            }
        } else {
            ia += 1;
        }
        ib += 1;
    }
    return true;
}

bool solve1(std::string s1, std::string s2) {
    if(s1.length() == s2.length()) {
        return replace(s1, s2);
    } else if(s1.length()+1 == s2.length()) {
        return edit(s1, s2);
    } else if(s1.length() == s2.length()+1) {
        return edit(s2, s1);
    }
    return false;
}


int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if(solve2(s1, s2))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}
