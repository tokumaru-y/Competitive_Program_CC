#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int IINF = 100000000;
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

int n,m;
int dp[1<<15][15];
vector<vector<int>> cost;

int rec(int s, int v){
    if(dp[s][v]!=-1)return dp[s][v];
    if(s == (1<<n)-1 && v == 0){
        return dp[s][v] = 0;
    } 
    int res = IINF;
    REP(u,n){
        if(!(s>>u & 1) && cost[v][u] !=-1){
            res = min(res, rec(s | 1 << u, u) + cost[v][u]);
        }
    }
    return dp[s][v]= res;
}
signed main () {
    scanf("%d %d",&n,&m);
    REP(i,(1<<n))REP(j,n)dp[i][j] = -1;
    cost.assign(n,vector<int>(n,-1));
    REP(i,m){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        cost[a][b] = c;
    }
    int ans = rec(0,0);
    if(ans==IINF)ans = -1;
    printf("%d\n",ans);
}