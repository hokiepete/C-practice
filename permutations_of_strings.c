#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char**s,int x, int y){
    char* temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}

void reverse(char** s, int x, int y){
    while(x<y){
        swap(s,x,y);
        y--;
        x++;
    }
}

int get_lower(char** s,int n){
    int lower=-1;
    for(int i=n-1;i>0;i--){
        if(strcmp(s[i-1],s[i])<0){
            lower = i-1;
            break;
        }

    }
    /*
    while(lower>0 && strcmp(s[lower-1],s[lower])>=0){
        lower--;
    }
    */
    return lower;
}

int get_upper(char** s, int n, int lower){
    int upper=n-1;
    for(int i = n-1; i>lower;i--){
        if(strcmp(s[lower],s[i])<0){
            upper = i;
            break;
        }

    }
    /*
    while(strcmp(s[lower+1],s[upper])>=0){
        upper--;
    }
    */
    return upper;
}

int next_permutation(int n, char **s)
{

    int lower = get_lower(s,n);
    //printf("%d\n",lower);
    if(lower < 0){
        return 0;
    }
    int upper = get_upper(s, n, lower);
    //printf("%d\n",upper);
    swap(s,lower,upper);
    reverse(s,lower+1,n-1);
    return 1;
    
}
int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}