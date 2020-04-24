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

signed main () {
    int h,w;scanf("%d %d",&h,&w);
    SCANF(k);
    vector<string> list(h);
    vector<vector<int>> ju(h+1,vector<int>(w+1,0));
    vector<vector<int>> oc(h+1,vector<int>(w+1,0));
    vector<vector<int>> ic(h+1,vector<int>(w+1,0));
    REP(i,h){
        string tmp;cin >> tmp;
        list[i]=tmp;
    }
    REP(i,h){
        REP(j,w){
            if(list[i][j]=='J'){
                ju[i+1][j+1] = ju[i][j+1] + ju[i+1][j] - ju[i][j] + 1;
                oc[i+1][j+1] = oc[i][j+1] + oc[i+1][j] - oc[i][j];
                ic[i+1][j+1] = ic[i][j+1] + ic[i+1][j] - ic[i][j];
            } else if(list[i][j]=='O'){
                ju[i+1][j+1] = ju[i][j+1] + ju[i+1][j] - ju[i][j];
                oc[i+1][j+1] = oc[i][j+1] + oc[i+1][j] - oc[i][j] + 1;
                ic[i+1][j+1] = ic[i][j+1] + ic[i+1][j] - ic[i][j];
            } else if(list[i][j]=='I'){
                ju[i+1][j+1] = ju[i][j+1] + ju[i+1][j] - ju[i][j];
                oc[i+1][j+1] = oc[i][j+1] + oc[i+1][j] - oc[i][j];
                ic[i+1][j+1] = ic[i][j+1] + ic[i+1][j] - ic[i][j] + 1;
            }
        }
    }
    REP(i,k){
        int x1,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int jungle=ju[x2][y2] - ju[x1][y2] - ju[x2][y1] + ju[x1][y1];
        int ocean=oc[x2][y2] - oc[x1][y2] - oc[x2][y1] + oc[x1][y1];;
        int ice=ic[x2][y2] - ic[x1][y2] - ic[x2][y1] + ic[x1][y1];;
        printf("%d %d %d\n",jungle,ocean,ice);
    }
}