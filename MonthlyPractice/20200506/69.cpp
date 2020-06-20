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
    string s;cin >> s;
    int lens=s.length();
    bool c[5]={false,false,false,false,false};
    int checked=0;
    int minnum=10000000;
    vector<string>ans;
    map<int,vector<string>> anslist;
    REP(i,5){
        char target;
        if(i==0)target='S';
        else if(i==1)target='H';
        else if(i==2)target='D';
        else if(i==3)target='C';
        else target='A';
        ll index = 0;
        while(index<lens){
            string tmp = "";
            tmp+=s[index];
            if(s[index]==target){
                if(s[index+1]=='1'){
                    tmp+=s[index+1];
                    tmp+=s[index+2];
                    index+=3;
                    if(c[0])ans.push_back(tmp);
                    else c[0]=true,checked++;
                } else {
                    tmp+=s[index+1];
                    if(s[index+1]=='Q'){
                        if(c[1])ans.push_back(tmp);
                        else c[1]=true,checked++;
                    } else if(s[index+1]=='J'){
                        if(c[2])ans.push_back(tmp);
                        else c[2]=true,checked++;
                    } else if(s[index+1]=='K'){
                        if(c[3])ans.push_back(tmp);
                        else c[3]=true,checked++;
                    } else if(s[index+1]=='A'){
                        if(c[4])ans.push_back(tmp);
                        else c[4]=true,checked++;
                    } else {
                        ans.push_back(tmp);
                    }
                    index+=2;
                }    
            } else {
                if(s[index+1]=='1'){
                    tmp+=s[index+1];
                    tmp+=s[index+2];
                    index+=3;
                } else{
                    tmp+=s[index+1];
                    index+=2;
                }
                ans.push_back(tmp);
            }
            if(checked==5){
                int checkedlens = ans.size();
                minnum=min(minnum,checkedlens);
                anslist[checkedlens]=ans;
                break;
            }
        }
    }
    if(minnum==0){
        cout << 0 << endl;
    } else {
        for(string aaa : anslist[minnum]){
            cout << aaa;
        }
        cout << endl;
    }
    return 0;
}//https://atcoder.jp/contests/tenka1-2012-qualC/tasks/tenka1_2012_10