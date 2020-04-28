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
/*
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
}*/
signed main(){
    int h,w;scanf("%d %d",&h,&w);
    int k;scanf("%d",&k);
    vector<vector<int>> jun(h+1,vector<int>(w+1,0));
    vector<vector<int>> oce(h+1,vector<int>(w+1,0));
    vector<vector<int>> ice(h+1,vector<int>(w+1,0));
    REP(a,h){
        REP(b,w){
            char tmp;cin >> tmp;
            if(tmp=='J')jun[a+1][b+1]++;
            if(tmp=='O')oce[a+1][b+1]++;
            if(tmp=='I')ice[a+1][b+1]++;
        }
    }
    vector<vector<int>> j(h+1,vector<int>(w+1,0));
    vector<vector<int>> o(h+1,vector<int>(w+1,0));
    vector<vector<int>> i(h+1,vector<int>(w+1,0));
    REP(a,h){
        REP(b,w){
            j[a+1][b+1]=j[a+1][b]+j[a][b+1]-j[a][b]+jun[a+1][b+1];
            o[a+1][b+1]=o[a+1][b]+o[a][b+1]-o[a][b]+oce[a+1][b+1];
            i[a+1][b+1]=i[a+1][b]+i[a][b+1]-i[a][b]+ice[a+1][b+1];
        }
    }
    REP(a,k){
        int x1,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int jungle = j[x2][y2] - j[x2][y1-1] - j[x1-1][y2] + j[x1-1][y1-1];
        int ocean = o[x2][y2] - o[x2][y1-1] - o[x1-1][y2] + o[x1-1][y1-1];
        int ices = i[x2][y2] - i[x2][y1-1] - i[x1-1][y2] + i[x1-1][y1-1];
        cout << jungle << ' ' << ocean << ' ' << ices << endl;
    }
}