#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int factorial(int n);

int main(void){

  int i, order;
  double e, *terms;

  //Enter order
  printf("Please enter the required polinomial order\n");
  if(scanf("%d", &order) != 1){
    printf("Did not enter a number");
    return 1;
  }

  //Allocate dynamic array space
  terms = malloc(order*sizeof(double));
  for(i = 0; i<order; i++){
    terms[i] = 1.0/(double) factorial(i+1);
    printf("e term for order %d is %1.14lf\n", order, terms[i]);
  }

  e = 1.0;
  for(i=0; i<order; i++){
    e=e+terms[i];
  }

  free(terms);

  printf("\ne is estimated as %.10lf,  with difference %.10lf\n", e, e-exp(1.0));

}

int factorial(int n){
  if(n<0){
    printf("Error: It should be a positive value.");
    return -1;
  }
  else if(n==0){
    return 1;
  }
  else{
   return(n*factorial(n-1));
  }
}
