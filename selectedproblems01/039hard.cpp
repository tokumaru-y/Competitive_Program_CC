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
    int n;scanf("%d",&n);
    vector<vector<ll>> dp(n-1,vector<ll>(21,0));
    vector<int> inlist(n-1);
    int first;scanf("%d",&first);
    REP(i,n-1){
        int tmp;scanf("%d",&tmp);
        inlist[i] = tmp;
    }
    dp[0][first] = 1;
    REP(i,n-2){
        REP(j,21){
            ll sum = 0;
            if(j-inlist[i] >=0) sum += dp[i][j-inlist[i]];
            if(j+inlist[i] <= 20) sum += dp[i][j+inlist[i]];
            dp[i+1][j] = sum;
        }
    }
    printf("%lld\n",dp[n-2][inlist[n-2]]);
}