#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    ll a,b,k;scanf("%lld %lld %lld",&a,&b,&k);
    if(a>=k){
        a -= k;
    } else {
        k -= a;
        a = 0;
        b < k ?b = 0 : b -= k;
    }
    printf("%lld %lld",a,b);
}