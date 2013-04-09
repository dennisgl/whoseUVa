#include <stdio.h>
#include <stdlib.h>
#define MAX 10000


int allH[MAX+1]; //all Height
int maxR,nowH;

int main() {
    int r,l,h,i;   
    
    maxR=-1;
    
    while (scanf("%d%d%d",&l,&h,&r)!=EOF) {
        if (maxR<r) {
            maxR = r;
        }
        for (i=l;i<r;i++) {
            if (allH[i]<h) {
                allH[i] = h;
            }
        }
    }
    
    nowH=-1;
    for (i=0;i<=maxR;i++) {
        if (allH[i]!=nowH) {
            if (nowH==-1) {
                nowH = allH[i];
            } else {
                printf("%d %d",i,allH[i]);
                if (i!=maxR) {
                    printf(" ");
                }
                nowH = allH[i];
            }
        }
    }
    printf("\n");
}
