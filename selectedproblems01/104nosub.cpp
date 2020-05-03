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
int H,W;
vector<ll> sx;vector<ll> sy;
vector<ll> ex;vector<ll> ey;
vector<vector<bool>> seen;
void dfs(vector<vector<int>> press, int h, int w,int hl,int wl){
    queue<P> queue;
    queue.push(P(h,w));
    while(!queue.empty()){
        P tmp=queue.front();queue.pop();
        int x = tmp.first;int y=tmp.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];int ny=y+dy[i];
            if(nx<0 || nx>hl || ny<0 || ny>wl)continue;
            if(!seen[nx][ny] && press[nx][ny]<1){
                seen[nx][ny]=true;
                queue.push(P(nx,ny));
            }
        }
    }
}


void solve(vector<ll> sortx,vector<ll> sorty) {
    vector<ll> gridx;vector<ll> gridy;
    for(int i=0;i<sortx.size();i++){
        if(i==0 || sortx[i] != sortx[i-1])gridx.push_back(sortx[i]);
    }
    for(int i=0;i<sorty.size();i++){
        if(i==0 || sorty[i] != sorty[i-1])gridy.push_back(sorty[i]);
    }
    vector<vector<int>> press(sortx.size()+1,vector<int>(sorty.size()+1));
    for(int i=0;i<sortx.size();i++){
        int x1=lower_bound(ALL(gridx),sx[i]) - gridx.begin();
        int y1=lower_bound(ALL(gridy),sy[i]) - gridy.begin();
        int x2=lower_bound(ALL(gridx),ex[i]) - gridx.begin();
        int y2=lower_bound(ALL(gridy),ey[i]) - gridy.begin();
        press[x1][y1]++;press[x1][y2]--;press[x1][y2]--;press[x2][y2]++;
    }
    cout << 'a' << endl;
    for(int i=0;i<sortx.size();i++){
        for(int j=0;j<sorty.size()-1;j++){
            press[i][j+1]+=press[i][j];
        }
    }
    for(int i=0;i<sorty.size();i++){
        for(int j=0;j<sortx.size();j++)
        press[j+1][i]+=press[j][i];
    }
    cout << 'b' << endl;
    int ans = 0;
    REP(i,sortx.size()){
        REP(j,sorty.size()){
            cout << press[i][j];
        }
        cout << endl;
    }
    seen.assign(sortx.size()+1,vector<bool>(sorty.size()+1,false));
    FOR(i,0,sortx.size()){
        FOR(j,0,sorty.size()){
            if(!seen[i][j] && press[i][j]<1){
                seen[i][j]=true;
                dfs(press,i,j,sortx.size(),sorty.size());
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main () {
    cin >> W >> H;
    int n;cin >> n;
    sx.resize(n);sy.resize(n);
    ex.resize(n);ey.resize(n);
    vector<ll> sortx;vector<ll> sorty;
    REP(i,n){
        ll ax,ay,bx,by;cin >> ax >> ay >> bx >> by;
        sx[i]=ax;sy[i]=ay;ex[i]=bx;ey[i]=by;
        sortx.push_back(ax);sortx.push_back(bx);
        if(bx+1<W)sortx.push_back(bx+1);
        sorty.push_back(ay);sorty.push_back(by);
        if(by+1<H)sorty.push_back(by+1);
    }
    sort(ALL(sortx));sort(ALL(sorty));
    solve(sortx,sorty);
    return 1;
}