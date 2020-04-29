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
    int m;scanf("%d",&m);
    vector<P> list(m);
    REP(i,m){
        int a,b;scanf("%d %d",&a,&b);
        P tmp = make_pair(a,b);
        list[i]=tmp;
    }
    int n;scanf("%d",&n);
    vector<P> list2(n);
    map<P,bool> mm;
    REP(i,n){
        int a,b;scanf("%d %d",&a,&b);
        list2[i]=make_pair(a,b);
        mm[P(a,b)]=true;
    }
    P tmp =list[0];int tx = tmp.first;int ty = tmp.second;
    REP(i,n){
        P tt = list2[i];
        int xdiff=tt.first-tx;int ydiff=tt.second-ty;
        bool flag=true;
        REP(i,m){
            P ttt=list[i];int mx=ttt.first;int my = ttt.second;
            flag &= mm[P(mx+xdiff,my+ydiff)];
        }
        if(flag){
            printf("%d %d\n",xdiff,ydiff);
            exit(0);
        }
    }
}