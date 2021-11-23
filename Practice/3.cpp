// https://atcoder.jp/contests/arc099/tasks/arc099_a
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
    int N,K;
    cin >> N >> K;
    vector<int> A(N,-1);
    REP(i,N)cin >> A[i];
    sort(ALL(A));
    A.erase(unique(ALL(A)), A.end());
    int s = (int)A.size() - 1;
    int ans = s / (K-1);
    if (s%(K-1) > 0)ans++;
    cout << ans << endl;
}