#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int IINF=100000000;
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
vector<vector<int>> dp;vector<vector<int>> cost;
vector<vector<int>> timetable;
int n,m;
int rec(int s,int v,int t){
    if(dp[s][v]!= -1)return dp[s][v];
    if(s==(1<<n)-1 && v==0)return dp[s][v]=0;
    int res = IINF;
    REP(u,n){
        if(!(s>>u & 1) && (cost[v][u] !=IINF) && timetable[v][u] >= t){
            res = min(res, rec(s|(1<<u),u,t+1)+cost[v][u]);
        }
    }
    return dp[s][v]=res;
}
signed main () {
    scanf("%d %d",&n,&m);
    dp.assign((1<<n), vector<int>(n,-1));
    cost.assign(n,vector<int>(n,IINF));
    timetable.assign(n,vector<int>(n,IINF));
    REP(i,m){
        int a,b,c,d;scanf("%d %d %d %d",&a,&b,&c,&d);
        cost[a-1][b-1] = c;cost[b-1][a-1]=c;
        timetable[a-1][b-1]=d;timetable[b-1][a-1]=d;
    }
    int cnt=0;
    int ans=IINF;
    REP(i,1<<n){
    //dp.assign((1<<n), vector<int>(n,-1));
        int pre = ans;
        if(cost[0][i] != IINF){
            ans = min(ans, rec(0,i,0));
        }
        if(ans==pre){
            cnt++;
        } else {
            cnt = 1;
        }
    }
    if(ans==IINF){
        printf("IMPOSSIBLE\n");
        return 1;
    }
    printf("%d %d\n",ans,cnt);
}