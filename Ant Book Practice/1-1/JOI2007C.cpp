#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    int n;ll m;scanf("%d %lld",&n,&m);
    vector<ll> list={};
    vector<ll> list2 = {};
    REP(i,n) {
        ll tmp;scanf("%lld",&tmp);
        list.push_back(tmp);
        list2.push_back(tmp);
    }
    ll ans = 0;
    REP(i,n){
        REP(j,n) {
            list2.push_back(list[i] + list[j]);
        }
    }
    sort(list2.begin(), list2.end());
    REP(i,n){
        if (list[i] > m) continue;
        REP(j,n){
            ans < list[i] ? ans = list[i] : ans = ans;
            if(list[i] + list[j] > m) continue;
            ans < list[i] + list[j] ? ans =list[i] + list[j] : ans = ans;
            auto iter = upper_bound(list2.begin(), list2.end(), m - list[i] - list[j]);
            if (iter == list2.end()) continue;
            iter--;
            if(list[i] + list[j] + *iter <= m){
                ans < list[i] + list[j] + *iter ? ans = list[i] + list[j] + *iter :ans = ans;
            }
        }
    }
    printf("%lld\n", ans);
}