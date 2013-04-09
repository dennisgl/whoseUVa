#include <stdio.h>
#include <string.h>

#define INF -135792468
//#define debug
#define debug2
#define MAX 10000

char tree[MAX];
int ptr = 0;
int solved = 0;
int sum = 0;
int n;

void fill() {
    if (tree[ptr]=='\0') {
        gets(&tree[strlen(tree)]);
        #ifdef debug
        printf("tree:%s\n",tree);
        #endif
    }

}

int getNum() {
    int p,s,e,flag=0;
    char nums[10];
    int number;

    p = ptr;
    s = ptr;

    while (1) {
        fill();
        if (tree[p]==')') {
            break;
        }
        if ((tree[p]=='-'||(tree[p]>='0'&&tree[p]<='9')) && flag == 0) {
            s=p;
            #ifdef debug
            printf("tree[s]:%c\n",tree[s]);
            #endif
            flag=1;
        }

        if (flag) {
            if (!(tree[p]=='-'||(tree[p]>='0'&&tree[p]<='9'))) {
                break;
            }
        }

        p++;
    }
    e = p;

    fill();

    if (s==e) {
        while (tree[p]!=')') {
            fill();
            p++;
        }
        ptr = p+1;
        return INF;
    } else {
        strncpy(nums,&tree[s],e-s+1);
        sscanf(nums,"%d",&number);
        return number;
    }
}

int solve(int now) {
    int isLeaf=0,nums,i,num;

    sum += now;
    #ifdef debug
    printf("sum:%d\nnow:%d\nptr:%d\n",sum,now,ptr);
    #endif
    while (1) {
        fill();
        if (tree[ptr]=='(') {
            ptr++;
            num = getNum();
            #ifdef debug
            printf("num:%d\n------\n",num);
            #endif
            if (num==INF) {
                sum -= now;
                return INF;
            }
            for (i=1;i<=2;i++) {
                if (solve(num)==INF) {
                    isLeaf++;
                }
                #ifdef debug
                printf("sum:%d now:%d i:%d isLeaf:%d\n------\n",sum,now,i,isLeaf);
                #endif
            }

            if (isLeaf == 2) {
                #ifdef debug
                printf("now:%d sum+num:%d\n------\n",now,sum+num);
                #endif
                if ((sum+num)==n) {
                    solved = 1;
                }
            }
            sum -= now;
            return (num == INF) ? INF : 1;
        } else {
            ptr++;
        }
    }
}

int main() {
    char tmp[MAX],ptr2;

    #ifdef debug2
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    while (gets(tmp)!=NULL) {
        ptr=ptr2=0;
        solved=0;
        memset(tree,0,sizeof(tree));

        sscanf(tmp,"%d",&n);
        strcpy(tree,strchr(tmp,' '));

        if (strcmp(tree,"()")==0) {
            printf("no\n");
            continue;
        }
        #ifdef debug
        printf("tmp:%s\nn: %d\ntree:%s\n-------\n",tmp,n,tree);
        #endif
        solve(0);
        if (solved==1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
