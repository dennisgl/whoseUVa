#include <stdio.h>
#define MAX 50

int dir[8][2] = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };

int puzzle[MAX][MAX];

int main() {
    int ptr[2];
    int m,n;
    int Num;
    int i,x,y;

    scanf("%d",&Num);

    for (i=1;i<=Num;i++) {
        scanf("%d%d",&m,&n);
        for (x=0;x<m;x++) {
            for (y=0;y<n;y++) {
                puzzle[x][y] = getch();
            }
        }
    }
}
