#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    int array[5];
    for(int i=0;i<5;i++){
        scanf("%d",&array[i]);
    }
    int k;
    scanf("%d",&k);
    bool flag = true;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j){
                continue;
            } else if (abs(array[i] - array[j])>k){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        printf("%s", "Yay!");
    } else {
        printf("%s", ":(");
    }
}