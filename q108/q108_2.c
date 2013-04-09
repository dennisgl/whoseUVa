#include <stdio.h>
#include <string.h>

int arr[100][100];

int main() {
	int N;
	int x,y,x2,y2;
	int tmp,sum = -10000000;
	
	scanf("%d",&N);

	
	for (y=0;y<N;y++) {
		for (x=0;x<N;x++) {
			scanf("%d",&arr[x][y]);
		}
	}

	for (y=0;y<N;y++) {
		for (x=1;x<N;x++) {
			arr[x][y] = arr[x][y] + arr[x-1][y];
		}
	}

	for (x=0;x<N;x++) {
		for (y=1;y<N;y++) {
			arr[x][y] = arr[x][y] + arr[x][y-1];
		}
	}	

/*
	for (y=0;y<N;y++) {
		for (x=0;x<N;x++) {
			printf("%2d ",arr[x][y]);
		}
		printf("\n");
	}
*/

	for (y=0;y<N;y++) {
		for (x=0;x<N;x++) {
			for (y2=0;y2<N;y2++) {
				for (x2=0;x2<N;x2++) {
					if (!(y2>=y && x2>=x)) {
						continue;
					}
					
					tmp = arr[x2][y2] ;
					if (y>0) 
						tmp -= arr[x2][y-1];
					if (x>0) 
						tmp -= arr[x-1][y2];
					if (x>0&&y>0)
						tmp += arr[x-1][y-1];
					
					if (tmp > sum) {
						sum = tmp;
					}
				}
			}
		}
	}
	
	
	printf("%d\n",sum);
	
	//system("PAUSE");
	
	return 0;	
}
