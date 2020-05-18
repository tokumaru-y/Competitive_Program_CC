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
    int n,m,l,x;cin >> n >> m >> l >> x;
    vector<vector<int>> dp(n+1,vector<int>(m,10001));
    REP(i,n+1)dp[i][0]=1;
    REP(i,n){
        int gas ;cin >> gas;
        REP(j,m){
            int bef = (j+gas)%m;
            dp[i+1][bef]=min(dp[i][j]+(j+gas)/m,dp[i][bef]);
        }
    }
    if(dp[n][l]<x){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}