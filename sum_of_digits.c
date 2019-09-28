#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int sum;
    scanf("%d", &n);
    sum = n % 10;
    for(int i;i<5;i++){
        n /= 10;
        sum += n % 10;
    }
    printf("%d",sum);
    //Complete the code to calculate the sum of the five digits on n.
    return 0;
}

