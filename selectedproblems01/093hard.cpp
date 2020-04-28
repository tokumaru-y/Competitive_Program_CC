#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
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
int H,W,K;
void changeparet(vector<vector<int>>& p){
    for(int i=H-1;i>=0;i--){
        REP(j,W){
            if(p[i][j]==0){
                for(int s=i-1;s>=0;s--){
                    if(p[s][j]!=0){
                        swap(p[i][j],p[s][j]);
                        break;
                    }
                }
            }
        }
    }
}


ll solve(int x, int y, vector<vector<int>> pp){
    vector<vector<int>> p =pp;p[x][y]=0;ll res = 0;
    changeparet(p);
    bool flag=true;ll roopcnt = 1;
    while(flag){
        flag = false;
        ll tmpsum=0;
        REP(i,H){
            REP(j,W-K+1){
                if(p[i][j]==0)continue;
                int cnt=1;
                FOR(k,j+1,W){
                    if(p[i][j]==p[i][k])cnt++;
                    else break;
                }
                if(cnt>=K){
                    int num = p[i][j];
                    FOR(k,j,j+cnt)p[i][k]=0;
                    tmpsum+=num*cnt;
                    flag=true;
                }
            }
        }
        res += roopcnt*tmpsum;
        roopcnt*=2;
        changeparet(p);
    }
    return res;
}


signed main () {
    scanf("%d %d %d",&H,&W,&K);
    ll ans=0;
    vector<vector<int>> list(H,vector<int>(W));
    REP(i,H){
        string tmp;cin >> tmp;
        REP(j,W){
            list[i][j]=tmp[j]-'0';
        }
    }
    REP(i,H)REP(j,W)ans=max(ans,solve(i,j,list));
    printf("%lld\n",ans);
}