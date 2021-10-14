#include <stdio.h>
void p(int l1[],int l2[],int f[],int n,int m)
{
    int i=0,j=0,x=0;
    for(i=0;i<n+m;i++)
    {
        f[i]=0;
    }
    i=0;
    while(j<m && i<n)
    {   
        if(l1[i]<l2[j])
        {
            f[x++]=l1[i++];
            printf("\n");
        }
        else
        {

            f[x++]=l2[j++];
            printf("\n");

        }
        for(int k=0;k<n+m;k++)
        {
            printf("%d ",f[k]);
        }
    }
    if(i<n)
    {
        while(i<n)
        {
            f[x++]=l1[i++];
            printf("\n");
            for(int k=0;k<n+m;k++)
            {
            printf("%d ",f[k]);
            }
        }
    }
    if(j<m)
    {
        while(j<m)
        {
            f[x++]=l2[j++];
            
            for(int k=0;k<n+m;k++)
            {
            printf("%d ",f[k]);
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d",&n);
    int l1[n],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&l1[i]);
    }
    scanf("%d",&m);
    int l2[m];
    for(i=0;i<m;i++)
    {
        scanf("%d",&l2[i]);
    }
    int f[n+m];
    p(l1,l2,f,n,m);
}