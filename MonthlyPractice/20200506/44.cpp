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
vector<vector<char>> grid;
vector<vector<bool>> seen;
signed main () {
    int h,w;cin >> h >> w;
    grid.assign(h,vector<char>(w));
    seen.assign(h,vector<bool>(w,false));
    vector<vector<char>> ans(h,vector<char>(w));
    REP(i,h)REP(j,w){
        cin >> grid[i][j];
    }
    REP(i,h)REP(j,w){
        bool flag = true;
        if(grid[i][j]=='#'){
            for(int s=-1;s<=1;s++){
                for(int t=-1;t<=1;t++){
                    int nx = i+s;int ny = j+t;
                    if(nx<0 || nx >= h || ny < 0 || ny >= w)continue;
                    if(grid[nx][ny]!='#')flag = false;
                }
            }
            if(flag){
                ans[i][j]='#';
                for(int s=-1;s<=1;s++){
                    for(int t=-1;t<=1;t++){
                        int nx = i+s;int ny = j+t;
                        if(nx<0 || nx >= h || ny < 0 || ny >= w)continue;
                        seen[nx][ny]=true;
                    }
                }
            } else {
                ans[i][j]='.';
            }
        }else{
            ans[i][j]='.';
        }
    }
    REP(i,h)REP(j,w){
        if(grid[i][j]=='#'){
            if(!seen[i][j]){
                cout << "impossible" << endl;return 0;
            }
        }
    }
    cout << "possible" << endl;
    REP(i,h){
        REP(j,w){
            cout << ans[i][j];
        }
        cout << endl;
    }
}//https://atcoder.jp/contests/abc039/tasks/abc039_d
