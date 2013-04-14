#include <stdio.h>
#include <string.h>

#define MAX 110
#define INF 2100000000

int map[MAX][MAX];


int main() {
	int C,S,Q;
	int c1,c2,d;
	int i,j,k;
	int count=1;
	
	while (scanf("%d%d%d",&C,&S,&Q)!=EOF) {
		if (C+S+Q==0) break;
		
		if (count!=1) printf("\n");
		
		for (i=1;i<=C;i++) {
			for (j=1;j<=C;j++) {
				map[i][j] = INF;
			}
		}
		
		for (i=1;i<=S;i++) {
			scanf("%d%d%d",&c1,&c2,&d);
			map[c1][c2] = d;
			map[c2][c1] = d;
		}
		
		for (k=1;k<=C;k++) {
			for (i=1;i<=C;i++) {
				for (j=1;j<=C;j++) {
					if (map[i][k]==INF||map[k][j]==INF) {
						continue;
					}
					//printf("%c %c %c\n",'A'+i-1,'A'+j-1,'A'+k-1);
					//printf("%d %d %d\n",map[i][j],map[i][k],map[k][j]);
					if (map[i][j]>(map[i][k]>map[k][j]?map[i][k]:map[k][j])) {
						map[i][j] = map[i][k]>map[k][j]?map[i][k]:map[k][j];
						map[j][i] = map[i][k]>map[k][j]?map[i][k]:map[k][j];
					}
				}
			}
		}
		
		
		printf("Case #%d\n",count++);
		
		for (i=1;i<=Q;i++) {
			scanf("%d%d",&c1,&c2);
			if (map[c1][c2]==INF) {
				printf("no path\n");
			} else {
				printf("%d\n",map[c1][c2]);
			}
		}
	}
	
	
	return 0;
}
