/* Input
0 25 35 999 100 999
999 0 27 14 999 999
999 999 0 29 999 999
999 999 999 0 999 21
999 999 50 999 0 999
999 999 999 999 48 0
*/

#include <stdbool.h>
#include <stdio.h>
#define MAX 999
int V;
int parents[50];
int noParent= -1;

int minDistance(int totalWeight[], bool picked[])
{
	int min = MAX, min_index;

	for (int v = 0; v < V; v++)
	{
	    if (picked[v] == false && totalWeight[v] <= min)
			{
			    min = totalWeight[v];
                min_index = v;
            }
	}

	return min_index;
}
void printPath(int currentVertex,int parents[V])
{
	if (currentVertex == noParent)
    {
		return;
	}
	printPath(parents[currentVertex], parents);
	printf("%d  ",currentVertex);
}
void printSolution(int totalWeight[])
{
	printf("\nVertex \t\t Distance from Source\t\tPath\n");
	for (int i = 0; i < V; i++)
    {
        printf("%d \t\t\t\t %d \t\t", i, totalWeight[i]);
		printPath(i,parents);//for each node we print the shortest from from root node
		printf("\n");
	}
}

void dijkstra(int graph[V][V], int src)
{
	int totalWeight[V];//total weight from source to each node

	bool picked[V];//node picked or not
	for (int i = 0; i < V; i++)
    {
        totalWeight[i] = MAX;
        picked[i] = false;
    }

	totalWeight[src] = 0;
    parents[0]=noParent;//no parent yet
	for (int count = 0; count < V - 1; count++)
    {
		int u = minDistance(totalWeight, picked);//find node with min distance

		picked[u] = true;//pick that node

		for (int v = 0; v < V; v++)
        {
            if (!picked[v] && graph[u][v]
				&& totalWeight[u] != MAX
				&& totalWeight[u] + graph[u][v] < totalWeight[v])//find min one
				{
                    totalWeight[v] = totalWeight[u] + graph[u][v];
                    parents[v]=u;//u is parent of v
				}
		}
	}

	printSolution(totalWeight);
}

int main()
{
    printf("Enter the number of Vertices of the graph:\n");
    scanf("%d",&V);
	int graph[V][V],j;
	printf("Enter the matrix\n");
	for(int i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
	}

	dijkstra(graph, 0);

	return 0;
}
