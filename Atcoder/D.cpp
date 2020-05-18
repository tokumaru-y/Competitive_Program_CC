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
vector<ll> graph;
vector<ll> start;vector<ll> finish;
vector<ll> roots;
ll ans ;
ll roopcnt;ll startcnt;
void dfs(int x,int cnt) {
    ll nx = graph[x];
    start[x]=cnt;
    cnt++;
    if(start[nx]>=0 && finish[nx]==-1){
        startcnt=start[nx];
        roopcnt=cnt - start[nx];
        finish[nx]=cnt+1;
        return;
    }
    roots.push_back(nx);
    dfs(nx,cnt);
    cnt++;
    finish[x]=cnt;
}

signed main () {
    ll n,k;cin >> n >> k;
    graph.resize(n);
    start.assign(n,-1);finish.assign(n,-1);
    REP(i,n){int tmp;cin >> tmp;graph[i]=tmp-1;}
    roots.push_back(0);
    dfs(0,0);
    if(startcnt>=k){
        ans = roots[k]+1;
    } else {
        ll left = k - (startcnt);
        ll ind = left%roopcnt;
        ans = roots[startcnt+ind]+1;
    }
    cout << ans << endl;
}