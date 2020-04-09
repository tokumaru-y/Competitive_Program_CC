#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
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
signed main () {
    int n;scanf("%d",&n);
    vector<vector<bool>> list(5001,vector<bool>(5001,false));
    vector<vector<int>> originlist(n, vector<int>(2,0));
    REP(i,n){
        int x,y;scanf("%d %d",&x,&y);
        list[x][y] = true;
        originlist[i][0]=x;originlist[i][1]=y;
    }
    int ans=0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int x1 = originlist[i][0]; int y1 = originlist[i][1];
            int x2 = originlist[j][0]; int y2 = originlist[j][1];
            int tmp1 = x2-y2+y1;int tmp2 = y2+x2-x1;int tmp3 = x1-y2+y1; int tmp4 = y1+x2-x1;
            if (tmp1 < 0 || tmp1 > 5000 ||
                tmp2 < 0 || tmp2 > 5000 ||
                tmp3 < 0 || tmp3 > 5000 ||
                tmp4 < 0 || tmp4 > 5000 ) continue;
            if (list[tmp1][tmp2] == true && list[tmp3][tmp4] == true){
                ans = max(ans, (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            }
        }
    }
    printf("%d\n",ans);
}