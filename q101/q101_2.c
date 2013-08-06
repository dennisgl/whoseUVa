#include <stdio.h>
#include <string.h>
#define MAX 25

#define debug

char blocks[MAX][MAX+100];
int ptr[MAX];

char cmd1[10],cmd2[10];
int t1,t2;

int n;

void add(char c,int p) {
    int len;
    len = strlen(blocks[p]);
    

    blocks[p][len+1] = '\0';
    blocks[p][len] = c;

}

int find(int a) {
    int i;
    
    for (i=0;i<strlen(blocks[ptr[a]]);i++) {
        if (blocks[ptr[a]][i] == '0'+a) {
            return i;
        }
    }
}

void moveOnto() {
    int t1p,t2p;
    int i;
    int valid=0;
    char *s1 = blocks[ptr[t1]];
    char *s2 = blocks[ptr[t2]];
    
    t1p = find(t1);
    t2p = find(t2);
    
    for (i=strlen(s1)-1;i>=t1p+1;i--) {
        add(s1[i],s1[i]-'0');
        ptr[s1[i]-'0'] = s1[i]-'0';
        s1[i] = '\0';
    }
    for (i=strlen(s2)-1;i>=t2p+1;i--) {
        if (s2[i]-'0' == t2p) {
            return;
        }
    }    
    for (i=strlen(s2)-1;i>=t2p+1;i--) {
        add(s2[i],s2[i]-'0');
        ptr[s2[i]-'0'] = s2[i]-'0';
        s2[i] = '\0';
    }
    add(t1+'0',ptr[t2]);
    s1[t1p] = '\0';
    #ifdef debug
    printf("t1:%d t2:%d\n",t1,t2);
    #endif
    ptr[t1] = ptr[t2];
}

void moveOver() {
    int t1p,t2p;
    int i;
    char *s1 = blocks[ptr[t1]];
    char *s2 = blocks[ptr[t2]];
    
    t1p = find(t1);
    t2p = find(t2);
    
    for (i=strlen(s1)-1;i>=t1p+1;i--) {
        add(s1[i],s1[i]-'0');
        ptr[s1[i]-'0'] = s1[i]-'0';
        s1[i] = '\0';
    }
    add('0'+t1,ptr[t2]);
    s1[t1p] = '\0';
    ptr[t1] = ptr[t2];
}

void pileOnto(){
    int t1p,t2p;
    int i;
    char *s1 = blocks[ptr[t1]];
    char *s2 = blocks[ptr[t2]];
    
    t1p = find(t1);
    t2p = find(t2);
    
    for (i=strlen(s2)-1;i>=t2p+1;i--) {
        add(s2[i],s2[i]-'0');
        ptr[s2[i]-'0'] = s2[i]-'0';
        s2[i] = '\0';
    }
    
    for (i=strlen(s1)-1;i>=t1p;i--) {
        ptr[s1[i]-'0'] = ptr[t2];
    }
    
    strcpy(&s2[strlen(s2)],&s1[t1p]);
    memset(&s1[t1p],'\0',sizeof(char)*(strlen(s1)-t1p+1));
}

void pileOver() {
    int t1p,t2p;
    int i;
    char *s1 = blocks[ptr[t1]];
    char *s2 = blocks[ptr[t2]];
    
    t1p = find(t1);
    t2p = find(t2);

    for (i=strlen(s1)-1;i>=t1p;i--) {
        ptr[s1[i]-'0'] = ptr[t2];
    }

    strcpy(&s2[strlen(s2)],&s1[t1p]);
    memset(&s1[t1p],'\0',sizeof(char)*(strlen(s1)-t1p+1));
}

int printans() {
    int i,j;
    
    
    for (i=0;i<n;i++) {
        printf("%d: ",i);
        for (j=0;j<strlen(blocks[i]);j++) {
            printf("%d",blocks[i][j]-'0');
            if (j!=strlen(blocks[i])-1) {
                printf(" ");
            }
        }
        printf("\n");
    }   
}

void move() {
    if (cmd2[1]=='n') {
        moveOnto();
    } else {
        moveOver();
    }
}

void pile() {
    if (cmd2[1]=='n') {
        pileOnto();
    } else {
        pileOver();
    }
}

int main() {
    int i;
    
    /*#ifdef debug
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif*/
    
    while (scanf("%d",&n)!=EOF) {
        for (i=0;i<n;i++) {
            blocks[i][0] = '0'+i;
            blocks[i][1] = '\0';
            ptr[i] = i;
        }
        
        while (1) {
            scanf("%s",cmd1);
            
            if (cmd1[0]=='q') {
                break;
            }
            scanf("%d%s%d",&t1,cmd2,&t2);
            if (ptr[t1]==ptr[t2]) {
                continue;
            }
            
            if (strcmp(cmd1,"move")==0) {
                move();
            } else {
                pile();
            }
            #ifdef debug
            printans();
            #endif
        }
         
         printans();       
    }
    
    return 0;   
}
