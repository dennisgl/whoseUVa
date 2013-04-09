#include <stdio.h>

int arr[100][100];
int arr2[100][100];
int sum,ans=0;

int main() {
	int n,i,j,k,l;
	
	//freopen("test.in","r",stdin);
	
	scanf("%d",&n);
	
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			scanf("%d",&arr[i][j]);
		}
	}

    for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (j==0) {
				arr2[i][j] = arr[i][j];
				continue;
			}
			arr2[i][j] = arr[i][j] + arr[i][j-1];
		}
	}

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (j==0) {
				arr[j][i] = arr2[j][i];
			}
			arr[j][i] = arr[j-1][i] + arr2[j][i];
		}
	}

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			for (k=0;k<n;k++) {
				for (l=0;l<n;l++) {
					if (!(k>i&&l>j)) {
						continue;
					}
					
					sum = arr[l][k] - arr[j-1][k] - arr[l][i-1] +arr[j-1][i-1];
					/*if (j-1>0) {
						sum -= arr[j-1][k];
					}
					if (i-1>0) {
						sum -= arr[l][i-1];
					}
					if (j-1>0&&i-1>0) {
					 	sum += arr[j-1][i-1];
					}*/
					
					if (sum>ans) {
						ans = sum;
					}
				}
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}
