//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int )= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    while (true){
        int n,x;scanf("%d %d",&n,&x);
        if(n==0&&x==0)break;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(i+j+k==x)ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}