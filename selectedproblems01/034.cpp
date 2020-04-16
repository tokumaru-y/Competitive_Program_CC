#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
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

vector<int> dp;
int fib(int t){
    if(dp[t]!=-1)return dp[t];
    int res1,res2;
    dp[t-1]!=-1 ? res1 = dp[t-1] : res1=fib(t-1);
    dp[t-2]!=-1 ? res2 = dp[t-2] : res2=fib(t-2);
    dp[t]=res1+res2;
    return dp[t];
}
signed main () {
    int n;scanf("%d",&n);
    dp.assign(n+1,-1);
    dp[0]=1;dp[1]=1;
    fib(n);
    printf("%d\n",dp[n]);
    
}