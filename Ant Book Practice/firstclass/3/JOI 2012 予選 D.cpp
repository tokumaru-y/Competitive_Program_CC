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

signed main () {
    int n,d;cin >> n >> d;
    vector<int> tem(n);vector<int> mintemp(d);vector<int> maxtemp(d);vector<int> points(d);
    REP(i,n)cin >> tem[i];
    REP(i,d)cin >> mintemp[i] >> maxtemp[i] >> points[i];
    vector<vector<int>> dp(n+1,vector<int>(d,0));
    //REP(i,d)if(tem[0]>=mintemp[i] && tem[0]<=maxtemp[i])dp[1][i]=points[i];
    FOR(i,1,n){
        REP(j,d){
            if(tem[i]<mintemp[j] || tem[i]>maxtemp[j]){
                continue;
            }
            REP(l,d){
                if(tem[i-1] < mintemp[l] || tem[i-1]>maxtemp[l])continue;
                dp[i][j]=max(dp[i][j],dp[i-1][l]+abs(points[l]-points[j]));
            }
        }
    }
    cout << *max_element(ALL(dp[n-1])) << endl;
}