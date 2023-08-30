#include <stdio.h>
#define max 100
int visit[max],stack[max],top=-1;

void dfs(int v,int n,int am[max][max])
{
    int i;
    //printf("\n %d ",v);
    visit[v]=1;
    for(i=1;i<=n;i++)
    {
        if(am[v][i]&&!visit[i])
        {
            dfs(i,n,am);//printf("\n %d -> %d ",v,i);
        }
    }
    stack[++(top)] = v;
}

void topologicalSort(int n,int am[max][max])
{
    int i,j;

    for (i = 1; i <=n ; i++)
    {
        if (!visit[i])//if not visited
            dfs(i, n, am);
    }
    printf("Topological Sort Order: ");
    while (top >= 0)
    {
        printf("%d ", stack[top--]);
    }
}

void main()
{
    int am[max][max];
    int i,j,n;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        visit[i]=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&am[i][j]);
        }
    }
    topologicalSort(n,am);
}
