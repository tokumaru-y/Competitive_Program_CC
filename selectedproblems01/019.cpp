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
    ll d;scanf("%lld",&d);
    ll n;scanf("%lld",&n);
    ll m;scanf("%lld",&m);
    ll ans=0;
    vector<ll> shop(n);
    shop[0]=0;
    for(int i=1;i<n;i++){
        ll tmp;scanf("%lld",&tmp);
        shop[i]= tmp;
    }
    sort(ALL(shop));
    REP(i,m){
        ll tmp;scanf("%lld",&tmp);
        if(binary_search(ALL(shop),tmp))continue;
        auto itr = upper_bound(ALL(shop),tmp);
        if(itr==shop.end()){
            ll dif1 = d - tmp;
            --itr;
            ll dif2 = tmp - *itr;
            ans+= min(dif1,dif2);
        } else {
            ll dif1=*itr - tmp;
            --itr;
            ll dif2 = tmp - *itr;
            ans += min(dif1,dif2);
        }
    }
    printf("%lld\n",ans);
}