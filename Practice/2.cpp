// https://atcoder.jp/contests/arc056/tasks/arc056_a
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
    ll A,B,K,L;
    cin >> A >> B >> K >> L;
    ll ans = INF;
    ll tmp = min((K/L) * B + B, (K/L) * B + (K%L) * A);
    ans = min(A*K, tmp);
    cout << ans << endl;
}