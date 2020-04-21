#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
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

int v,e,s;
struct edge{
    ll to; ll cost;
};
vector<edge> g[100020];
vector<ll> ans;
void dijkstra(int start){
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(start,0));
    ans[start] = 0;
    while(!que.empty()){
        P tmp = que.top();que.pop();
        ll to = tmp.first;ll cost = tmp.second;
        if(ans[to] < cost)continue;
        FOR(i,0,g[to].size()){
            edge tmp = g[to][i];
            if(ans[tmp.to] > ans[to] + tmp.cost){
                ans[tmp.to] = ans[to] + tmp.cost;
                que.push(make_pair(tmp.to, ans[tmp.to]));
            }
        }
    }
}
signed main () {
    scanf("%d %d %d",&v,&e,&s);
    REP(i,e){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        g[a].push_back(edge{b,c});
    }
    ans.assign(v,INF);

    dijkstra(s);

    REP(i,v){
        if(ans[i]==INF){
            printf("INF\n");
        } else {
            printf("%d\n",ans[i]);
        }
    }
}