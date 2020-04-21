#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
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
int n,m;
signed main () {
    scanf("%d %d",&n,&m);
    vector<vector<ll>> dp(n,vector<ll>(n,INF));
    REP(i,n)dp[i][i] = 0;
    REP(i,m){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        a--;b--;
        dp[a][b]=c;dp[b][a]=c;
    }
    REP(k,n){
        REP(i,n){
            REP(j,n){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    vector<ll> ans(n,0);
    REP(i,n){
        REP(j,n){
            ans[i]=max(ans[i], dp[i][j]);
        }
    }
    ll outans = *min_element(ALL(ans));
    printf("%lld\n",outans);
}