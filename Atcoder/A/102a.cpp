#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    int ans ;
    if(a%2==0){
        ans = a;
    } else {
        ans = a *2;
    }
    printf("%d",ans);
}