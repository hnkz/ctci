#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int num = 1;
    char bef = 0;
    std::string ans;
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

    std::cout << ans << std::endl;
}
