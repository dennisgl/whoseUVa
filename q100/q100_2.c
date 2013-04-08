#include <stdio.h>

int cycle (int n) {
    int length = 0;
    
    while (n != 1) {
          if ( n%2 == 1 ){
             n = n*3 + 1;
             length ++;
          } else {
                 n /= 2;
                 length ++;
          }
    }

    return length+1;
}

int main() {
    int i,j,oi,oj;
    int k;
    int temp;
    int now,max;
    while (scanf("%d %d",&i,&j) != EOF) {
          max = 0;
          oi = i; oj = j;
          if (i>j) {
             temp = i;
             i = j;
             j = temp;
          }
          for (k=i;k<=j;k++) {
              now = cycle(k);
              if (now>max) {
                     max = now;
              }
          }
          printf("%d %d %d\n",oi,oj,max);
          
    }
    
    return 0;
}
