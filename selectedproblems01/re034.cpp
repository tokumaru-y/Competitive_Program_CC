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

vector<int> dp;
int N;
int calc(int n){
    ll res1,res2;
    dp[n-1]!=-1 ? res1 = dp[n-1] : res1 = calc(n-1);
    dp[n-2]!=-1 ? res2 = dp[n-2] : res2 = calc(n-2);
    return dp[n]=res1 + res2;
}
signed main () {
    scanf("%d",&N);
    dp.assign(N+1,-1);
    dp[0]=1;dp[1]=1;
    if(N-1<1){
        printf("1\n");
        return 0;
    }
    calc(N);
    printf("%d\n",dp[N]);
}