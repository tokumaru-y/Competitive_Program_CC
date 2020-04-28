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
    ll h,w,cost,money;scanf("%lld %lld %lld %lld",&h,&w,&cost,&money);
    vector<vector<ll>> list(h+1,vector<ll>(w+1,0));
    vector<vector<ll>> sl(h+1,vector<ll>(w+1,0));
    REP(i,h)REP(j,w){
        cin >> list[i][j];
    }
    REP(i,h)REP(j,w){
        sl[i+1][j+1]=sl[i][j+1]+sl[i+1][j]-sl[i][j]+list[i][j];
    }
    ll ans =0;
    FOR(hi,1,h+1)FOR(wi,1,w+1){
        REP(i,hi+1)REP(j,wi+1){
            ll numsum = sl[hi][wi] - sl[i][wi] - sl[hi][j] + sl[i][j];
            ll mathcnt = (hi-i)*(wi-j);
            ll total = numsum + mathcnt*cost;
            if(total<=money){
                ans=max(ans,mathcnt);
            }
        }
    }
    printf("%lld\n",ans);
}