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
    ll h,n;cin >> h >> n;
    vector<ll> damage(n);vector<ll> magic(n);
    REP(i,n){
        ll a,b;cin >> a >> b;
        damage[i]=a;magic[i]=b;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(h+1,INF));
    dp[0][0]=0;
    REP(i,n){
        REP(j,h+1){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            dp[i+1][min(j+damage[i],h)]=min(dp[i+1][j]+magic[i],dp[i+1][min(j+damage[i],h)]);
        }
    }
    cout << dp[n][h] << endl;
}