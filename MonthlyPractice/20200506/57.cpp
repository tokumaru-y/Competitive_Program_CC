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
    string instr;cin >> instr;
    ll len = instr.length();
    vector<int> cntlist;int index = 0;int cnt=0;
    while(index<len-1){
        if(instr[index] == '2' && instr[index+1]== '5'){
            cnt++;
            index+=2;
            while(index+1<len && instr[index]=='2' && instr[index+1]=='5')cnt++,index+=2;
        } else index++;
        if(cnt>0)cntlist.push_back(cnt),cnt=0;
    }
    ll ans = 0 ;auto itr = cntlist.begin();
    REP(i,cntlist.size()){
        ll tmp = *itr;
        while(tmp>0){
            ans+=tmp;tmp--;
        }
        itr++;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_2