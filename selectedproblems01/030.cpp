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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int h,w,fac;scanf("%d %d %d",&h,&w,&fac);
    vector<string> list(h);
    int sx,sy;
    REP(i,h){
        string t;cin >> t;
        list[i]=t;
    }
    REP(i,h){
        REP(j,w){
            if(list[i][j] == 'S'){
                sx = i;sy=j;
            }
        }
    }
    int ans = 0;
    REP(i,fac){
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(sx,sy,0));
        vector<vector<bool>> seen(h,vector<bool>(w,false));
        seen[sx][sy]=true;
        while(!q.empty()){
            tuple<int,int,int> tmp = q.front();q.pop();
            int x=get<0>(tmp);int y = get<1>(tmp);int cnt=get<2>(tmp);
            for(int k=0;k<4;k++){
                int nx=x+dx[k];int ny=y+dy[k];
                if(nx<0 || nx>=h || ny<0 || ny>=w)continue;
                if(list[nx][ny]=='0' + (i+1)){
                    ans+=cnt+1;
                    sx = nx;sy = ny;
                    queue<tuple<int,int,int>> t;
                    swap(q,t);
                    break;
                } else if (list[nx][ny] != 'X' && !seen[nx][ny]){
                    seen[nx][ny]=true;
                    q.push(make_tuple(nx,ny,cnt+1));
                }
            }
        }
        //printf("%d",ans);
    }
    printf("%d\n",ans);
}