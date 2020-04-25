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

signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<tuple<int,int,int>> list(n);
    REP(i,n){
        int x,y,r;scanf("%d %d %d",&x,&y,&r);
        list[i]=make_tuple(x,y,r);
    }

    vector<P> list2(m);
    REP(i,m){
        int x,y;scanf("%d %d",&x,&y);
        list2[i]=make_pair(x,y);
    }
    vector<double> dis;
    REP(i,m){
        int x1=get<0>(list2[i]);int y1 = get<1>(list2[i]);
        FOR(j,i+1,m){
            int x2 = get<0>(list2[j]);int y2 = get<1>(list2[j]);
            double xx = pow(abs(x1-x2),2);double yy = pow(abs(y1-y2),2);
            dis.push_back(sqrt(xx+yy)/2.0);
        }
    }
    REP(i,n){
        int x1=get<0>(list[i]);int y1 = get<1>(list[i]);int r = get<2>(list[i]);
        dis.push_back(r);
        REP(j,m){
            int x2 = get<0>(list2[j]);int y2 = get<1>(list2[j]);
            double xx = (x1-x2)*(x1-x2);double yy = (y1-y2)*(y1-y2);
            dis.push_back(sqrt(xx+yy)-r);
        }
    }
    double ans = *min_element(ALL(dis));
    printf("%.10lf\n",ans);
}