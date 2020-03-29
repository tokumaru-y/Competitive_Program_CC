#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    int n,k,m;scanf("%d %d %d",&n,&k,&m);
    int suma = 0;
    REP(i,n-1){
        int tmp;scanf("%d",&tmp);
        suma += tmp;
    }
    int ans=-1;
    for(int i = k;i>=0;i--){
        if((suma + i)/n >= m){
            ans = i;
        }
    }
    printf("%d",ans);
}