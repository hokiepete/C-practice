#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

int dist_char(const char* a){
    int dist = 0;
    /*
    int len = strlen(a);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(a[i]==a[j]){
                break;
            }
            dist++;
        }
    }*/
    while (*a != '\0') {
        if (!strchr(a + 1, *a))
            dist++;
        a++;
    }
    return dist;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int diff = dist_char(a)-dist_char(b);
    return (diff) ? diff : lexicographic_sort(a,b);
}

int sort_by_length(const char* a, const char* b) {
    int diff = strlen(a)-strlen(b);
    return (diff) ? diff : lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    int sorted = 0;
    while(!sorted){
        sorted = 1;
        for(int i=0;i<len-1;i++){
            if(cmp_func(arr[i],arr[i+1])>0){
                char *t= arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                sorted = 0;
            }
        }
    }
}



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}