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
    int n,m,k;cin >> n >> m >> k;
    vector<vector<int>> inlist(n,vector<int>(m));
    REP(i,n)REP(j,m)cin >> inlist[i][j];
    int ans=0;
    if(k%2==0){
        REP(i,n)REP(j,m){
            if((i+j)%2==0 && i+j<=k){
                ans=max(ans,inlist[i][j]);
            }
        }
    } else {
        REP(i,n)REP(j,m){
            if((i+j)%2==1 && i+j<=k){
                ans=max(ans,inlist[i][j]);
            }
        }
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/arc023/tasks/arc023_2