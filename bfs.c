#include <stdio.h>
//#define n 4
int am[100][100], q[100], visit[100], front = 1, rear = 0;

void bfs(int v,int n)
{
    int i;
    printf("%d ", v);
    visit[v] = 1;
    q[++rear] = v;

    while (front <= rear)
    {
        v = q[front++];

        for (i = 1; i <= n; i++)
        {
            if (am[v][i] && !visit[i])
            {
                printf("%d ", i);
                q[++rear] = i;
                visit[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j,n,start;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        visit[i] = 0;
        q[i] = 0;
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &am[i][j]);
        }
    }
    printf("Enter the starting node:\n");
    scanf("%d",&start);
    printf("BFS Traversal: ");
    bfs(start,n);
    printf("\n");

    return 0;
}
