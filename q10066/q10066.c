/*Algo: LCS
 2007/3/26 */

#include <stdio.h>
#include <string.h>
#define MAX 150

int n1len,n2len;
int table[MAX][MAX];

int n1[MAX],n2[MAX];


int main() {
    int i,j,count=0;
    
    while (scanf("%d%d",&n1len,&n2len)!=EOF) {
        if (n1len+n2len==0) {
            break;
        }
        
        memset(table,0,sizeof(table)); //initialize
        
        //input
        for (i=1;i<=n1len;i++) {
            scanf("%d",&n1[i]);
        }
        for (i=1;i<=n2len;i++) {
            scanf("%d",&n2[i]);
        }
        
        //LCS
        for (i=1;i<=n1len;i++) {
            for (j=1;j<=n2len;j++) {
                if (n1[i]==n2[j]) {
                    table[i][j] = table[i-1][j-1]+1;
                } else {
                    table[i][j] = table[i][j-1] > table[i-1][j] ? table[i][j-1]:table[i-1][j];
                }
            }
        }
        
        printf("Twin Towers #%d\n",++count);
        printf("Number of Tiles : ");
        printf("%d\n\n",table[n1len][n2len]);
    }
    return 0;   
}
