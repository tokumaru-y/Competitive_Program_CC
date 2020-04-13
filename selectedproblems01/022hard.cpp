#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
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
auto calculate(double x, double p){
    return x + (p / pow(2,x / 1.5));
}
signed main () {
    double p;scanf("%lf",&p);
    double low = 0; double high = 1e18;
    while(abs(low-high)>1e-9){
        double left = (low*2 + high) / 3;
        double right = (low + high*2) / 3;
        if(calculate(left,p) > calculate(right, p)) low = left;
        else high = right;
    }
    printf("%.10f\n",calculate(low, p));
}