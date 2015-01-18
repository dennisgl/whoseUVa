#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#define DEBUG

double list[100+1][10];
double ans;
int k,n;

void solve() {
	int i,j;

	for (i=1;i<=n;i++) {
		for (j=0;j<=k;j++) {
			if (i==1) {
				list[i][j] = 1;
				continue;
			}

			list[i][j] += list[i-1][j];

			if (j==0) {
                list[i][j] += list[i-1][j+1];
			} else if (j==9) {
                list[i][j] += list[i-1][j-1];
			} else {
                list[i][j] += list[i-1][j+1];
                list[i][j] += list[i-1][j-1];
			}
		}
	}

	#ifdef DEBUG
	for (i=1;i<=n;i++) {
		for (j=0;j<=k;j++) {
			printf("%5.0f ",list[i][j]);
		}
		printf("\n");
	}
	#endif

	for (i=0;i<=k;i++) {
		#ifdef DEBUG
        printf("%5.0f \n",list[n][i]);
        #endif
		ans += list[n][i];
	}

	#ifdef DEBUG
	printf("%5.0f \n",ans);
	#endif

}

int main() {

	while(scanf("%d%d",&k,&n)!=EOF) {
		ans = 0;

		if (n==1) {
			printf("100.00000\n");
			continue;
		}

		memset(list,0,sizeof(double)*(100+1)*10);

		solve();

		printf("%0.5f\n",ans/pow(k+1,n)*100);
	}

	#ifdef DEBUG
	system("PAUSE");
	#endif

	return 0;
}
