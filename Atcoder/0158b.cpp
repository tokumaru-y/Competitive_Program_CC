#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    ll n,a,b;scanf("%lld %lld %lld",&n,&a,&b);
    ll div = n / (a+b);ll mod = n %(a+b);
    ll ans = div * a;
    if (mod <= a){
        ans+=mod;
    } else {
        ans += a;
    }
    printf("%lld",ans);
}