#include <stdio.h>
#include <stdlib.h>
#define MAX 1200

typedef struct {
    int no;
    int days;
    int pen;  //penalty
    double div;  //divided
}Work;

int cmp(const void *a, const void *b) {
    Work *x = (Work *) a;
    Work *y = (Work *) b;

    if (x->div != y->div) {
        return x->div < y ->div ? 1 : 0;
    } else {
        return x->no - y->no;
    }
}

Work all[MAX];

int main() {
    int N,i;
    int casenum,j;
    scanf("%d",&N);
    
    for (i=1;i<=N;i++) {
        if (i!=1) printf("\n");
        scanf("%d",&casenum);
        for (j=0;j<casenum;j++) {
            scanf("%d%d",&all[j].days,&all[j].pen);
            all[j].div = (double)all[j].pen / all[j].days;
            
            all[j].no = j+1;
        }
        
        qsort(all,casenum,sizeof(all[0]),cmp);
        
        for (j=0;j<casenum;j++) {
            if (j!=0) printf(" ");
            printf("%d",all[j].no);
        }
        printf("\n");
        
    }

    return 0;
}
