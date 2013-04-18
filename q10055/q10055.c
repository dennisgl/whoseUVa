#include <stdio.h>
#include <stdlib.h>

int main() {
    long long a,b,result;
    while (scanf("%lld %lld",&a,&b) != EOF){
          result = a-b;
          if (result<0) {
             result = result - 2*result;
          }
          printf("%lld\n",result);
    }

    return 0;
}
