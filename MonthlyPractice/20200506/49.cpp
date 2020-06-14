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

signed main () {
    double nx,ny;cin >> nx >> ny;
    int n;cin >> n;
    vector<double> x;vector<double> y;
    REP(i,n){
        double a,b;cin >> a >> b;
        x.push_back(a);y.push_back(b);
    }
    double ans = 1e10;
    REP(i,n){
        double x1=x[i],y1=y[i],x2=x[i+1],y2=y[i+1];
        if(i==n-1)x2=x[0],y2=y[0];
        if(x1==x2){
            ans = min(ans,abs(nx-x1));
        } else if (y1==y2){
            ans = min(ans,abs(ny-y1));
        } else {
            double ori = (y2-y1)*(y2-y1)+(x1-x2)*(x1-x2);
            double tmp = sqrt(ori);
            double t = abs((y2-y1)*nx+(x1-x2)*ny-x1*y2+x2*y1);
            t/=tmp;
            ans = min(ans,t);
        }
    }
    printf("%.7lf\n",ans);
}//https://atcoder.jp/contests/arc042/tasks/arc042_b