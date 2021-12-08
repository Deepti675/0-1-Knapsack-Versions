#include<bits/stdc++.h>
using namespace std;
int count_of_subset_sum_with_given_diff(int a[],int n,int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    for(int j=0;j<sum+1;j++)
    {
        if(i==0)
        t[i][j]=0;
        if(j==0)
        t[i][j]=1;
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(a[i-1]<=j)
        t[i][j]=t[i-1][j-a[i-1]]+t[i-1][j];
        else
        t[i][j]=t[i-1][j];
    }
    
    return t[n][sum];
}
int main()
{
    int n,diff,sum=0,s1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>diff;
    for(int i=0;i<n;i++)
    sum=sum+a[i];
    s1=(diff+sum)/2;
    cout<<count_of_subset_sum_with_given_diff(a,n,s1);
}
