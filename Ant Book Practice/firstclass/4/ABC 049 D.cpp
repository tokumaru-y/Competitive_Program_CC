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
struct UF { 
    vector<int> par;vector<int> deepth;
    UF(int x) : par(x) {
        REP(i,x)par[i]=i;
        deepth.assign(x,1);
    }
    int root(int x){
        if(x==par[x])return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x);int ry=root(y);
        if(rx==ry)return;
        par[rx]=ry;
        deepth[ry]+=deepth[rx];
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int deep(int x){
        return deepth[x];
    }
};
signed main () {
    ll N,K,L;cin >> N >> K >> L;
    UF roads(N);UF trains(N);
    REP(i,K){
        int a,b;
        cin >> a >> b;
        a--;b--;
        roads.unite(a,b);
    }
    REP(i,L){
        int a,b;cin >> a >> b;
        a--;b--;
        trains.unite(a,b);
    }
    map<P,int> ans;
    REP(i,N){
        ans[make_pair(roads.root(i),trains.root(i))]++;
    }
    REP(i,N){
        cout << ans[make_pair(roads.root(i),trains.root(i))] << " ";
    }
}