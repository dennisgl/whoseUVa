#include <stdio.h>

int cy (long int n) {
    int l = 0;
    
    while (n != 1) {
          if ( n%2 == 1 ){
             n = n*3 + 1;
             l ++;
          } else {
                 n /= 2;
                 l ++;
          }
    }

    return l+1;
}

int main() {
    long int i,j,oi,oj;
    int k;
    int t;
    int n,m;
    while (scanf("%d %d",&i,&j) != EOF) {
          m = 0;
          oi = i; oj = j;
          if (i>j) {
             t = i;
             i = j;
             j = t;
          }
          for (k=i;k<=j;k++) {
              n = cy(k);
              if (n>m) {
                     m = n;
              }
          }
          printf("%d %d %d\n",oi,oj,m);
          
    }
    
    return 0;
}
