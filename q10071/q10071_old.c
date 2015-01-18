#include <stdio.h>

int main(){
    int v,v0,t,a,s;

    while ( scanf("%d%d",&v,&t) != EOF ) {
          if ( t != 0 ){
             a = v/t;
             v0 = v - a*t;
             s = v0*2*t + 0.5*a*4*t*t;
             printf("%d\n",s);
          } else {
            printf("0\n");
          }
    }
    
    return 0;
}
