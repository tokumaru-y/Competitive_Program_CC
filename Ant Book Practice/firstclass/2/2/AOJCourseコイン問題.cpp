#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
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
int ans=100000;
int calc(int target, int &left){
    int k = left/target;
    left -= target * k;
    return k;
}
signed main () {
    int n,m;cin >> n >> m;
    vector<int> coins(m);
    REP(i,m)cin >> coins[i];sort(ALL(coins));
    vector<ll> dp(n+1,100000);dp[0]=0;
    REP(i,n+1){
        for(int c : coins){
            if(c>i)continue;
            dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    cout << dp[n] << endl;
}
