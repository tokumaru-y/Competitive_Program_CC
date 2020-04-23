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
    SCANF(n);
    vector<ll> list(n);
    REP(i,n){
        ll t;scanf("%lld",&t);
        list[i]=t;
    }
    vector<ll> cum(n+1,0);
    FOR(i,1,n+1){
        cum[i] = list[i-1] + cum[i-1];
    }
    FOR(k,0,n){
        ll ans=0;
        FOR(i,1,n+1){
            ll tmp=0;
            tmp = cum[i] - cum[i-k-1];
            ans = max(ans,tmp);
        }
        printf("%lld\n",ans);
    }
}