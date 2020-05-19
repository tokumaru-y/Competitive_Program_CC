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
    ll n,s,k;cin >> n >> s >> k;
    s -= n*(n-1)*k/2;
    if(s<0) {
        cout << 0 << endl;return 0;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
    dp[0][0]=1;
    FOR(i,1,n+1){
        REP(j,s+1){
            if(j-i>=0)dp[i][j]=dp[i][j-i]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }
    cout << dp[n][s] << endl;
}
//https://yukicoder.me/problems/no/269