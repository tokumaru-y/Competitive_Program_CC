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
    int h,w,k;cin >> h >> w >> k;
    vector<vector<char>> inlist(h,vector<char>(w));
    REP(i,h){
        string tmp;cin >> tmp;
        REP(j,w){
            inlist[i][j]=tmp[j];
        }
    }
    int ans=0;
    for(int hb=0;hb<(1<<h);hb++){
        for(int wb=0;wb<(1<<w);wb++){
            vector<vector<char>> tmplist=inlist;
            for(int i=0;i<h;i++){
                if(hb & (1<<i)){
                    REP(j,w){
                        tmplist[i][j]='a';
                    }
                }
            }
            for(int j=0;j<w;j++){
                if(wb & (1<<j)){
                    REP(i,h){
                        tmplist[i][j]='a';
                    }
                }
            }
            int tmpcnt=0;
            REP(i,h)REP(j,w){
                if(tmplist[i][j]=='#')tmpcnt++;
            }
            if(tmpcnt==k)ans++;
        }
    }
    cout << ans << endl;
}