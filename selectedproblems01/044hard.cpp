#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    vector<int> list;
    int tmp=1;int cnt=1;
    while(tmp<=1000000){
        list.push_back(tmp);
        cnt++;
        tmp=cnt*(cnt+1)*(cnt+2)/6;
    }
    int len = list.size();
    vector<int> dp(1000001,0);vector<int> oddsdp(1000001,0);
    REP(i,1000001){
        dp[i]=i;oddsdp[i]=i;
    }
    REP(i,len){
        REP(j,1000001){
            if(j - list[i]>=0)dp[j] = min(dp[j-list[i]]+1,dp[j]);
        }
        //printf("%d\n",list[i]);
    }
    REP(i,len){
        if(list[i]%2 == 0)continue;
        REP(j,1000001){
            if(j-list[i]>=0)oddsdp[j]=min(oddsdp[j-list[i]]+1,oddsdp[j]);
        }
        //printf("%d\n",oddsdp[40]);
    }
    int n;scanf("%d",&n);
    while(n){
        int ans1,ans2;
        ans1 =dp[n];ans2=oddsdp[n];
        printf("%d %d\n",ans1,ans2);
        scanf("%d",&n);
    }
}