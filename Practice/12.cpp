// https://atcoder.jp/contests/abc175/tasks/abc175_b
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int L;
    cin >> L;
    vector<ll> A(L);
    REP(i,L)cin >> A[i];
    int ans = 0;
    REP(i,L)FOR(j,i+1,L)FOR(k,j+1,L){
        ll x=A[i], y=A[j],z=A[k];
        if (x == y || y == z || z == x)continue;
        if (x+y>z && y+z>x && x+z>y)ans++;
    }
    cout << ans << endl;
}