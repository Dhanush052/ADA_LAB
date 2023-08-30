#include <stdio.h>
//define n 4
int am[100][100],visit[100];

void dfs(int v,int n)
{
    int i;
    printf("\n %d ",v);
    visit[v]=1;
    for(i=1;i<=n;i++)
    {
        if(am[v][i]&&!visit[i])
        {
            dfs(i,n);//printf("\n %d -> %d ",v,i);
        }
    }

}
void main()
{
    int i,j,n,start;
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
    printf("Enter the starting node:\n");
    scanf("%d",&start);
    printf("DFS Traversal: ");
    dfs(start,n);
    //printf("\n");

}
