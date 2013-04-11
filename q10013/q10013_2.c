#include <stdio.h>
#define MAX 1000000

int a[MAX],b[MAX];

int main() {
    int i,j,n,len,carry;
    
    scanf("%d",&n);
    
    for (i=1;i<=n;i++) {
        scanf("%d",&len);
        
        for (j=0;j<len;j++) {
            scanf("%d%d",&a[j],&b[j]);
        }
        
        carry=0;
        
        for (j=len-1;j>=0;j--) {
            a[j] += b[j]+carry;
            carry = a[j]/10;
            a[j] %= 10;
        }
         
        if (carry!=0) {
            printf("1");
        }
        
        for (j=0;j<len;j++) {
            printf("%d",a[j]);
        }
        
        printf("\n");
        if (i!=n) {
            printf("\n");
        }   
    }
    
    return 0;   
}
