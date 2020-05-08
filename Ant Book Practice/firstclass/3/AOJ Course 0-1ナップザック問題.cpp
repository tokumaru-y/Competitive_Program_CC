#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
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
vector<vector<int>> goods;
signed main () {
    cin >> n >> w;
    goods.assign(n,vector<int>());
    REP(i,n){
        int a,b;cin >> a >> b;
        goods[i]={a,b};
    }
    vector<vector<ll>> dp(n+1,vector<ll>(10001,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(j-goods[i][1]>=0){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-goods[i][1]]+goods[i][0]);
            }
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
    }
    cout << *max_element(ALL(dp[n])) << endl;
}