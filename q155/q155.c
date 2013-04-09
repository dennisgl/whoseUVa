#include <stdio.h>

int count;
int tx,ty;

void solve(int k,int x,int y) {

    if (tx>=x-k&&tx<=x+k&&ty>=y-k&&ty<=y+k) {
        count++;
    }
    
    if (!(k>1)) {
        return;
    }
    
    solve(k/2,x-k,y+k);
    solve(k/2,x+k,y+k);
    solve(k/2,x-k,y-k);
    solve(k/2,x+k,y-k);
}

int main() {
    int K;

    while (scanf("%d%d%d",&K,&tx,&ty)!=EOF) {
        if (K==0&&tx==0&&ty==0) {
            break;
        }
        count=0;
        solve(K,1024,1024);
        printf("%3d\n",count);
    }

    return 0;
}
