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
    int n;scanf("%d",&n);
    vector<ll> x(n);vector<ll> y(n);
    REP(i,n){
        ll tmpx,tmpy;
        scanf("%lld %lld",&tmpx,&tmpy);
        x[i] = tmpx;y[i] = tmpy;
    }
    ll ans = INF;
    REP(i,n){
        REP(j,n){
            ll disx = x[i];ll disy = y[j];
            ll tmp = 0;
            REP(k,n){
                tmp += abs(x[k] - disx) + abs(x[k] - y[k]) + abs(disy - y[k]);
            }
            ans = min(ans,tmp);
        }
    }
    printf("%lld",ans);
}