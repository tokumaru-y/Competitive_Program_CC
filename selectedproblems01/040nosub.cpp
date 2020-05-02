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
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    vector<int> menu(n,-1);ll mod=10000;
    REP(i,m){
        int a,b;scanf("%d %d",&a,&b);
        a--;b--;
        menu[a]=b;
    }
    dp[0][0]=1;
    REP(i,2){
        if(menu[i]!=-1){
            REP(j,3){
                if(j!=menu[i])continue;
                REP(k,3){
                    dp[i+1][j]+=dp[i][k];
                }
            }
        } else {
            REP(j,3){
                REP(k,3){
                    dp[i+1][j]+=dp[i][k];
                }
            }
        }
    }

    FOR(i,2,n){
        if(menu[i]!=-1){
            REP(j,3){
                if(j!=menu[i])continue;
                REP(k,3){
                    if(k==j)dp[i+1][j]+=dp[i][k]-dp[i-1][k];
                    else dp[i+1][j]+=dp[i][k];
                }
            }
        } else {
            REP(j,3){
                REP(k,3){
                    if(k==j)dp[i+1][j]+=dp[i][k]-dp[i-1][k];
                    else dp[i+1][j]+=dp[i][k];
                }
            }
        }
    }
    REP(i,n+1){
        REP(j,3)cout << dp[i][j];
        cout << endl;
    }
    cout << *max_element(ALL(dp[n]))%mod << endl;
}