#include <stdio.h>

int profits[10],weights[10],maxW;

int knapsack(int n)
{
    int v[n+1][maxW+1],i,j;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxW; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (weights[i-1] <= j)
                v[i][j] = max(v[i - 1][j] , v[i - 1][j - weights[i - 1]] + profits[i - 1]);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    int selected[n];
    i = n; j = maxW;
    int count = 0;

    while (i > 0 && j > 0)
    {
        if (v[i][j] != v[i - 1][j])
        {
            selected[count++] = i;
            j -= weights[i - 1];
            i--;
        }
        else
            i--;

    }

    printf("Table: \n");
    for (i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxW; j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }

    printf("Items selected are : ");
    for (j = count-1; j >= 0; j--)
        printf("%d ", selected[j]);
    printf("\n");

    return v[n][maxW];
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void main()
{
    int n,i,j,maxP;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the Knapsack Capacity: ");
    scanf("%d",&maxW);
    printf("Enter the weights of all items\n");
    for(i=0;i<n;i++)
    scanf("%d",&weights[i]);
    printf("Enter the profits of all items\n");
    for(i=0;i<n;i++)
    scanf("%d",&profits[i]);
    maxP=knapsack(n);
    printf("Optimal solution with maximum profit is %d ",maxP);
}
