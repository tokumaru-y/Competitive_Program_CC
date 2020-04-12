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
    int switches,lights;scanf("%d %d",&switches,&lights);
    vector<vector<bool>> list(lights,vector<bool>(switches,false));
    int ans=0;
    REP(i,lights){
        int k;scanf("%d",&k);
        for(int j=0;j<k;j++){
            int ind;scanf("%d",&ind);
            list[i][ind-1] = true;
        }
    }
    vector<int> oddlist(lights,0);
    for(int i=0;i<lights;i++){
        int p;scanf("%d",&p);
        oddlist[i] = p;
    }
    for(int bit=0;bit<(1<<switches);bit++){
        vector<int> now_on(lights,0);
        for(int j=0;j<switches;j++){
            if(bit&(1<<j)){
                for(int k=0;k<lights;k++){
                    if(list[k][j]){
                        now_on[k]++;
                    }
                }
            }
        }
        bool flag = true;
        for(int f=0;f<lights;f++){
            if(oddlist[f]!=(now_on[f]%2))flag = false;
        }
        if(flag)ans++;
    }
    printf("%d",ans);
}