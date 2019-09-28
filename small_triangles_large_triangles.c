#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float calc_area(int a, int b, int c){
    float p = 0.5*(a+b+c);
    return sqrt(p*(p-a)*(p-b)*(p-c));

}

//void swap(triangle* tr, int i, int j){
void swap(triangle* tr, int j){
    triangle temp;
    temp = tr[j];
    tr[j] = tr[j+1];
    tr[j+1] = temp;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    float area_i, area_j;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            area_i = calc_area(tr[j].a,tr[j].b,tr[j].c);
            area_j = calc_area(tr[j+1].a,tr[j+1].b,tr[j+1].c);
            if(area_i>area_j){
                swap(tr,j);
            }
        }
    }
    /*
    int index = 1;
    for(int i=0;i<n;i++){
        area_i = calc_area(tr[i].a,tr[i].b,tr[i].c);
        if(area_i==0){
            index++;
        }
    }
    triangle *tr_out = malloc(index*sizeof(triangle));
    for(int i=0;i<n;i++){
        area_i = calc_area(tr[i].a,tr[i].b,tr[i].c);
        if(area_i!=0){
            tr_out[index]=tr[i];
            index--;
        }
    }
    tr = tr_out;
    */
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}