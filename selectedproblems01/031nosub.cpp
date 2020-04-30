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
int dex[]={-1,0,1,1,0,-1};int dey[]={0,-1,0,1,1,1};
int dex[]={-1,0,1,1,0,-1};int dey[]={0,-1,0,1,1,1};
ll search(ll sum ,int h,int w, vector<vector<bool>> &seen, vector<vector<int>> list){
    REP(i,6){
        int x=h+dxx[i];int y=w+dyy[i];
        if(x<0 || x >=H+2 || y<0 || y >=W+2)continue;
        if(list[x][y]==1)sum++;
    }
    REP(i,6){
        int x=h+dxx[i];int y=w+dyy[i];
        if(x<0 || x >=H+2 || y<0 || y >=W+2)continue;
        if (!seen[x][y] && list[x][y]==0){
            if(x==3 && y==2)cout << 'a' << endl;
            seen[x][y]=true;
            sum = search(sum,x,y,seen,list);
        }
    }
    return sum;
}

signed main () {
    scanf("%d %d",&W,&H);
    vector<vector<int>> list(H+2,vector<int>(W+2));
    FOR(i,1,H+1){
        FOR(j,1,W+1)cin >> list[i][j];
    }
    FOR(i,0,H+2){
        FOR(j,0,W+2)cout << list[i][j];
        cout << endl;
    }
    ll ans = 0;
    vector<vector<bool>> seen(H+2,vector<bool>(W+2,false));
    /*
    FOR(i,1,H+1)FOR(j,1,W+1){
        if(!seen[i][j] && list[i][j]!=1){
            seen[i][j]=true;
            ans += search(0,i,j,seen,list);
        }
    }*/
    seen[0][0]=true;
    ans =search(0,0,0,seen,list);
    cout << ans << endl;
}