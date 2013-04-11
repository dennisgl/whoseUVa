#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long add (long long a,char* buf1,char* buf2);
void rev (char* buf1,char* buf2);

long long int count = 0;

long long int add (long long p,char* buf1,char* buf2){
        long long added,j,k;
        char check1[100],check2[100];

        sprintf(buf1,"%d",p);

        rev(buf1,buf2);

        j = atoi(buf1);
        k = atoi(buf2);
        added = j+k;
       
        sprintf(check1,"%d",added);
        rev (check1,check2);

        count++;

        if (strcmp(check1,check2) == 0) {
           return added;
        } else {
          added = add (added,buf1,buf2);
        }
       
}

void rev (char* buf1,char* buf2) {
          int i,z;
          z=0;
          for (i=strlen(buf1)-1;i>=0;i--){
              buf2[z] = buf1[i];
              z++;
          }

          buf2[z] = '\0';
}

int main(){
    long long p;
    int N;
    int i;

    char buf1[100],buf2[100];
    long long result;

    scanf("%d",&N);

    for (i=1;i<=N;i++){
        scanf("%lld",&p);
        count = 0;
        result = add (p,buf1,buf2);
        printf("%lld %lld\n",count,result);
    }

    return 0;
} 
