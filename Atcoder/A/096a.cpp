#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    int ans = a;
    if (a > b){
        ans--;
    }
    printf("%d",ans);
}