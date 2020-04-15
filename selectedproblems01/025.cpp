#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
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
vector<vector<bool>> seen;
vector<vector<int>> islands;
int H,W;
void dfs(int i,int j){
    for(int s=-1;s<=1;s++){
        for(int t=-1;t<=1;t++){
            int x=s+i;int y = t+j;
            if(x<0 || x >=H || y < 0 || y >= W) continue;
            if(islands[x][y] == 1 && !seen[x][y]){
                seen[x][y]=true;
                dfs(x,y);
            }
        }
    }
}
signed main () {
    vector<int> list;
    while(scanf("%d %d",&W,&H)){
        if(H==0&&W==0)break;
        islands.assign(H,vector<int>(W,0));
        REP(i,H){
            REP(j,W){
                int tmp;scanf("%d",&tmp);
                islands[i][j]=tmp;
            }
        }
        int ans= 0;
        seen.assign(H,vector<bool>(W,false));
        REP(i,H){
            REP(j,W){
                if(islands[i][j]==1 && !seen[i][j]){
                    seen[i][j]=true;
                    dfs(i,j);
                    ans++;
                }
            }
        }
        list.push_back(ans);
    }
    for(int i:list)printf("%d\n",i);
}