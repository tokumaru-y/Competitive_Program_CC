// https://atcoder.jp/contests/abc040/tasks/abc040_c
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int N;
    cin >> N;
    vector<ll> A(N,INF);
    REP(i,N)cin >> A[i];
    vector<ll> dp(N+1, INF);
    dp[0] = 0;
    dp[1] = 0;
    for(int i=1;i<N;i++){
        dp[i+1] = min(dp[i] + abs(A[i] - A[i-1]), dp[i+1]);
        if (i-2>=0)dp[i+1] = min(dp[i-1] + abs(A[i] - A[i-2]), dp[i+1]);
    }
    cout << dp[N] << endl;
}