#include <stdio.h>

int main() 
{
    char ch, s[100], sen[100];
    /* for strings i need to allocate max length +1 to fit the string and the '\0' character
    in this problem the max input length is 100, including a newline character ('\n') therefore
    max length =100    
    */
    scanf("%c%*c", &ch); // *c is reading and eliminating '\n' so it won't be read in the next scanf
    scanf("%[^\n]%*c", &s); // scanf is reading until before '\n', so i need to eliminate '\n' again
    scanf("%[^\n]%*c", &sen);
    printf("%c\n%s\n%s",ch,s,sen); //printing all variables
    getchar(); //wait a char after printf
    return 0;
}