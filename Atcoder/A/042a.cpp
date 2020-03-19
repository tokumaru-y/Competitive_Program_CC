#include <bits/stdc++.h>
using namespace std;
int main (){
    int seven =0;int five=0;
    for(int i=0;i<3;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==7)seven++;
        if(tmp==5)five++;
    }
    if(seven==1 && five == 2){
        printf("YES");
    } else {
        printf("NO");
    }
}