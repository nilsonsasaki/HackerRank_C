#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	
    int size = 2*n;
    int matrix[size][size];
    
    for(int i = 0; i <=n-1;i++){
    
        for(int j=i;j<=n-1;j++){
      	    	
            matrix[i][j] = n-i;
            matrix[j][i] = n-i;
            matrix[i][size -2 -j] =n-i;
            matrix[j][size-2 -i] =n-i;
            matrix[size-2 -i][size-2 -j] =n-i;
            matrix[size-2-j][size-2 -i] =n-i;
            matrix[size-2 -i][j] =n-i;
            matrix[size-2-j][i] =n-i;
        }
        
    }
    for (int i=0; i<size-1;i++){
    
        for (int j=0;j<size-1;j++){
        
            (j==size-2)?printf("%d\n",matrix[i][j]):printf("%d ",matrix[i][j]);
        }
    } 
        
    return 0;
}

