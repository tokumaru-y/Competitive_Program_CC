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

int N;
vector<ll> xaxis;vector<ll> yaxis;
signed main () {
    cin >> N;xaxis.resize(N);yaxis.resize(N);
    REP(i,N)cin >> xaxis[i] >> yaxis[i];
    double ans=0;
    REP(i,N)FOR(j,i+1,N){
        double x=xaxis[i]-xaxis[j];
        double y=yaxis[i]-yaxis[j];
        ans = max(ans, pow(x*x+y*y,0.5));
    }
    printf("%.10lf\n",ans);
}