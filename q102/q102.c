#include <stdio.h>

int bottles[3][3];
char *ans;

//0B 1G 2C

int main() {
	int i,j;
	int sum,now,max;

	while(1) {
		sum=0;
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				if (scanf("%d",&bottles[i][j])==EOF)
				    return 0;
				    
				sum += bottles[i][j];
			}
		}
		
		now = max = bottles[0][0] + bottles[1][2] + bottles[2][1];
		ans = "BCG";
		
		now = bottles[0][0] + bottles[1][1] + bottles[2][2];
		if (max < now) {
			max = now;
			ans = "BGC";
		}
		
 		now = bottles[0][2] + bottles[1][0] + bottles[2][1];
		if (max < now) {
			max = now;
			ans = "CBG";
		}
		
		now = bottles[0][2] + bottles[1][1] + bottles[2][0];
		if (max < now) {
			max = now;
			ans = "CGB";
		}
		
		now = bottles[0][1] + bottles[1][0] + bottles[2][2];
		if (max < now) {
			max = now;
			ans = "GBC";
		}
		
		now = bottles[0][1] + bottles[1][2] + bottles[2][0];
		if (max < now) {
			max = now;
			ans = "GCB";
		}
		
		printf("%s %d\n",ans,sum-max);
	}
	return 0;
}
