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
    ll n,k;cin >> n >> k;
    vector<ll> days(n);
    REP(i,n)cin >> days[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
    ll passedsum=0;
    dp[0][0]=0;
    dp[1][0]=0;dp[1][1]=1;
    //passedsum+=days[0];
    for(int i=0;i<n;i++){
        if(i>0){
            for(int j=0;j<i+1;j++){
                if(dp[i][j]==INF)continue;
                ll tmp = ((dp[i][j]*days[i])/passedsum)+1;
                if(tmp <= days[i]){
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+tmp);
                }
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            }
        }
        passedsum+=days[i];
    }
    if(passedsum==k){
        cout << 1 << endl;
    } else {
        for(int j=n;j>=0;j--){
            if(dp[n][j]<=k){
                cout << j << endl;
                return 0;
            }
        }
    }
}