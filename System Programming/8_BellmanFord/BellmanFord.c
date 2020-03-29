#include <stdio.h>
#include <stdlib.h>

struct edge
{
	int source, destination, weight;
};

struct graph
{
	int V, E;
	struct edge* edge;
};

struct graph* create_graph(int v, int e)
{
	struct graph* graph = (struct graph *)malloc(sizeof(struct graph));
	graph->V = v;
	graph->E = e;
	graph->edge = (struct edge *)malloc(e*sizeof(struct edge));
	return graph;
}

void printArray(int arr[], int size) {
	int i;
	for(i = 0; i < size; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void bellman(struct graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	int pred[V];
	for(int i=0;i<V;i++)
		dist[i] = 9999;
	
	dist[src] = 0;
	pred[src] = 0;
	
	for(int i=1;i<=V;i++)
	{
		for(int j=0;j<E;j++)
		{
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
			if(dist[u] != 9999 && dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pred[v] = u;
			}
		}
	}

	for(int j=0;j<E;j++)
	{
		int u = graph->edge[j].source;
		int v = graph->edge[j].destination;
		int weight = graph->edge[j].weight;
		if(dist[u] != 9999 && dist[v] > dist[u] + weight){
			printf("NEGATIVE CYCLE!!..\n");
			return;	
		}
	}
	
	printf("\nDistance Array:");
	printArray(dist,V);
	
	printf("\nPredecessor Array:");
	printArray(pred,V);
}

int main()
{
	int vertices, edges;
	printf("\nEnter number of vertices:");
	scanf("%d",&vertices);
	
	printf("\nEnter number of edges:");
	scanf("%d",&edges);
	
	struct graph* graph = create_graph(vertices ,edges);
	printf("\nEnter source, destination and weight for each edge:");
	for(int i=0;i<edges;i++)
	{
		printf("\nEdge %d:\n",(i+1));
		scanf("%d%d%d",&graph->edge[i].source,&graph->edge[i].destination,&graph->edge[i].weight);
	}
	
	bellman(graph, 0);
	return 0;
}
