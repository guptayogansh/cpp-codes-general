#include<bits/stdc++.h>
#define ll long long
using namespace std;


void multiply(int a[2][2], int b[2][2]) 
{ 
 
    int mul[2][2]; 
    for (int i = 0; i < 2; i++) 
    { 
        for (int j = 0; j < 2; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 0; k < 2; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
  
    // storing the multiplication result in a[][] 
    for (int i=0; i<2; i++) 
        for (int j=0; j<2; j++) 
            a[i][j] = mul[i][j];  // Updating our matrix 
} 
  

int BinaryExponentiation(int p[][2], int n) 
{ 

    int res[][2]={{1,1},{1,1}};
    while(n > 0)
     {
         if ( n & 1)
           multiply(res, p);
        multiply(p,p);
        n >>= 1;
     }
    return res[0][1];
    
} 
  
int FibonacciByFastMatrix(int n) 
{ 
  
    int p[][2] = {{1,1}, {1,0}} ; 
  
    //Base cases 
    if(n==0) 
        return 0; 
    if(n==1 || n==2) 
        return 1; 
  
      cout<< "F(" << n <<") = " << BinaryExponentiation(p, n-1); 
} 


int main(){
 
     int n;
     cin>>n;
     FibonacciByFastMatrix(n);

    return 0;
}