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
    while(n!=0 && m!=0){
        vector<int> cb(m);
        REP(i,m){
            int tmp;scanf("%d",&tmp);
            cb[i]=tmp;
        }
        vector<int> list(n);
        REP(i,n){
            int tmp;scanf("%d",&tmp);
            list[i] = tmp;
        }
        vector<vector<ll>> dp(n+1,vector<ll>(256,INF));
        dp[0][128]=0;
        REP(i,n){
            REP(j,256){
                if(dp[i][j]==INF)continue;
                REP(l,m){
                    int y = j+cb[l];
                    if(y<0)y = 0;
                    if(y>255)y = 255;
                    int sum = (list[i]-y)*(list[i]-y);
                    dp[i+1][y]=min(dp[i+1][y], dp[i][j] + sum );
                }
            }
        }
        cout << *min_element(dp[n].begin(),dp[n].end()) << endl;
        scanf("%d %d",&n,&m);
    }

}