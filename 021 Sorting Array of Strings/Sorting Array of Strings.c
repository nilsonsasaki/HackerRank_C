#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
	
	return(strcmp(a,b));
	
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	
	return(strcmp(b,a));
}

int number_of_distinct_characters(const char *a){

	char distinct_characters [27];
	int i=0, distinct_characters_count =0;
	int is_new = 1;
	while (a[i]!='\0'){
	
		if (distinct_characters_count !=0){
		
			for (int j=0;j<distinct_characters_count;j++){
			
				if(distinct_characters[j]==a[i]){
				
					is_new=0;
					break;
				}
			}
			
		}
		if(is_new){
		
			distinct_characters[distinct_characters_count] = a[i];
			distinct_characters_count++;
		}
		is_new = 1;
		i++;
	}
	return (distinct_characters_count);
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {

	int a_count = number_of_distinct_characters(a);
	int b_count = number_of_distinct_characters(b);
	
	if(a_count >b_count){
	
		return(1);
		
	} else if (a_count <b_count){
	
		return (-1);
	}
	
	return(strcmp(a,b));
}
	
int sort_by_length(const char* a, const char* b) {

	unsigned int a_length = strlen(a);
	unsigned int b_length = strlen(b);
		
	if(a_length > b_length){
	
		return(1);
	
	}else if (a_length < b_length){
	
		return(-1);
	}
	
	return(strcmp(a,b));
}

void swap_string(char **a, char **b){

	 char *temp = *a;
	 *a=*b;
	 *b = temp;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){

	int is_finished =0;
	
	int count = len;
	
	while (!is_finished){
	
		is_finished=1;
		for (int i=0;i<count-1;i++){
		
			if(((*cmp_func)(arr[i],arr[i+1]))>0){
			
				swap_string(&arr[i],&arr[i+1]);
				is_finished=0;
				
			}
		}
		count--;
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
