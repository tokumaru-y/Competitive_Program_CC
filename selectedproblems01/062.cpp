#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
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
int h,w;
int numlist[10][10];
signed main () {
    scanf("%d %d",&h,&w);
    REP(i,10){
        REP(j,10){
            int tmp ;scanf("%d",&tmp);
            numlist[i][j]=tmp;
        }
    }
    REP(k,10){
        REP(i,10){
            REP(j,10){
                numlist[i][j]=min(numlist[i][j],numlist[i][k]+numlist[k][j]);
            }
        }
    }
    int ans=0;
    REP(i,h){
        REP(j,w){
            int tmp;scanf("%d",&tmp);
            if(tmp!=-1 && tmp != 1){
                ans+=numlist[tmp][1];
            }
        }
    }
    printf("%d\n",ans);
}