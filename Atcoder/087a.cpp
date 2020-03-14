#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    int ans = (a - b) % c;
    printf("%d", ans);
}