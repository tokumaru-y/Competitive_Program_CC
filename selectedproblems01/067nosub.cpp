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

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n) {
        REP(i,n)par[i]=i;
    }
    int root(int x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }
    void unite(int x, int y){
        int rx=root(x);int ry=root(y);
        if(rx==ry)return;
        par[rx]=ry;
    }
    bool same(int x,int y){
        int rx=root(x);int ry=root(y);
        return rx==ry;
    }
};
signed main () {
    SCANF(n);
    vector<pair<ll,ll>> list_x(n);
    vector<pair<ll,ll>> list_y(n);
    REP(i,n){
        ll a,b;scanf("%lld %lld",&a,&b);
        list_x[i]=make_pair(a,b);
        list_y[i]=make_pair(b,a);
    }
    sort(ALL(list_x));sort(ALL(list_y));
    UnionFind tree(2*n);
    priority_queue<tuple<ll,ll,ll,ll,ll,int>,vector<tuple<ll,ll,ll,ll,ll,int>>, greater<tuple<ll,ll,ll,ll,ll,int>>> que;
    REP(i,n-1){
        que.push(make_tuple(min(abs(list_x[i].first - list_x[i+1].first),abs(list_x[i].second - list_x[i+1].second)),list_x[i].first,list_x[i].second,list_x[i+1].first,list_x[i+1].second,i));
        que.push(make_tuple(min(abs(list_y[i].first - list_y[i+1].first),abs(list_y[i].second - list_y[i+1].second)),list_y[i].first,list_y[i].second,list_y[i+1].first,list_y[i+1].second,i));
    }
    int cnt=0;ll ans = 0;
    while(!que.empty()){
        tuple<ll,ll,ll,ll,ll,int> tmp=que.top();que.pop();
        int cost=get<0>(tmp);int a=get<1>(tmp);int b=get<2>(tmp);int c=get<3>(tmp);int d=get<4>(tmp);int 
        if(!tree.same())
    }
    printf("%lld\n",ans);
}