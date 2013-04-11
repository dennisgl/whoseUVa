#include <stdio.h>
#define MAX 1000000

int a[MAX],b[MAX];

int main() {
	int N,M;
	int i,j;
	int carry;
	
	scanf("%d",&N);
	for(i=1;i<=N;i++) {
		scanf("%d",&M);
		
		for (j=0;j<M;j++) {
			scanf("%d%d",&a[j],&b[j]);
		}
		
		carry=0;
		
		for (j=M-1;j>=0;j--) {
			a[j]+=b[j]+carry;
			carry = a[j]/10;
			a[j]%=10;
		}
		
		for (j=0;j<M;j++) {
			printf("%d",a[j]);
		}
		
		printf("\n");
	}
}
