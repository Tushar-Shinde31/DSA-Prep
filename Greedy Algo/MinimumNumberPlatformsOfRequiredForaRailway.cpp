int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; 
    for(int i=0;i<=n-1;i++)
    {
        int count=1; 
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count); 
    }
    return ans;
 }
 
