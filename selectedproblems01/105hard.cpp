#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    ll n,k,l,r;cin >> n >> k >> l >> r;
    vector<ll> list(n);
    REP(i,n)cin >> list[i];
    ll ind = n/2;
    vector<vector<ll>> firsthalf(ind+1,vector<ll>());
    vector<vector<ll>> secondhalf(n-ind+1,vector<ll>());
    for(ll i=0;i<(1<<ind);i++){
        ll cnt=0;ll value=0;
        for(ll j=0;j<ind;j++){
            if(i >> j & 1)value+=list[j],cnt++;
        }
        firsthalf[cnt].push_back(value);
    }
    for(ll i=0;i<(1<<n-ind);i++){
        ll cnt=0;ll value=0;
        for(ll j=0;j<n-ind;j++){
            if(i >> j & 1)value+=list[ind+j],cnt++;
        }
        secondhalf[cnt].push_back(value);
    }
    REP(i,ind)sort(ALL(firsthalf[i]));
    ll ans=0;
    for(ll i=max(k-ind,(ll)0);i<min(k,n-ind)+1;i++){
        vector<ll> target = secondhalf[i];
        for(int j = 0;j<target.size();j++){
            ll res = (ll)(upper_bound(ALL(firsthalf[k-i]),r-target[j]) - lower_bound(ALL(firsthalf[k-i]),l-target[j]));
            ans += res;
        }
    }
    cout << ans << endl;
}