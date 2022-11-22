int isMagicSquare(int **square, const int n)
{
  if(n<0){
    return 0;
  }

  int magic_num = 0;
  int off_diag_sum = 0;
  int i,j;
  for(i=0;i<n;i++){
    magic_num += square[i][i];
    off_diag_sum += square[i][n-i-1];
  }

  if(off_diag_sum != magic_num){
    return 0;
  }

  for(i=0;i<n;i++){
    int rowsum = 0;
    int colsum = 0;

    for(j=0;j<n;j++){
      rowsum += square[i][j];
      colsum += square[j][i];
    }

    if(rowsum != magic_num || colsum != magic_num){
      return 0;
    }
  }
  return 1;
}

