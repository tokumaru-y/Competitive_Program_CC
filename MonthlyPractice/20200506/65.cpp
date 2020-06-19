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
    int n;cin >> n;
    map<char,string> alp;
    for(char tm = 'a';tm<='z';tm++){
        if(tm=='b'||tm=='c')alp[tm]="1";
        else if(tm=='t'||tm=='j')alp[tm]="3";
        else if(tm=='l'||tm=='v')alp[tm]="5";
        else if(tm=='p'||tm=='m')alp[tm]="7";
        else if(tm=='d'||tm=='w')alp[tm]="2";
        else if(tm=='f'||tm=='q')alp[tm]="4";
        else if(tm=='s'||tm=='x')alp[tm]="6";
        else if(tm=='h'||tm=='k')alp[tm]="8";
        else if(tm=='n'||tm=='g')alp[tm]="9";
        else if(tm=='z'||tm=='r')alp[tm]="0";
    }
    vector<string> ans;
    REP(i,n){
        bool h = false;
        string tmp;cin >> tmp;string ansstr = "";
        transform(tmp.begin(),tmp.end(),tmp.begin(), ::tolower);
        for(char t : tmp){
            if(alp.count(t)==0)continue;
            else ansstr+=alp[t],h=true;
        }
        if(h)ans.push_back(ansstr);
    }
    if(ans.size()==0){
        cout << endl;
        return 0;
    }
    for(int i=0;i<=ans.size()-1;i++){
        cout << ans[i];
        if(i==ans.size()-1)cout << endl;
        else cout << " ";
    }
}//https://atcoder.jp/contests/arc011/tasks/arc011_2