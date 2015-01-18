#include <stdio.h>

int main(){
    int v,t;

    while ( scanf("%d%d",&v,&t) != EOF ) {
          if ( t != 0 ){
             printf("%d\n",2*v*t);
          } else {
            printf("0\n");
          }
    }
    
    return 0;
}
