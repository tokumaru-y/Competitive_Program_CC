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
    int n,w,k;cin >> w;
    cin >> n >> k;
    vector<ll> width(n);vector<ll> cost(n);
    REP(i,n)cin >> width[i] >> cost[i];
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(w+1,vector<ll>(k+1,0)));
    REP(i,n){
        REP(j,w+1){
            REP(s,k){
                int ind=j-width[i];
                if(ind>=0){
                    dp[i+1][j][s+1]=max(dp[i+1][j][s+1],dp[i][ind][s]+cost[i]);
                }
                dp[i+1][j][s+1]=max({dp[i+1][j][s+1],dp[i][j][s],dp[i][j][s+1],dp[i+1][j][s]});
            }
        }
    }
    cout << *max_element(ALL(dp[n][w])) << endl;
}