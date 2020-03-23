#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    vector<vector<int>> bingo(3);
    int point[3][3] = {0};
    REP(i,3){
        int a,b,c;scanf("%d %d %d",&a,&b,&c);
        bingo.at(i).push_back(a);
        bingo.at(i).push_back(b);
        bingo.at(i).push_back(c);
    }
    int n;scanf("%d",&n);
    REP(i,n) {
        int tmp;scanf("%d",&tmp);
        REP(j,3) {
            REP(k,3) {
                if(bingo[j][k] == tmp) {
                    point[j][k] += 1;
                }           
            }
        }
    }
    if (
        (point[0][0] && point[0][1] && point[0][2]) ||
        (point[1][0] && point[1][1] && point[1][2]) ||
        (point[2][0] && point[2][1] && point[2][2]) ||
        (point[0][0] && point[1][0] && point[2][0]) ||
        (point[0][1] && point[1][1] && point[2][1]) ||
        (point[0][2] && point[1][2] && point[2][2]) ||
        (point[0][0] && point[1][1] && point[2][2]) ||
        (point[0][2] && point[1][1] && point[2][0])
    ) {
        printf("Yes");
    } else {
        printf("No");
    }
    
}