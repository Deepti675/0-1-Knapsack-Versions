
#include <bits/stdc++.h>

using namespace std;
int knapsack(int w,int wt[],int val[],int n,int **dp)
{
    if(n<0)
    return 0;
    if(dp[n][w]!=-1)
       return dp[n][w];
    if(wt[n]>w)
    {
        dp[n][w]=knapsack(w,wt,val,n-1,dp);
        return dp[n][w];
    }
    else
    {
        dp[n][w]=max(val[n]+knapsack(w-wt[n],wt,val,n-1,dp),knapsack(w,wt,val,n-1,dp));
        return dp[n][w];
    }
    
}
int main()
{
   int n,w;
   cin>>n>>w;
   int wt[n],val[n];
   for(int i=0;i<n;i++)
   {
       cin>>wt[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>val[i];
   }
   //double pointer to declear the table dynamically
   int **dp;
   dp=new int *[n+1];
   //loop to create the table dynamically
   for(int i=0;i<n+1;i++)
   {
       dp[i]=new int[w+1];
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<w+1;j++)
       {
           dp[i][j]=-1;
       }
   }
   
   cout<<knapsack(w,wt,val,n-1,dp);
    return 0;
}
