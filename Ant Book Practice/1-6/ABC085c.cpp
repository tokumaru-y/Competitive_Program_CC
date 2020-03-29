#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    int n,y;scanf("%d %d",&n,&y);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            if(10000*i + 5000*j + 1000*(n-i-j) == y){
                printf("%d %d %d",i,j,n-i-j);
                return 0;
            }
        }
    }
    printf("-1 -1 -1");
}