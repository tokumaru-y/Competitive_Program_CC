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
    int h,w;scanf("%d %d",&h,&w);
    vector<string> list(h);
    int b_origin = 0;
    REP(i,h){
        string tmp;cin >> tmp;
        list[i] = tmp;
        REP(j,w){
            if(tmp[j] == '#')b_origin++;
        }
    }
    queue<tuple<int,int,int>> q;
    vector<vector<int>> seen(h,vector<int>(w,-1));
    q.push(make_tuple(0,0,1));seen[0][0]=0;
    while(!q.empty()){
        tuple<int,int,int> tmp = q.front();q.pop();
        int x = get<0>(tmp);int y = get<1>(tmp); int cnt = get<2>(tmp);
        REP(i,4){
            int nx = x+dx[i];int ny = y+dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
            if (nx == h-1 && ny == w-1){
                seen[nx][ny] = cnt+1;
                queue<tuple<int,int,int>> t;
                swap(q, t);
                break;
            } else if(list[nx][ny] == '.' && seen[nx][ny] == -1){
                seen[nx][ny] = cnt+1;
                q.push(make_tuple(nx,ny,cnt+1));
            }
        }
    }
    if(seen[h-1][w-1] == -1){
        printf("-1\n");
    } else {
        int ans = (h*w) - b_origin - seen[h-1][w-1];
        printf("%d",ans);
    }
}