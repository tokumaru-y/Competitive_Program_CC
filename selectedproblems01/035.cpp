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
int n,w;
vector<vector<int>> dp;
vector<pair<int,int>> goods;
signed main () {
    scanf("%d %d",&n,&w);
    dp.assign(n+1,vector<int>(w+1,0));
    goods.assign(n,pair<int,int>());
    REP(i,n){
        int a,b;scanf("%d %d",&a,&b);
        pair<int,int> tmp = make_pair(a,b);
        goods[i]=tmp;
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(goods[i].second<=j){
                dp[i+1][j]=max(dp[i][j],dp[i][j-goods[i].second]+goods[i].first);
            }
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
    }
    printf("%d\n",dp[n][w]);
}