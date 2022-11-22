#include<stdio.h>
#include<stdlib.h>

void hanoi(int n, int source, int destination, int inter){
  //base cases
  if(n==1){
    printf("Move disk %d from %d to %d\n",n, source,destination);
  }
  else{
    hanoi(n-1, source, inter, destination);
    printf("Move disc %d from %d to %d\n",n, source, destination);
    hanoi(n-1, inter, destination, source);
  }
}

int main(void)
{
  int n = 6;
  printf("Solution for %d discs\n", n);
  hanoi(n,1,3,2);
  return 0;
}
