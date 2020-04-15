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
vector<vector<int>> graph;
vector<int> ans;
signed main () {
    int n;scanf("%d",&n);
    graph.assign(n,vector<int>(n));
    ans.assign(n,-1);
    REP(i,n){
        int id,tmp;scanf("%d %d",&id,&tmp);
        REP(j,tmp){
            int t;scanf("%d",&t);
            graph[i].push_back(t-1);
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));ans[0] = 0;
    while(!q.empty()){
        pair<int, int> tmp = q.front();q.pop();
        int ind = tmp.first;int cnt = tmp.second;
        for(int next : graph[ind]){
            if(ans[next]!=-1)continue;
            ans[next] = cnt+1;
            q.push(make_pair(next, cnt+1));
        }
    }
    REP(i,n){
        printf("%d %d\n",i+1,ans[i]);
    }
}