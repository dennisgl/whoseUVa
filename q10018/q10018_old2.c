#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
int digits = 0;

void rev (int* int1,int* int2,int digits) {
         int i,j=0;
         for (i=digits-1;i>=0;i--) {
            int2[j] = int1[i];
            j++;
         }
}

unsigned long itoi (int* a , int digits) {
    int i;
    unsigned long result=0;
    for (i=0;i<digits;i++) {
        result = result*10 + a[i];
    }
    return result;
}

int main(){
    int N;
    int i,j;

    int int1[100],int2[100];
    char buf[100];
    unsigned long result;

    scanf("%d",&N);

    for (i=1;i<=N;i++){
    
        count = 0;
        
        scanf("%s",buf);
        digits = strlen(buf);
        for (j=0;j<digits ;j++) {
            int1[j] =(int)(buf[j] - '0');
        }
        
        while (1) {
        
              rev(int1,int2,digits);  /*Reverse*/
              
              for (j=0;j<digits;j++) {            /*Checking if the "Reverse&Add" is over*/

                  if (int1[j] != int2[j]) {
                     break;
                  }
              }
              if ( !(j<digits) && count != 0 ) {
                 break;
              }
              
              result = itoi(int1,digits) + itoi(int2,digits); /*Add*/

              sprintf(buf,"%U",result);
              digits = strlen(buf);
              for (j=0;j<digits;j++) {
                  int1[j] =(int)(buf[j] - '0');
              }

              count++;
        }

        printf("%lu %lu\n",count,result);

    }

    return 0;
}
