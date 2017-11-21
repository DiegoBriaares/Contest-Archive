#include <iostream>
#include <stdlib.h>
using namespace std;
int pas[102][102];
void sp(int n){
     for(int i=0;i<n;i++)cout << " ";
     }
      int main (){
               int i,n,j,k,g,h;
               cin>>n;
               pas[1][1]=1;
               pas[2][1]=1;
               pas[2][2]=1;
               for(i=3;i<=n;i++){
                  for(j=1;j<=n;j++){
                          if(j==1||j==i)pas[i][j]=1;  
                          else pas[i][j]=pas[i-1][j]+pas[i-1][j-1];       
                  }                  
               }
               for(i=1;i<=n;i++){
               sp(n-i);
               for(j=1;j<=i;j++)cout << pas[i][j]<<" ";
               cout << "\n";
               }
               system("pause");
          }
