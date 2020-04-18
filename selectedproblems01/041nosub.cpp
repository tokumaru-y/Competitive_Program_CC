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
    int n,m;scanf("%d %d",&n,&m);
    vector<int> tmpo(n);
    vector<tuple<int,int,int>> cl(n);
    REP(i,n){
        int tmp;scanf("%d",&tmp);
        tmpo[i] = tmp;
    }
    REP(i,m){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        cl[i] = make_tuple(a,b,c);
    }
    vector<vector<int>> dp(n+1,vector<int>(m,0));
    FOR(i,0,n){
        FOR(j,0,m){
            tuple<int,int,int> tmp = cl[j];
            int a=get<0>(tmp); int b=get<1>(tmp); int c=get<2>(tmp);
            if(tmpo[i] >= a && tmpo[i] <= b){
                REP(h,m){
                    tuple<int,int,int> target = cl[h];
                    int aa=get<0>(target);int bb = get<1>(target);
                    if(i!=0 && !(tmpo[i-1] >= aa && tmpo[i-1] <= bb))continue;
                    int tar =get<2>(target);
                    dp[i+1][j] = max(dp[i+1][j],abs(c-tar) + dp[i][h]);
                }
            }
        }
    }
    int ans=0;
    REP(i,m)ans = max(ans,dp[n][i]);
    printf("%d\n",ans);
}