#include <stdio.h>

int count;

int main() {
    int N; //number of inputs
    unsigned long P,R,tem; //P:primitive number R:Reverse tem:temporary var

    int i; //loop counters
    
    scanf("%d",&N);

    for (i=1;i<=N;i++){
        count = 0;
        
        scanf ("%lu",&P);

        while (1){
              R = 0;
              
              tem = P;
              while (tem) {
                    R = R*10 + tem%10;
                    tem = (tem-tem%10) / 10;
              }

              if (P == R && count !=0) {
                 break;
              }
              count++;
              
              P += R;
        }

        printf("%d %lu\n",count,P);
    }

    return 0;
}
