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
    ll n,m;cin >> n >> m;
    vector<vector<vector<ll>>> dp(102,vector<vector<ll>>(102,vector<ll>(102,0)));
    REP(i,n){
        ll a,b,c,w;cin >> a >> b >> c >> w;
        dp[a][b][c]=max(w,dp[a][b][c]);
    }
    REP(i,101)REP(j,101)REP(s,101){
        dp[i+1][j][s]=max(dp[i+1][j][s],dp[i][j][s]);
        dp[i][j+1][s]=max(dp[i][j+1][s],dp[i][j][s]);
        dp[i][j][s+1]=max(dp[i][j][s+1],dp[i][j][s]);
    }
    REP(i,m){
        ll a,b,c;cin >> a >> b >> c;
        cout << dp[a][b][c] << endl;
    }
}