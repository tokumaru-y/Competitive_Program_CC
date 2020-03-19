#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf("%d",&n);
    int div = n /15;
    printf("%d", n * 800 - (200*div));
}