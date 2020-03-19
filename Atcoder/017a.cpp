#include <bits/stdc++.h>
using namespace std;
int main () {
    int ans=0;
    for(int i=0;i<3;i++){
        int a,b;scanf("%d %d",&a,&b);
        ans += a * b / 10;
    }
    printf("%d\n",ans);
}