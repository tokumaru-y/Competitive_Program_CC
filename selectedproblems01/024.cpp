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
vector<bool> seen;
vector<int> start_time;vector<int> finish_time;
vector<vector<int> > g;
void dfs(int ind,int& cnt){
    start_time[ind]=++cnt;
    seen[ind]=true;
    for(int nextind : g[ind]){
        if(seen[nextind])continue;
        dfs(nextind,cnt);
    }
    finish_time[ind]=++cnt;
}
signed main () {
    int n;scanf("%d",&n);
    g.resize(n);
    REP(i,n){
        int ind,tmp;scanf("%d %d",&ind,&tmp);
        REP(j,tmp){
            int a;scanf("%d",&a);
            g[i].push_back(a-1);
        }
    }
    seen.assign(n,false);start_time.resize(n);finish_time.resize(n);
    int cnt =0;
    REP(i,n){
        if(seen[i])continue;
        dfs(i,cnt);
    }
    REP(i,n){
        printf("%d %d %d\n",i+1,start_time[i],finish_time[i]);
    }
    return 0;
}