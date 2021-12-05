// https://atcoder.jp/contests/abc104/tasks/abc104_c
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
    int D,G;cin >> D >> G;
    vector<int> P(D,-1);vector<int> C(D,-1);
    REP(i,D)cin >> P[i] >> C[i];
    int ans = IINF;
    for(int bit=0;bit < 1<<(D);bit++){
        ll total_score=0;
        int total_cnt = 0;
        vector<bool> used(D,false);
        for(int i=0;i<D;i++){
            if(bit & (1<<i)){
                total_score+=P[i]*100*(i+1);
                total_score+=C[i];
                used[i]=true;
                total_cnt += P[i];
            }
        }
        if(total_score >= G){
            ans = min(ans, total_cnt);
        } else {
            for(int i=D-1;i>=0;i--){
                if (!used[i]){
                    int need = G - total_score;
                    if (100*(i+1)*(P[i] - 1)>=need){
                        total_cnt += (need + 100*(i+1) - 1)/(100*(i+1));
                        ans = min(ans, total_cnt);
                    }
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}