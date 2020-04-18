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
    vector<vector<int>> grid(n,vector<int>(5));
    REP(i,5){
        REP(j,n){
            char tmp;cin >> tmp;
            int t;
            if(tmp=='R')t=0;
            else if(tmp=='B')t=1;
            else if(tmp=='W')t=2;
            else if(tmp=='#')t=3;
            grid[j][i] = t; 
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(3,INF));
    REP(i,1){
        REP(j,3){
            dp[i][j]=0;
            REP(k,5){
                if(j==grid[i][k])continue;
                dp[i][j]++;
            }
        }
    }

    FOR(i,1,n){
        REP(j,3){
            int tmp=0;
            REP(k,5){
                if(j!=grid[i][k])tmp++;
            }
            REP(h,3){
                if(h==j)continue;
                dp[i][j] = min(dp[i][j], dp[i-1][h]+tmp);
            }
        }
    }
    ll ans = INF;
    REP(i,3)ans=min(ans,dp[n-1][i]);
    printf("%lld\n",ans);
}