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
    REP(i,n){
        string a,b;cin >> a >> b;
        int al = a.length();int bl = b.length();
        vector<vector<int>> dp(al+1,vector<int>(bl+1,0));
        REP(i,al){
            REP(j,bl){
                if(a[i] == b[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                }
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
            }
        }
        printf("%d\n",dp[al][bl]);
    }
}