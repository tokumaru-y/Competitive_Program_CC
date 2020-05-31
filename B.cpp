#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;

signed main () {
    ll n;cin >> n;
    ll ans = 1;
    ll limit = 1e+18;
    vector<ll> inlist(n);
    REP(i,n){
        ll tmp;cin >> tmp;
        inlist[i]=tmp;
        if(tmp==0){
            cout << 0 << endl;
            return 0;
        }
    }
    for(ll a : inlist){
        if(ans<=limit/a){
            ans *=a;
        } else {
            cout << -1 << endl;return 0;
        }
    }
    cout << ans << endl;
}