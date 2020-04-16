#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<int> coins(m);
    REP(i,m){
        int tmp;scanf("%d",&tmp);
        coins[i] =tmp;
    }
    vector<ll> dp(n+1,INF);
    dp[0]=0;
    FOR(i,0,m){
        FOR(j,0,n+1){
            if(j-coins[i] >= 0)dp[j] = min(dp[j],dp[j-coins[i]] + 1);
        }
    }
    printf("%lld\n",dp[n]);
}