#include <bits/stdc++.h>
using namespace std;
int main () {
    char s[4];
    scanf("%s", s);
    bool first = (s[0] == s[1] && s[1] == s[2]);
    bool second = (s[1] == s[2] && s[2] == s[3]);
    if (first || second) {
        printf("%s", "Yes");
    }  else {
        printf("%s", "No");
    }
}