#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int dist(int size, int i, int j){
    int dist_i, dist_j;
    if(i>=size){
        dist_i = i-size+2;
    }else{
        dist_i = size-i;
    }
    if(j>=size){
        dist_j = j-size+2;
    }else{
        dist_j = size-j;
    }
    if(dist_i>=dist_j){
        return dist_i;
    }else{
        return dist_j;
    }
}

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            if(j==2*n-2){
                printf("%d\n",dist(n,i,j));
            }else{
                printf("%d ",dist(n,i,j));
            }
        }
    }
    
    return 0;
}

