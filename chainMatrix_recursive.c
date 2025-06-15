#include <stdio.h>
#include <limits.h>
#define MAX 100
int arr[MAX][MAX];    
int s[MAX][MAX];      
int matrixChainOrder(int p[], int i, int j) 
{
    if(i == j) 
    {
        return 0; 
    }
    if (arr[i][j]!= -1) 
    {
        return arr[i][j];
    }
    int min=INT_MAX;
    int k_min = -1;
    for(int k=i;k<j;k++) 
    {
        int count=matrixChainOrder(p,i,k)+matrixChainOrder(p,k+1,j)+
        p[i-1]*p[k]*p[j];
        printf("The value of k is %d, the cost is %d\n",k,count);
        if(count<min) 
        {
            min=count;
            k_min=k;  
        }
    }
    arr[i][j]=min;
    s[i][j]=k_min; 
    return min;
}

void printOptimalParenthesization(int i,int j) 
{
    if(i == j) 
    {
        printf("A%d", i);
    } 
    else 
    {
        printf("(");
        printOptimalParenthesization(i, s[i][j]);
        printOptimalParenthesization(s[i][j]+1,j);
        printf(")");
    }
}

int main() 
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n+1]; 
    printf("Enter the dimensions of the matrices:\n");
    for(int i=0;i<n;i++) 
    {
        printf("Matrix %d: ", i + 1);
        scanf("%d %d", &p[i], &p[i + 1]);
    }
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++) 
        {
            arr[i][j]=-1;
            s[i][j]=-1; 
        }
    }
    printf("Minimum number of multiplications is: %d\n", matrixChainOrder(p, 1, n));
    printf("Optimal Parenthesization: ");
    printOptimalParenthesization(1, n);
    printf("\n");
    return 0;
}