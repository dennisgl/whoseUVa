#include <stdio.h>

int main() {
    unsigned n1,n2,carry,count;

    
    while (scanf("%u%u",&n1,&n2)!=EOF) {
        if (n1+n2==0) {
            break;
        }
        count=carry=0;
        
        while (n1>0 || n2>0) {
                            
            if (n1%10+n2%10+carry>=10) {
                carry = 1;
                count++;
            } else {
                carry = 0;
            }
                
            n1/=10;
            n2/=10;

        }   
         
         
        if (count==0) {
            printf("No carry operation.\n");
        } else if (count==1){
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n",count);
        }
    }
    
    
    return 0;   
}
