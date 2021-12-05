// https://atcoder.jp/contests/arc004/tasks/arc004_1
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
    vector<int> X(N,-1);vector<int> Y(N,-1);
    REP(i,N) cin >> X[i] >> Y[i];
    double ans =0.0;
    REP(i,N)FOR(j,i+1,N){
        int a = X[i], b = Y[i],c = X[j],d = Y[j];
        ans = max(ans, sqrt(pow(a-c,2.0) + pow(b-d,2.0)));
    }
    cout << ans << endl;
}