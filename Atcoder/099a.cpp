#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if((n >= 999 && n - (999 * (n/999)) >= 1) || n == 1998) {
        printf("%s", "ABD");
    } else {
        printf("%s", "ABC");
    }
}