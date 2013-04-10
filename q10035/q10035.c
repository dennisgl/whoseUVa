#include <stdio.h>

int a[15],b[15];
int ad=-1,bd=-1; //ad: a's digit number   bd: b's digit number

int main() {
	unsigned n1,n2;
	int digits;
	int carry,carry_count;
	int i;
	
	while (scanf("%u%u",&n1,&n2)!=EOF) {

		if (n1==0 && n2==0 || n1<0 || n2<0) {
			break;
		}

		ad = bd = 0;

		carry_count = carry = 0;
		while (n1) {
			ad++;
			a[ad] = n1%10;
			n1/=10;
		}
		
		while (n2) {
			bd++;
			b[bd] = n2%10;
			n2/=10;
		}
		/*
		for (i=0;i<10;i++) {
			printf("%d",a[i]);
		}
		
		printf("\n");
		
		for (i=0;i<10;i++) {
			printf("%d",b[i]);
		}
		
		printf("\n");
		*/
		if (ad>bd) {
			digits = ad;
		} else {
			digits = bd;
		}
		/*
		printf("d:%d\n",digits);
		*/
		for (i=0;i<=digits;i++) {
			a[i] = a[i] + b[i] + carry;
			carry = a[i]/10;
			/*
			printf("c:%d\n",carry);
			*/
			if (carry!=0) {
				carry_count++;
			}
			a[i] %= 10;
		}
		
		if (carry_count!=0) {
			printf("%d carry operations.\n",carry_count);
		} else {
			printf("No carry operations.\n");
		}
	}
	return 0;
}
