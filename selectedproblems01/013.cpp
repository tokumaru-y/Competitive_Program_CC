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
    int n,m;scanf("%d %d",&n,&m);
    vector<vector<int>> list(n,vector<int>(m));
    REP(i,n){
        REP(j,m){
            int tmp;scanf("%d",&tmp);
            list[i][j] = tmp;
        }
    }
    int ans = 0;
    for(int bit=0;bit<(1<<n);bit++){
        int tmp_ans=0;
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                if(list[k][j] == 1 && (bit&(1<<k))){
                    cnt++;
                } else if (list[k][j] == 0 && !(bit&(1<<k))){
                    cnt++;
                }
            }
            tmp_ans += max(cnt,n-cnt);
        }
        ans=max(ans,tmp_ans);
    }
    printf("%d\n",ans);
}