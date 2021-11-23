// https://atcoder.jp/contests/arc004/tasks/arc004_1
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) for(int (i)=0;(i) < (n);(i)++)
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
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    REP(i,N){
        int x,y;
        cin >> x >> y;
        auto p = make_pair(x,y);
        A[i] = p;
    }
    double ans = 0.0;
    REP(i,N)FOR(j,i+1,N){
        auto x = A[i];
        auto y = A[j];
        double tmp = sqrt(pow(abs(x.first - y.first), 2.0) + pow(abs(x.second - y.second), 2.0));
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}