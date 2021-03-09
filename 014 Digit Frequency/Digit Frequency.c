#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char input[1000];
    int occurs[10];
    
    scanf("%s",input);
    for (int i=0;i<10;i++){
        occurs[i] = 0;
    }
    for(int i=0;input[i]!='\0';i++){
    
 
        if(input[i] == '0'){
        
            occurs[0]= occurs[0]+1;
            
        } else if (input[i] == '1') {
        
            occurs[1]= occurs[1]+1;
            
        } else if (input[i] == '2') {
        
            occurs[2]= occurs[2]+1;
            
        } else if (input[i] == '3') {
        
            occurs[3]= occurs[3]+1;
            
        } else if (input[i] == '4') {
        
            occurs[4]= occurs[4]+1;
            
        } else if (input[i] == '5') {
        
            occurs[5]= occurs[5]+1;
            
        } else if (input[i] == '6') {
        
            occurs[6]= occurs[6]+1;
            
        } else if (input[i] == '7') {
        
            occurs[7]= occurs[7]+1;
            
        } else if (input[i] == '8') {
        
            occurs[8]= occurs[8]+1;
            
        } else if (input[i] == '9') {
        
            occurs[9]= occurs[9]+1;
        }
    }
    
    for (int i=0;i<10;i++)
    
        (i==9)?(printf("%d",occurs[i])):(printf("%d ",occurs[i]));
        
    return 0;
}

