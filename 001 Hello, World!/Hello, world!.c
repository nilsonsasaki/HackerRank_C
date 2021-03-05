#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];
    scanf("%[^\n]%*c", s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /*
    -------------------------------English----------------------------------
    Just added one line with the required text, escape sequence for new line
    and printing a string
    
   ----------------------------Português(Brasil)----------------------------
    Adicionei apenas uma linha contendo o texto exigido, a sequencia de escape 
    para nova linha (\n) e imprimindo uma string
    */
    printf("Hello, World!\n%s",s);
    getchar();
    getchar();    
    return 0;
}
