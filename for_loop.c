#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for(int n=a;n<=b;n++){
        if(n==1){
            printf("%s","one\n");
        }else if(n==2){
            printf("%s","two\n");
        }else if(n==3){
            printf("%s","three\n");
        }else if(n==4){
            printf("%s","four\n");
        }else if(n==5){
            printf("%s","five\n");
        }else if(n==6){
            printf("%s","six\n");
        }else if(n==7){
            printf("%s","seven\n");
        }else if(n==8){
            printf("%s","eight\n");
        }else if(n==9){
            printf("%s","nine\n");
        }else if(n>9 && n % 2 == 0){
            printf("%s","even\n");
        }else{
            printf("%s","odd\n");
        }
    }

    return 0;
}

