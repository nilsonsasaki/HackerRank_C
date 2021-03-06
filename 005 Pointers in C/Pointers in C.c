#include <stdio.h>
#include <stdlib.h>


void update(int *a,int *b) {

    int temp_a;
    
    temp_a = *a;
    *a = *a + *b;
    
    // abs() is in <stdlib.h> and <math.h>
    *b = abs(temp_a-*b);        
}

int main() {

    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

