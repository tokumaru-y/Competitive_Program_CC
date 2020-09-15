#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;

signed main () {
    int n,m;cin >> n >> m;
    vector<ll> list(n);
    REP(i,n)cin >> list[i];
    sort(ALL(list));
    ll ans=0;
    REP(i,m){
        ans+=list[i];
    }
    cout << ans << endl;
}