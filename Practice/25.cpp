// https://atcoder.jp/contests/arc031/tasks/arc031_2
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};
void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &used){
    used[x][y] = true;
    REP(i,4){
        int nx=x+dx[i];int ny=y+dy[i];
        if (!(0<=nx && nx <= 9) || !(0<=ny && ny <= 9))continue;
        if (used[nx][ny] || grid[nx][ny] == 'x')continue;
        dfs(nx,ny, grid, used);
    }
}

bool check(vector<vector<char>> &grid, vector<vector<bool>> &used){
    REP(i,10)REP(j,10){
        if (grid[i][j] == 'o' && !used[i][j]){
            return false;
        }
    }
    return true;
}
signed main () {
    vector<vector<char>> grid(10, vector<char>(10));
    REP(i,10)REP(j,10){
        cin >> grid[i][j];
    }
    REP(i,10)REP(j,10){
        if (grid[i][j] == 'x'){
            vector<vector<bool>> used(10, vector<bool>(10, false));
            grid[i][j] = 'o';
            dfs(i,j, grid, used);
            bool is_ok = check(grid, used);
            if (is_ok){cout << "YES" << endl;return 0;}
            grid[i][j] = 'x';
        }
    }
    cout << "NO"<< endl;
}