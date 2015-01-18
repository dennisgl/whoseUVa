#include <stdio.h>
#include <string.h>
#define MAX 120
#define INF 2100000000
//#define debug

int m,n;
int map[MAX][MAX];
int mapL[MAX][MAX];
int mapR[MAX][MAX];

int min(int a,int b ,int c) {
    int ans=INF;
    
    if (ans>a) {
        ans = a;
    }
    
    if (ans>b) {
        ans = b;
    }
    
    if (ans>c) {
        ans = c;
    }
    
    if (ans == -1) {   
        return 0;
    }
    
    return ans;
}

int main () {
    int i,j;
    int ans;
    int area;
    int h,nowl,nowr,nowArea;
    
    while (scanf("%d%d",&m,&n)!=EOF) {
        
        if (m+n==0) {
            break;
        }
        
        ans=0;
        memset(map,0,sizeof(map));
        memset(mapL,0,sizeof(mapL));
        memset(mapR,0,sizeof(mapR));
        
        for (i=1;i<=m;i++) {
            for (j=1;j<=n;j++) {
                scanf("%d",&map[j][i]);
                if (map[j][i]==1) {
                    map[j][i]=-1;
                }
            }
        }
        
        for (i=1;i<=m;i++) {
            area=1;
            for (j=1;j<=n;j++) {
                if (map[j][i]==0) {
                    mapL[j][i] = area++;
                } else {
                    area=1;
                }
            }
        }
        
        for (i=1;i<=m;i++) {
            area=1;
            for (j=n;j>=1;j--) {
                if (map[j][i]==0) {
                    mapR[j][i] = area++;
                } else {
                    area=1;
                }
            }
        }
        
        for (i=1;i<=m;i++) {
            for (j=n;j>=1;j--) {
                nowl = nowr = INF;
                if (map[j][i]==0) {
                    #ifdef debug
                    printf("j:%d i:%d\n------\n",j,i);
                    #endif
                    h=i;
                    while (h>=1) {
                        if (nowl>mapL[j][h]) {
                            nowl = mapL[j][h];
                        }
                        if (nowr>mapR[j+1][h]) {
                            nowr = mapR[j+1][h];
                        }
                        nowArea = (nowl+nowr)*(i-h+1);
                        #ifdef debug
                        printf("j:%d i:%d h:%d nowl:%d nowr:%d nowArea:%d\n",j,i,h,nowl,nowr,nowArea);
                        #endif
                        
                        if (ans<nowArea) {
                            ans = nowArea;
                        }
                        
                        h--;
                    }
                    
                    #ifdef debug
                    printf("\n\n");
                    #endif
                }
            }
        }
        
        printf("%d\n",ans);
    }
        
    return 0;   
}
