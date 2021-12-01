// https://atcoder.jp/contests/arc130/tasks/arc130_b
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
    int H,W,C,Q;
    cin >> H >> W >> C >> Q;
    vector<vector<int>> TNC(Q, vector<int>{-1,-1,-1});
    REP(i,Q)cin >> TNC[i][0] >> TNC[i][1] >> TNC[i][2];
    reverse(ALL(TNC));
    set<int>used_h;set<int>used_w;
    vector<ll> ans(C+1,0);
    REP(i,Q){
        int t = TNC[i][0];int n = TNC[i][1];int c = TNC[i][2];
        if (t==1 && used_h.find(n) == used_h.end()){
            used_h.insert(n);
            ans[c] += W - used_w.size();
        } else if (t==2 && used_w.find(n) == used_w.end()){
            used_w.insert(n);
            ans[c] += H - used_h.size();
        }
    }
    REP(i,C){
        cout << ans[i+1] << " ";
    }
    cout << endl;
}