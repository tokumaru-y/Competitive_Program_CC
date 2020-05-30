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
typedef long double ld;
const ld eps = 1.0e-9; // 許容される誤差
double mysqrtl(ld x)
{
  ld a = sqrt((double)x); // 近似値
  do {
    a = (a + x/a) / 2.0L;
  } while (fabsl(x - a*a) > eps);
  return a;
}
signed main () {
    static const double pi = 3.1415926535897932;
    float x,y,h,m; cin >> x >> y >> h >> m ;
    double xx =6.0*m;
    double yy =(0.50*m)+(30.0*h);
    if(xx==0)xx=360.0;
    if(yy==0)yy=360.0;
    double diff =xx<yy?yy-xx:xx-yy;
    double ans = pow(x,2.0) + pow(y,2.0) -2*x*y*(cos(M_PI*(diff/180.0)));
    if(h==m){
        cout << abs(x-y) << endl;
        exit(0);
    }
    printf("%.10lf\n",mysqrtl(ans));
}