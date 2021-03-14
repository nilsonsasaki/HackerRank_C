#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
	
	
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	
	
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {

	
}

int sort_by_length(const char* a, const char* b) {

	int a_length =0, b_length=0;
	int is_end_of_a = 0;
	int is_end_of_b = 0;
	int index=0;
	
	while (!is_end_of_a && !is end of b){
	
		if(*(a+index)=='\0'&& is_end_of_a==0)
			is_end_of_a=1;
		
		if(*(b+index)=='\0' && is_end_of_b==0)
			is_end_of_b=1;
		
		if (is_end_of_a==0){
		
			a_length++;
		}
		
		if (is_end_of_b==0){
		
			b_length++;
		}
		index++;
	}
	return((a>b)?a:b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){

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
