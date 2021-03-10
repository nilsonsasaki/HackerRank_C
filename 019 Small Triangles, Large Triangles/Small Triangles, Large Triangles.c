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

long int calculate_perimeter (int a, int b, int c){

    long int perimeter = (long int) a + (long int) b + (long int) c;
    return(perimeter);  
}

long square_of_area (int a, int b, int c){

    
    long int p = (calculate_perimeter (a,b,c))/2;
    long int sq_of_area = p*(p-a)*(p-b)*(p-c);
    
    return (sq_of_area);
    
}

void get_all_areas (triangle* tr, int n, long int* areas){

    for (int i=0; i<n; i++){
        
        *(areas+i) = square_of_area((tr+i)->a,(tr+i)->b,(tr+i)->c);
            
    }
}

void put_before_first (int item_index,int first_index, long int *areas,  triangle * tr){


	long int area_swap = areas[item_index];
	triangle tr_swap = tr[item_index];
	
	for (int i=item_index; i>=0;i--){

		areas[i] = areas[i-1];
		tr[i] = tr[i-1];
	}
	areas[first_index] = area_swap;
	tr[first_index] = tr_swap;
	
}


void sort_by_area(triangle* tr, int n) {

    long int *areas = malloc (n*sizeof(long int));
    get_all_areas (tr, n, areas);
    
    for(int i=0; i<n-1;i++){
    
        for (int j=1; j<n; j++){
        
            if (areas[i]> areas[j]){
            
                put_before_first(j,i,areas,tr);
            }
        }
    }
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
