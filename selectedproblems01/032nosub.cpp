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
int dir[4]={1,0,1,0};//横、縦、横、縦
int H,W;
vector<vector<int>> seen;vector<vector<int>> vertical;vector<vector<int>> horizon;
bool check(int h,int w,int d,int diff){
    cout << "ssss" << endl;
    cout << h << ' ' << w << endl;
    //縦移動
    if(d){
        cout << h-diff << " " << w << endl;
        cout << "tate" << endl;
        if(vertical[h-diff][w]==0)return true;
        return false;
    } else {
        cout << h << " " << w-diff << endl;
        cout << "yoko" << endl;
        if(horizon[h][w-diff]==0)return true;
        return false;
    }
}
void search(int h,int w){
    REP(i,4){
        int nh = h+dx[i];int nw = w+dy[i];int d=dir[i];
        if(nh<0||nh>=H||nw<0||nw>=W||seen[nh][nw]!=-1)continue;
        if(check(nh,nw,d,dx[i]+dy[i])){
            seen[nh][nw]=seen[h][w]+1;
            search(nh,nw);
        }
    }
}
signed main () {
    while(cin >> W >> H){
        if(H+W==0)break;
        seen.assign(H,vector<int>(W,-1));
        horizon.assign(H,vector<int>(W-1));
        vertical.assign(H-1,vector<int>(W));
        int index=0;
        REP(i,(H*2)-1){
            if(i%2==0){
                REP(j,W-1)cin >> horizon[index][j];
            } else {
                REP(j,W)cin >> vertical[index][j];
                index++;
            }
        }
        seen[0][0]=1;
        search(0,0);
        ll ans =0;
        seen[H-1][W-1]==-1?ans =0:ans=seen[H-1][W-1];
        cout << ans << endl;
    }
}