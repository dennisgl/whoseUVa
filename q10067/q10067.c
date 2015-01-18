#include <stdio.h>
#define Q_MAX 100000

typedef struct {
    char d[4];  //four digits
    int num;
} Num;

Num start,goal;

int method[8][4] = {{-1,0,0,0},{1,0,0,0},{0,-1,0,0},{0,1,0,0},
                    {0,0,-1,0},{0,0,1,0},{0,0,0,-1},{0,0,0,1}};

int flag[10000];

int digits2Num(char a, char b, char c, char d) {
    return a*1000+b*100+c*10+d;
}

Num queue[Q_MAX];
int front,rear;

int main() {
    int caseNum,i;
    int n,j;
    int k;
    char buf[4];
    
    scanf("%d",&caseNum);
    
    for (i=1;i<=caseNum;i++) {
        memset(flag,0,sizeof(flag));

        for (j=0;j<4;j++) {
            scanf("%d",&buf[0]);
            start.d[j] = buf[0]-'0';
        }
        start.num = digits2Num (start.d[0],start.d[1],start.d[2],start.d[3]);
        
        for (j=0;j<4;j++) {
            scanf("%d",&buf[0]);
            goal.d[j] = buf[0]-'0';
        }
        goal.num = digits2Num (goal.d[0],goal.d[1],goal.d[2],goal.d[3]);
        
        scanf("%d",&n);
        for (j=0;j<n;j++) {
            for (k=0;k<4;k++) scanf("%d",&buf[k]);
            flag[digits2Num (buf[0],buf[1],buf[2],buf[3])] = 1;
        }
        
        
    }
    return 0;
}
