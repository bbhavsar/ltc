#include "common.hh"

#include <cctype>



bool isPalindrome(string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [] (char c) {return !isalnum(c); } ), s.end());

    for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
    }

    return true;
}

int main() {

    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;

    return 0;
}



