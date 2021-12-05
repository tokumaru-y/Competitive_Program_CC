// https://atcoder.jp/contests/abc085/tasks/abc085_c
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
    int N,Y;cin >> N >> Y;
    REP(i,N+1)REP(j,N+1){
        ll left = Y - (i*(10000) + j*(5000));
        if (left%1000 != 0)continue;
        if (left >= 0 && i+j+(left/1000) == N){
            cout << i << " " << j << " " << left/1000 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}