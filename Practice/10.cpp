// https://atcoder.jp/contests/abc051/tasks/abc051_b
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
    int K,S;
    cin >> K >> S;
    int ans = 0;
    REP(i,K+1)REP(j,K+1){
        if (i+j>S || S-i-j>K)continue;
        ans++;
    }
    cout << ans << endl;
}