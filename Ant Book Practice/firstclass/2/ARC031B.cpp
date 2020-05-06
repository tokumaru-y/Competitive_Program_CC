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

int h=10;int w=10;
vector<vector<char>> grid;
vector<vector<bool>> seen;
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i];int ny=y+dy[i];
        if(nx<0||nx>h-1||ny<0||ny>w-1)continue;
        if(seen[nx][ny] || grid[nx][ny]=='x')continue;
        seen[nx][ny]=true;
        dfs(nx,ny);
    }
}
signed main () {
    grid.resize(h,vector<char>(w));
    seen.resize(h,vector<bool>(w,false));
    int sx,sy;
    for(int i=0;i<h;i++){
        string tmp ;cin >> tmp;
        for(int j=0;j<w;j++){
            grid[i][j]=tmp[j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            bool flag=grid[i][j]=='x'?true:false;
            grid[i][j]='o';
            int cnt = 0;
            for(int s=0;s<h;s++){
                for(int k=0;k<w;k++){
                    if(grid[s][k]=='o'&& !seen[s][k]){
                        seen[s][k]=true;
                        dfs(s,k);
                        cnt++;
                    }
                }
            }
            if(flag)grid[i][j]='x';
            seen.assign(h,vector<bool>(w,false));
            if(cnt==1)cout << "YES" << endl,exit(0);
        }
    }
    cout << "NO" << endl;
}