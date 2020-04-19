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
vector<vector<ll>> dp(2100,vector<ll>(2100,-1));
int b[2100];
int a;
ll calc(int l, int r, int s){
    if(~dp[l][r])return dp[l][r];
    if(l==r){
        if(s)return dp[l][r]=0;
        return dp[l][r]=b[l];
    }
    if(s){
        if(b[l] > b[r]){
            return dp[l][r] = calc((l+1)%a,r,0);
        } else {
            return dp[l][r]= calc(l,(r+a-1)%a,0);
        }
    }
    return dp[l][r] = max(calc((l+1)%a,r,1)+b[l], calc(l,(r+a-1)%a,1)+b[r]);
}
signed main () {
    scanf("%d ",&a);
    REP(i,a)scanf("%d",b+i);
    ll ret = 0;
    REP(i,a){
        ret = max(ret,calc((i+1)%a,(i+a-1)%a,1)+b[i]);
    }
    printf("%lld\n",ret);
}