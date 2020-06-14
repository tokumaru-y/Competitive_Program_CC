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
    int h,w;cin >> h >> w;
    vector<vector<int>> grid(h,vector<int>(w));
    REP(i,h){
        string tmp ;cin >> tmp;
        REP(j,w)grid[i][j]=tmp[j]-'0';
    }
    vector<vector<int>> ans(h,vector<int>(w,0));
    FOR(i,1,h)FOR(j,1,w){
        if(i==j && i==0)continue;
        int mi = IINF;
        REP(s,4){
            int nx=dx[s]+i;int ny=dy[s]+j;
            if(nx<0 || nx>=h || ny<0 || ny>=w || grid[nx][ny]==0){mi=IINF;break;}
            mi = min(mi,grid[nx][ny]);
        }
        if(mi!=IINF){
            REP(s,4){
                int nx=dx[s]+i;int ny=dy[s]+j;
                grid[nx][ny]-=mi;
            }
            ans[i][j]=mi;
        }
    }
    REP(i,h){
        REP(j,w)cout << ans[i][j];
        cout << endl;
    }    
}//https://atcoder.jp/contests/arc041/tasks/arc041_b