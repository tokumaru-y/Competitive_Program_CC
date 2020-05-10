#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
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
    int n,m,x; cin >> n >> m >> x;
    vector<ll> cost(n);
    vector<vector<ll>> list(n,vector<ll>(m));
    REP(i,n){
        cin >> cost[i];
        REP(j,m)cin >> list[i][j];
    }
    ll ans= INF;
    for(int i=0;i<(1<<n);i++){
        vector<ll> suml(n,0);
        ll tmpcnt = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                tmpcnt+=cost[j];
                REP(s,m){
                    suml[s]+=list[j][s];
                }
            }
        }
        bool flag =true;
        REP(t,m){
            if(suml[t]<x){flag=false;}
        }
        if(flag)ans=min(ans,tmpcnt);
    }
    if(ans==INF)ans = -1;
    cout << ans << endl;
}