#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    long long w;scanf("%lld",&w);
    int ans=0;
    if(b<=w &&w<=c){   
        ans++;
    }
    for(int i=0;i<a-1;i++){
        long long tmp ;
        scanf("%lld",&tmp);
        w+=tmp;
        if(b<=w &&w<=c){   
            ans++;
        }
    }
    printf("%d\n",ans);
}