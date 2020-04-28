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

signed main () {
    int n,m,q;scanf("%d %d %d",&n,&m,&q);
    vector<vector<int>> list(n+1,vector<int>(n+1,0));
    REP(i,m){
        int l,r;scanf("%d %d",&l,&r);
        list[l][r]++;
    }
    vector<vector<int>> cnt(n+1,vector<int>(n+1,0));
    FOR(i,1,n+1)FOR(j,1,n+1)list[i][j]+=list[i-1][j];
    FOR(i,1,n+1)FOR(j,1,n+1)list[i][j]+=list[i][j-1];
    REP(i,q){
        int l,r;scanf("%d %d",&l,&r);
        int ans=list[r][r] -list[l-1][r]-list[r][l-1]+list[l-1][l-1];
        printf("%d\n",ans);
    }
}