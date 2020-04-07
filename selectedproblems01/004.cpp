#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<vector<ll>> list(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll tmp;scanf("%lld",&tmp);
            list[i].push_back(tmp);
        }
    }
    ll ans=0;
    for(int j=0;j<m-1;j++){
        for(int k=j+1;k<m;k++){
            ll tmp=0;
            for(int i=0;i<n;i++){
                tmp += max(list[i][j],list[i][k]);
                //printf("%lld %lld",list[i][j],list[i][k]);
            }
            ans = max(tmp,ans);
        }
    }
    printf("%lld",ans);
}