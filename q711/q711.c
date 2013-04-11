#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

int marble_i[6+1];

int solve(int target) {
    int value[200000];
	int i,j,k;

	#ifdef DEBUG
	printf("target:%d\n",target);
	#endif
	
	memset(value,0,sizeof(int)*200000);
	
	value[0] = 1;
	
	for (i=6;i>=1;i--) {
		for (j=target;j>=0;j--) {
			if (value[j]==1) {
				for (k=1;k<=marble_i[i];k++) {
					#ifdef DEBUG
					printf("j:%d i:%d k:%d (j+i*k):%d  marble_i[i]:%d\n",j,i,k,j+i*k,marble_i[i]);
					#endif

					value[j+i*k] = 1;
				}
			}
			
			if (value[target]) {
				return 1;
			}
		}
	}
	
	return 0;
}

int main() {
	int n,i;
	int check;
	
	for (n=1;;n++) {
		check = 0;

		for (i=1;i<=6;i++) {
			scanf("%d",&marble_i[i]);
			check += marble_i[i]*i;;
		}
		
		if (check==0) {
			break;
		}
		
		printf("Collection #%d:\n",n);
		
		if (check%2==0) {
			check /= 2;
			if (solve(check)){
				printf("Can be divided.\n");
			} else {
                printf("Can't be divided.\n");
			}
		} else {
            printf("Can't be divided.\n");
		}
		printf("\n");
	}

	#ifdef DEBUG
	system("PAUSE");
	#endif

	return 0;
}
