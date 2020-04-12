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
    vector<vector<bool>> memberlist(n,vector<bool>(n,false));
    REP(i,m){
        int a,b;scanf("%d %d",&a,&b);
        memberlist[a-1][b-1]=true;
        memberlist[b-1][a-1]=true;
    }
    int ans=1;
    for(int bit=0;bit<(1<<n);bit++){
        vector<bool> tmp(n,false);
        int cnt=0;
        for(int j=0;j<n;j++){
            if(bit&(1<<j)){
                tmp[j]=true;
                cnt++;
            }
        }
        bool flag = true;
        for(int h=0;h<n;h++){
            if(!tmp[h])continue;
            for(int k=0;k<n;k++){
                if(!tmp[k] || h == k)continue;
                if(!memberlist[h][k])flag=false;
            }
        }
        if(flag){
            ans = max(ans,cnt);
        }
    }
    printf("%d\n",ans);
}