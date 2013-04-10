#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char a;
    int count;
} Letter;

Letter all[26];

int cmp(const void *a, const void *b) {
    Letter *p1,*p2;
    p1 = (Letter *) a;
    p2 = (Letter *) b;
    
    if (p1->count != p2->count) {
        return p2->count - p1->count;
    } else {
        return p1->a - p2->a;
    }
}

int main() {
    int N;
    char now;
    int i;
    
    for (i=0;i<26;i++) {
        all[i].a='A'+i;
        all[i].count = 0;
    }

    scanf("%d",&N);
    
    while (scanf("%c",&now)!=EOF) {
        if (!((now>=65&&now<=90)||(now>=97&&now<=122))) {
            continue;
        }
        
        if (now>=97) {
            now -=32;
        }
        
        all[now-'A'].count++;
    }

    qsort(all,26,sizeof(all[0]),cmp);

    for (i=0;i<26;i++) {
        if (all[i].count==0) {
            break;
        }
        printf("%c %d\n",all[i].a,all[i].count);
    }

    return 0;
}
