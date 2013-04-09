#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

int target;
char tree[MAX];
int solved;

char *run(int sum, char *ptr, int len) {
    int num=0;
    int leaf=0;
    int isleaf = 1;
    
    while (isdigit(*ptr)) {
        num = num*10 + *ptr-'0';
        ptr++;
    }
    
    if (*ptr=='\0') gets(&tree[len]);
    while (leaf < 2) {
        if (*ptr == '(') {
            ptr++;
            if (*ptr==')') { leaf++; continue; }
            isleaf = 0;
            ptr = run(sum+num,ptr,strlen(tree));
            if (solved==1) return ;
            if (*ptr=='\0') gets(&tree[len]);
        }
        
        ptr++;
    }
    
    if (isleaf==1) {
        ptr++;
        if (sum+num == target) solved = 1;
        return ptr;
    }
}

int main() {
    char *ptr;

    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    while (scanf("%d",&target)!=EOF) {
        solved=0;
        gets(tree);
        ptr = strchr(tree,'(');
        ptr++;
        if (*ptr == ')') {
            printf("no\n");
            continue;
        }
        run(0,ptr,strlen(tree));
        printf("%s\n",solved==1?"yes":"no");
    }

    return 0;
}
