// https://atcoder.jp/contests/abc002/tasks/abc002_4
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int N,M;cin >> N >> M;
    vector<vector<int>> edge(N,vector<int>(N,-1));
    REP(i,M){
        int x,y;
        cin >> x >> y;
        x--,y--;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }
    int ans = -1;
    for(int bit=0;bit<(1<<N);bit++){
        vector<int>list;
        for(int i=0;i<N;i++){
            if(bit & (1<<i))list.push_back(i);
        }
        bool flag=true;
        for(auto j: list){
            for(auto k: list){
                if (j==k)continue;
                if (edge[j][k] != 1)flag=false;
            }
        }
        if(flag)ans=max(ans, (int)list.size());
    }
    cout << ans << endl;
}