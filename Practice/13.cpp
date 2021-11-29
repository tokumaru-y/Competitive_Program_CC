// https://atcoder.jp/contests/arc013/tasks/arc013_1
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
    vector<int> X(3,-1);
    vector<int> Y(3,-1);
    REP(i,3)cin >> X[i];
    REP(i,3)cin >> Y[i];
    sort(ALL(Y));
    int ans = 0;
    do {
        int cnt = 1;
        REP(i,3)cnt *= X[i] / Y[i];
        ans = max(ans, cnt);
    } while(next_permutation(Y.begin(), Y.end()));
    cout << ans << endl; 
}