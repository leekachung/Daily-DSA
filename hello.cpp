#include<iostream>

int main(){
   int n = 3;
   int A [n][n];
   for(int i = 1; i <= n; i*=2)
   {
      for(int j = 0; j < i; j++)
      {
         A[i][j] = 0;
      }
   }
}