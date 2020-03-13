#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[4];
    for(int i=0;i<4;i++){
        scanf("%d", &a[i]);
    }
    int x=a[1];int y=a[3];
    if(a[0] <= a[1]) {
        x = a[0];
    }
    if(a[2] <= a[3]) {
        y = a[2];
    }
    printf("%d", x+y);
}