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

void sort_by_area(triangle* tr, int n) {

	long int *areas = malloc (n*sizeof(long int));
	

	/**
	* Sort an array a of the length n
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
