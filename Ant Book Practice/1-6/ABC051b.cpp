#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    int k,s;scanf("%d %d",&k,&s);
    int ans=0;
    for(int i=0;i<=k;i++){
        if(i>s) continue;
        if(i==s){
            ans++;
            continue;
        }
        for(int j=0;j<=k;j++){
            if(i+j>s || s-i-j>k)continue;
            ans++;
        }
    }
    printf("%d",ans);
}