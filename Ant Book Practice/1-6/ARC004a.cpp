#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    int n;scanf("%d",&n);
    vector<vector<int>> list = {};
    REP(i,n){
        int x,y;scanf("%d %d",&x,&y);
        list.push_back({x,y});
    }
    float ans = 0;
    REP(i,n){
        for(int j=i+1;j<n;j++){
            float tmp = sqrt(pow(list[i][0] - list[j][0], 2.0) + pow(list[i][1] - list[j][1], 2.0));
            ans < tmp ? ans = tmp :ans = ans;
        }
    }
    printf("%f", ans);
}