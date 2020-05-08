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
int n,m;vector<vector<int>> path;
int ans =0;vector<bool> seen;
void dfs(int x,int nowcnt){
    for(int cand : path[x]){
        if(seen[cand])continue;
        if(nowcnt+1==n){
            ans++;return;
        }
        seen[cand]=true;
        dfs(cand,nowcnt+1);
        seen[cand]=false;
    }
}
signed main () {
    cin >> n >> m;
    path.assign(n,vector<int>(n));
    seen.assign(n,false);
    REP(i,m){
        int a,b;cin >> a >> b;
        a--;b--;
        path[a].push_back(b);path[b].push_back(a);
    }
    seen[0]=true;
    dfs(0,1);
    cout << ans << endl;
}