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

int n,m,k,s;ll p,q;
struct edge{int to;int cost;};
vector<vector<int>> roads;
vector<bool> seen;
vector<vector<edge>> g;
vector<bool> town_state;
vector<ll> ans;
void djkastra(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(make_pair(s,0));
    while(!que.empty()){
        P tmp = que.top();que.pop();
        int to = tmp.first;ll cost = tmp.second;
        if(ans[to] < cost)continue;
        FOR(i,0,roads[to].size()){
            int next = roads[to][i];
            ll pay = town_state[to] ? p :  q;
            if(ans[next]>cost + pay){
                ans[next] = cost + pay;
                que.push(make_pair(next, ans[next]));
            }
        }
    }
    
}
void check_state(int i, int cnt){
    cnt++;
    town_state[i]=false;
    if(cnt<=s){
        for(int j = 0;j<roads[i].size();j++){
            if(!seen[j]){
                seen[j]=true;
                check_state(roads[i][j],cnt);
            }
        }
    }
}
signed main () {
    scanf("%d %d %d %d",&n,&m,&k,&s);
    scanf("%lld %lld",&p,&q);
    roads.assign(n,vector<int>());
    town_state.assign(n,true);
    vector<int> out_area_list;
    REP(i,k){
        int tmp;scanf("%d",&tmp);
        out_area_list.push_back(tmp-1);
    }
    REP(i,m){
        int a,b;scanf("%d %d",&a,&b);
        a--;b--;
        roads[a].push_back(b);roads[b].push_back(a);
    }
    for(int i : out_area_list){
        seen.assign(n,false);
        seen[i] =true;
        check_state(i,0);
    }
    ans.assign(n,INF);
    ans[0]=0;
    djkastra(0);
    printf("%lld\n",ans[n-1]);
}