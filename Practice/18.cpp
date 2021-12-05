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
    int N;cin >> N;
    vector<int> L(N,-1);
    REP(i,N)cin >> L[i];
    int ans =0;
    FOR(i,0,N)FOR(j,i+1,N)FOR(k,j+1,N){
        if (L[i] == L[j] || L[j] == L[k] || L[k] == L[i])continue;
        if (L[i]+L[j] > L[k] && L[j]+L[k] > L[i] && L[k]+L[i] > L[j])ans++;
    }
    cout << ans << endl;
}