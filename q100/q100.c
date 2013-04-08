#include <stdio.h>

void cycle (int n,int *counter);
//this is for finding the "3n+1 cycle", it's recursive

int main(){
    int n=0; //the number to be "3n+1"
    int i=0,j=0; //input
    int k =0; //counter
    int counter=0; //cycle length
    int max = 0; //MAX cycle-length

    while (scanf("%d %d",&i,&j) != EOF) {
          int tem = 0; //temp variable to do swaping
          int isOppsite = 0; //the bool flag to mark out if i is bigger than j
          max = 0; //initialize
          if (i>j){ //obviously, this action is for swaping i,j if needed
             tem = i;
             i = j;
             j = tem;
             isOppsite = 1;
          }
          
          for ( k = i;k <= j;k++){
              counter = 0; //initialize
          
              cycle (k,&counter); //step into the recursive func.
              if (max == 0){ //comparing, if there's another bigger circle-length then replace it
                 max = counter;
              } else if (counter > max) {
                     max = counter;
              }
          }
          if (isOppsite != 1){                  //two kinds of outputing method
             printf("%d %d %d\n",i,j,max);
          } else {
             printf("%d %d %d\n",j,i,max);
          }
    }
}

void cycle (int n,int *counter) {

     short int isOne = 0;

     if ( n == 1) {             //these are 3n+1 rules, just apply it
        isOne = 1;
     } else if ( n%2 == 1 ){
            n = n*3 + 1;
     } else {
            n /= 2;
     }

     *counter = *counter + 1;   //circle-length +1

     if (isOne) {  //if the item is 1, then end this recursive func.
        return;
     } else {
       cycle ( n , counter); //otherwise, continue the recursive func.
     }

     return;
     
}
