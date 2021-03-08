#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int str_qsortcmp (const void * a, const void * b ) {
    const char **pa = (const char**)a;
    const char **pb = (const char**)b;

    return strcmp(*pa,*pb);
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
	int i,j,there_is_next = false;
	
	char *swap =(char*)malloc(11*sizeof(char));

	for (int i=n-1;i>0;i--)
	{
		if(strcmp(*(s+i),*(s+i-1))>0&& (i==n-1)){
			
			strcpy(swap,*(s+i-1));
			strcpy(*(s+i-1),*(s+i));
			strcpy(*(s+i),swap);
			there_is_next = true;
			break;

		} else if (strcmp(*(s+i),*(s+i-1))>0 && (i<n-1)){

			strcpy(swap,*(s+i-1));
			for (j = n-1; j>=i;j--){
			
				if(strcmp (*(s+j),swap)>0){
				
					strcpy(*(s+i-1),*(s+j));
					strcpy(*(s+j),swap);
					break;
					
				}
				
			}
			qsort(s+i,n-i,sizeof(char*),str_qsortcmp);
			there_is_next = true;
			break;
				
		}
	}
	
	free(swap);
	return(there_is_next);

}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = (char*)calloc(11, sizeof(char));
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
