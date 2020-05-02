#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    ll k,n;scanf("%lld %lld",&k,&n);
    vector<ll> list(n);vector<ll> diff(n);
    REP(i,n){
        ll tmp;scanf("%lld",&tmp);
        list.at(i)= tmp;
        if(i >=1){
            diff.at(i-1) = list[i] - list[i-1];
        }
    }
    diff.at(n-1) = k - list[n-1];
    sort(diff.begin(), diff.end());
    ll ans = accumulate(diff.begin(), diff.end()-1,0);
    printf("%lld", ans);

}