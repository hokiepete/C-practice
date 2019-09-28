#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int pa, pb;
    pa = *a + *b;
    pb = *a - *b;
    *a = pa;
    if(pb<0){
        *b = -pb;
    }
    else{
        *b = pb;
    }
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

