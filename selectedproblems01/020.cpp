#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
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
    vector<ll> first(n);vector<ll> mid(n);vector<ll> bottom(n);
    REP(i,n){
        ll tmp;scanf("%lld",&tmp);
        first[i]=tmp;
    }
    REP(i,n){
        ll tmp;scanf("%lld",&tmp);
        mid[i]=tmp;
    }
    REP(i,n){
        ll tmp;scanf("%lld",&tmp);
        bottom[i]=tmp;
    }
    sort(ALL(first));sort(ALL(bottom));
    ll ans=0;
    for(int i=0;i<n;i++){
        ll t = mid[i];
        auto f = lower_bound(ALL(first),t);
        auto b = upper_bound(ALL(bottom),t);
        if (b == bottom.end() || f== first.begin())continue;
        ans +=  (f-first.begin()) * (bottom.end() - b); 
    }
    printf("%lld",ans);
}