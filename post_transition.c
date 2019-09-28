#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6
#include<string.h> 
struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n",t.name);
    for(int i=0;i<t.offices_count;i++){
        printf("\t%d:\n",i);
        for(int j=0;j<t.offices[i].packages_count;j++){
            printf("\t\t%s\n",t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {	
    /*
    printf("%s\n","PRINT Source");
    print_all_packages(*source);
    printf("%s\n","PRINT Target");
    print_all_packages(*target);
    */
    int max_weight, min_weight,index;//, target_packages;
    int* target_packages;
    int* source_packages;
    //package* source_p = source->offices[source_office_index].packages;
    //package* target_p = target->offices[target_office_index].packages;
    source_packages = &(source->offices[source_office_index].packages_count);
    target_packages = &(target->offices[target_office_index].packages_count);
    max_weight = target->offices[target_office_index].max_weight;
    min_weight = target->offices[target_office_index].min_weight;
    int pack_weight;
    for(int i=0; i<*source_packages;i++){
        pack_weight = source->offices[source_office_index].packages[i].weight;
        if(min_weight<=pack_weight && pack_weight <=max_weight){
            
            (*target_packages)++;
            //printf("%d\n",(*target_packages));
            //printf("%d\n",target->offices[target_office_index].packages_count);
            //printf("%d\n",(*source_packages));
            
            //printf("%s\n",source->offices[source_office_index].packages[i].id);
            target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages, (*target_packages)*sizeof(package));

            target->offices[target_office_index].packages[(*target_packages)-1]=source->offices[source_office_index].packages[i];
            //printf("%s\n",target->offices[target_office_index].packages[(*target_packages)-1].id);
            for(int j=i;j<(*source_packages)-1;j++){
                package temp = source->offices[source_office_index].packages[j];
                //printf("Reassign %s\n",source->offices[source_office_index].packages[i].id);
                source->offices[source_office_index].packages[j]=source->offices[source_office_index].packages[j+1];
                source->offices[source_office_index].packages[j+1] = source->offices[source_office_index].packages[j];

            }
            //printf("%s\n",source->offices[source_office_index].packages[i].id);
            i--;
            (*source_packages)--;
            source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages, (*source_packages)*sizeof(package));
        }

    }
    /*
    printf("%s\n","PRINT Source");
    print_all_packages(*source);
    printf("%s\n","PRINT Target");
    print_all_packages(*target);
    printf("%s\n","PRINT Target");
    for(int i=0;i<target->offices[target_office_index].packages_count;i++){
        printf("%s\n",target->offices[target_office_index].packages[i].id);
    }
    printf("%s\n","PRINT Target DONE");
    */
}

town town_with_most_packages(town* towns, int towns_count) {
    int max_index = -1;
    int max_sum = -1;
    int sum;
    for(int i=0;i<towns_count;i++){
        sum = 0;
        for(int j=0;j<towns[i].offices_count;j++){
            //printf("%s %d\n",towns[i].name,towns[i].offices[j].packages_count);
            sum += towns[i].offices[j].packages_count;
        }
        //printf("%s %d\n",towns[i].name,sum);
        if(sum>max_sum){
            max_sum=sum;
            max_index = i;
        }
    }
    //printf("%s\n",towns[max_index].name);
    return towns[max_index];
}

town* find_town(town* towns, int towns_count, char* name) {
    while(towns_count--){
        if(strcmp(towns[towns_count].name, name)==0){
            return &towns[towns_count];
        }
    }
    printf("%s\n","noooo");
    return &towns[0];;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}

