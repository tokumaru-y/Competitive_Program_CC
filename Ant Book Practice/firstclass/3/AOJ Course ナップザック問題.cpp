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
    int n,w;cin >> n >> w;
    vector<ll> width(n);vector<ll> value(n);
    REP(i,n){
        ll a,b;cin >> a >> b;
        width[i] = b;value[i]=a;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(w+1,0));
    REP(i,n){
        ll origin=width[i];
        REP(j,w+1){
            if(j-origin>=0){
                dp[i+1][j]=max(dp[i][j],dp[i+1][j-origin] + value[i]);
            } else {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            }
        }
    }
    cout << dp[n][w] << endl;
}