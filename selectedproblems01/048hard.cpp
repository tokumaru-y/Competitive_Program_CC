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
int n;
vector<int> weight;
vector<vector<int>> dp;
int rec(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(abs(l-r)<=1)return 0;
    int res = 0;
    if(abs(weight[l] - weight[r-1])<=1 && rec(l+1,r-1) == r - l - 2){
        res = r-l;
    }
    for(int mid=l+1;mid<=r-1;mid++){
        res = max(res, rec(l,mid) + rec(mid,r));
    }
    return dp[l][r] = res;
}
signed main () {
    scanf("%d",&n);
    while(n!=0){
        weight.assign(n,-1);
        REP(i,n){
            int tmp;scanf("%d",&tmp);
            weight[i]= tmp;
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        rec(0,n);
        printf("%d\n",dp[0][n]);
        scanf("%d",&n);
    }
}