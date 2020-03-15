#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int number = a * 100 + b *10 + c;
    if (number %4 == 0) {
        printf("%s", "YES");
    } else {
        printf("%s", "NO");
    }
} 