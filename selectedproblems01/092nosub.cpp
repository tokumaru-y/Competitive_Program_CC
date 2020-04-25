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

signed main () {
    int h;
    while(cin >> h){
        if(h==0)break;
        vector<vector<int>> list(h,vector<int>(5));
        REP(i,h){
            REP(j,5){
                cin >> list[i][j];
            }
        }
        ll ans =0;bool flag = true;
        while(flag){
            ll stmp = 0;
            vector<vector<bool>> l(h,vector<bool>(5,false));
            REP(i,h){
                int t=0;int cnt =0;
                REP(j,3){
                    if(list[i][j]!=0 && !l[i][j] && list[i][j] == list[i][j+1] && list[i][j+1] == list[i][j+2]){
                        t=list[i][j];
                        FOR(k,j,5){
                            if(!l[i][k]){
                                cnt++;l[i][k]=true;
                            }
                        }
                    }
                }
                stmp+=t*cnt;
            }
            for(int i=h-1;i>=0;i--){
                REP(j,5){
                    if(l[i][j]){
                        if(i==0){
                            list[i][j]=0;
                        } else {
                            list[i][j] = list[i-1][j];
                            l[i-1][j]=true;
                            for(int k=i-1;i>=0;k--){
                                if(l[k][j]){
                                    l[k][j]=true;
                                } else {
                                    list[i][j]=list[k][j];
                                    l[k][j]=true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            ans += stmp;
            if(!stmp)break;
        }
        printf("%lld\n",ans);
    }
}