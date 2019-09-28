#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i]=0;
    }
    for(char *i = s;*i!=NULL;i++){
        if(*i=='0'){
            arr[0]++;
        }else if(*i=='1'){
            arr[1]++;
        }else if(*i=='2'){
            arr[2]++;
        }else if(*i=='3'){
            arr[3]++;
        }else if(*i=='4'){
            arr[4]++;
        }else if(*i=='5'){
            arr[5]++;
        }else if(*i=='6'){
            arr[6]++;
        }else if(*i=='7'){
            arr[7]++;
        }else if(*i=='8'){
            arr[8]++;
        }else if(*i=='9'){
            arr[9]++;
        }   
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
