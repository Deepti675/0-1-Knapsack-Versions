
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



/////another way passing table 



#include <bits/stdc++.h>

using namespace std;
int static t[102][1002];
int knapsack(int w,int wt[],int val[],int n)
{
    if(n<0)
    return 0;
    if(t[n][w]!=-1)
    return t[n][w];
    if(wt[n]>w)
    {
        t[n][w]=knapsack(w,wt,val,n-1);
        return t[n][w];
    }
    else
    {
        t[n][w]=max(val[n]+knapsack(w-wt[n],wt,val,n-1),knapsack(w,wt,val,n-1));
        return t[n][w];
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

    memset(t,-1,sizeof(t));
   cout<<knapsack(w,wt,val,n-1);
    return 0;
}

