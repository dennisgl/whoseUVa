#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() {
    int n;
    int *A;
    int * check;
    int i;
    int abs_dif;

    while (scanf("%d",&n) != EOF) {
          A = (int *)malloc(sizeof(int)*n);
          check = (int *)malloc(sizeof(int)*n);
          for (i=0;i<n;i++) {
              check[i] = 0;
          }
          
          for (i=0;i<n;i++) {
              scanf("%d",&A[i]);
          }

          for (i=0;i<n-1;i++) {
              abs_dif = abs(A[i] - A[i+1]);

              if (abs_dif >= n || abs_dif == 0) {
                 break;
              }

              if (check[abs_dif] == 0) {
                 check[abs_dif] = abs_dif;
              } else {
                break;
              }
          }

          if ( !(i < n-1) ) {
             printf("Jolly\n");
          } else {
            printf("Not jolly\n");
          }

          free(A);
    }
}
