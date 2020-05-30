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

signed main () {
    int n,m;cin >> n >> m;
    vector<vector<int>> trees(n,vector<int>());
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        trees[a].push_back(b);
        trees[b].push_back(a);
    }
    vector<int> ans(n);
    priority_queue<P,vector<P>,greater<P>> que;
    vector<bool> seen(n,false);
    seen[0]=true;
    for(int next : trees[0]){
        que.push(P(1,next));
        ans[next]=1;
        seen[next]=true;
    }
    while(!que.empty()){
        P tmp = que.top();que.pop();
        int cnt = tmp.first;int origin=tmp.second;
        for(int next : trees[origin]){
            if(!seen[next]){
                que.push(P(cnt+1,next));
                ans[next]=origin+1;
                seen[next]=true;
            }
        }
    }
    if(count(ALL(seen),false)>0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        FOR(i,1,n){
            cout << ans[i] << endl;
        }
    }
}