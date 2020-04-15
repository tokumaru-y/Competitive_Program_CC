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
vector<vector<int>> trees;
vector<int> ans;
vector<int> query;
vector<bool> seen;
void dfs(int ind, int& points){
    points += query[ind];
    ans[ind] = points;
    for(int nextind : trees[ind]){
        if(seen[nextind])continue;
        seen[nextind]=true;
        dfs(nextind,points);
    }
    points -= query[ind];
}
signed main () {
    int n,m;scanf("%d %d",&n,&m);
    trees.assign(n,vector<int>());
    ans.assign(n,0);
    query.assign(n,0);
    seen.assign(n,false);
    REP(i,n-1){
        int a,b;scanf("%d %d",&a,&b);
        trees[a-1].push_back(b-1);
        trees[b-1].push_back(a-1);
    }
    REP(i,m){
        int a,b;scanf("%d %d",&a,&b);
        query[a-1] += b;
    }
    int points=0;
    seen[0] = true;
    dfs(0,points);
    printf("%d",ans[0]);
    for(int i=1;i<n;i++){
        printf(" %d",ans[i]);
    }
}