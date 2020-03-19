#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    if ( a < 1200) {
        printf("%s", "ABC");
    } else if (a < 2800) {
        printf("%s", "ARC");
    } else { 
        printf("%s", "AGC");
    }
}