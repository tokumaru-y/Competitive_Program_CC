#include <bits/stdc++.h>
using namespace std;
int main () {
    int x[3];
    scanf("%d %d %d",&x[0],&x[1],&x[2]);
    sort(x,x+3);
    printf("%d\n",x[1]);
}