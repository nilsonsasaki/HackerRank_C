#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int find_nth_term(int n, int a, int b, int c) {
  
  int sum, numbers[4];
  
  for(int i =0; i<3;i++){
  
      numbers[i] = i;
      
  }
  
  if(n<=3){
  
      sum = numbers[n];
      
  } else{
  
        for(int i=4;i<=n;i++){
        
            sum= a+b+c;
            a=b;
            b=c;
            c=sum;   
               
        } 
  }
  
  return(sum);
}

int main() {

    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}

