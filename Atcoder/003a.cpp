#include <bits/stdc++.h>
using namespace std;
int main () {
    int a;scanf("%d",&a);
    int ans=0;
    for(int i=1;i<=a;i++){
        ans += 10000 * i;
    }
    printf("%d",ans/a);
}