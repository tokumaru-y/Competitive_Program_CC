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
    int h,w;cin >> w >> h;
    h--;w--;
    string dir;cin >> dir;
    vector<string> grid(9);
    REP(i,9)cin >> grid[i];
    int cnt=0;
    bool flag = false;
    while(cnt<4){
        cout << grid[h][w];
        if(dir=="R"){
            if(w>=8)dir="L",w--;
            else w++;
        } else if(dir=="L"){
            if(w<=0)dir="R",w++;
            else w--;
        } else if(dir=="U"){
            if(h<=0)dir="D",h++;
            else h--;
        } else if(dir=="D"){
            if(h>=8)dir="U",h--;
            else h++;
        } else if(dir=="RU"){
            if(w>=8 && h<=0)dir="LD",h++,w--;
            else if(w>=8)dir="LU",h--,w--;
            else if(h<=0)dir="RD",h++,w++;
            else h--,w++;
        } else if(dir=="RD"){
            if(w>=8 && h>=8)dir="LU",h--,w--;
            else if(w>=8)dir="LD",h++,w--;
            else if(h>=8)dir="RU",h--,w++;
            else h++,w++;
        } else if(dir=="LU"){
            if(w<=0 && h<=0)dir="RD",h++,w++;
            else if(w<=0)dir="RU",h--,w++;
            else if(h<=0)dir="LD",h++,w--;
            else h--,w--;
        } else if(dir=="LD"){
            if(w<=0 && h>=8)dir="RU",h--,w++;
            else if(w<=0)dir="RD",h++,w++;
            else if(h>=8)dir="LU",h--,w--;
            else h++,w--;
        }
        cnt++;
    }
    cout << endl;
}//https://atcoder.jp/contests/arc005/tasks/arc005_2