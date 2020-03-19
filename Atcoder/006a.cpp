#include <bits/stdc++.h>
using namespace std;
int main () {
    string a;cin >> a;
    int num = atoi(a.c_str());
    if(a.find("3") == string::npos && num%3!=0) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}