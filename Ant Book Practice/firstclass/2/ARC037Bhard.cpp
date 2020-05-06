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
int n,w;
vector<vector<int>> tree;
vector<bool> seen;vector<bool> finish;
bool flag;
void dfs(int x, int pre){
    seen[x]=true;
    for(int nx : tree[x]){
        if(nx==pre)continue;
        if(seen[nx] && !finish[nx]){
            flag =false;return;
        }
        dfs(nx,x);
    }
    finish[x]=true;
}
signed main () {
    cin >> n >> w;
    tree.assign(n,vector<int>());
    REP(i,w){
        int a,b;cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    seen.assign(n,false);
    finish.assign(n,false);
    int cnt =0;
    for(int i=0;i<n;i++){
        if(!seen[i]){
            flag=true;
            dfs(i,-1);
            if(flag)cnt++;
        }
    }
    cout << cnt << endl;
}