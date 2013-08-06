#include <stdio.h>
#include <string.h>

#define MAX 25

int blocks[MAX][MAX],btop[MAX];
int tmp[MAX],ttop;
int pos[MAX];

int n;

char cmd1[10],cmd2[10];
int t1,t2;

/**************************/

void moveOnto() {
    int t1p,t2p,now;

    t1p = pos[t1];
    t2p = pos[t2];
    
    while (blocks[t1p][btop[t1p]]!=t1) {
        now = blocks[t1p][btop[t1p]--];
        pos[now] = now;
        blocks[now][++btop[now]] = now;
    }
    while (blocks[t2p][btop[t2p]]!=t2) {
        now = blocks[t2p][btop[t2p]--];
        pos[now] = now;
        blocks[now][++btop[now]] = now;
    }
    
    blocks[t2p][++btop[t2p]] = t1;
    pos[t1] = t2p;
    btop[t1p]--;
}

void moveOver() {
    int t1p,t2p,now;
    
    t1p = pos[t1];
    t2p = pos[t2];
    
    while (blocks[t1p][btop[t1p]]!=t1) {
        now = blocks[t1p][btop[t1p]--];
        pos[now] = now;
        blocks[now][++btop[now]] = now;
    }
    
    blocks[t2p][++btop[t2p]] = t1;
    pos[t1] = t2p;
    btop[t1p]--;
}

void pileOnto() {
    int t1p,t2p,now;
    
    t1p = pos[t1];
    t2p = pos[t2];
    
    while (blocks[t2p][btop[t2p]]!=t2) {
        now = blocks[t2p][btop[t2p]--];
        pos[now] = now;
        blocks[now][++btop[now]] = now;
    }
    
    do {
        tmp[++ttop] = blocks[t1p][btop[t1p]--];
    } while (tmp[ttop] != t1);
    
    while (ttop!=-1) {
        blocks[t2p][++btop[t2p]] = tmp[ttop];
        pos[tmp[ttop]] = t2p;
        ttop--;
    }
}

void pileOver() {
    int t1p,t2p,now;
    
    t1p = pos[t1];
    t2p = pos[t2];
    
    do {
        tmp[++ttop] = blocks[t1p][btop[t1p]--];
    } while (tmp[ttop] != t1);
    
    while (ttop!=-1) {
        blocks[t2p][++btop[t2p]] = tmp[ttop];
        pos[tmp[ttop]] = t2p;
        ttop--;
    }
}

void printans() {
    int i,j;
    
    for (i=0;i<n;i++) {
        printf("%d:",i);
        for (j=0;j<=btop[i];j++) {
            if (j==0) {
                printf(" ");
            }
            printf("%d",blocks[i][j]);
            if (j!=btop[i]) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i,s=0;
    
    
    while (scanf("%d",&n)!=EOF) {
        
        memset(blocks,0,sizeof(blocks));
        memset(btop,0xff,sizeof(btop));
        memset(tmp,0,sizeof(tmp));
        ttop = -1;
             
        for (i=0;i<n;i++) {
            blocks[i][++btop[i]] = i;
            pos[i] = i;
        }
             
        while (1) {
            scanf("%s",cmd1);
            if (cmd1[0]=='q') {
                break;
            }
            scanf("%d%s%d",&t1,cmd2,&t2);
            
            if (pos[t1]==pos[t2]) {
                continue;
            }
            
            if (cmd1[0] == 'm') {
                if (cmd2[1] == 'n') {
                    moveOnto();
                } else {
                    moveOver();
                }
            } else {
                if (cmd2[1] == 'n') {
                    pileOnto();
                } else {
                    pileOver();
                }
            } 
        }    
            
            printans();             
    }  
    
    return 0;   
}
