#include <stdio.h>
#include <stdlib.h>

// Input arguments f(n-1) and f(n-2)
// assigns values to f(n) and f(n -1)
void fibonacci(long *a, long *b);

int main(){
    int i,n;
    long f1 = 1, f0 = 0;
    
    //input value
    printf("Enter a positive integer.\n");
    scanf("%d", &n);
    
    if(n<1){
        printf("The number is not positive");
        exit(1);
    }
    
    printf("The Fibonacci series upto %d is\n", n);
    printf("%ld, %ld", f0, f1);
    
    // print fibonacci series
    for(i=2; i<n; i++){
        fibonacci(&f1,&f0);
        printf(", %ld", f1);
        
        if((i+1)%10 == 0) printf("\n");
        
    }
    
    return 0;

}

void fibonacci(long *a, long *b){
    long next;
    
    // value of fibonacci term after the passed terms
    next = *a + *b;
    
    //assigning next values; *a = f(n); *b = f(n-1)
    *b = *a;
    *a = next;
    
}
