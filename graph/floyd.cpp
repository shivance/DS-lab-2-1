#include <bits/stdc++.h> 
using namespace std; 


#define V 4 
#define INF 99999 


void print(int dp[][V]) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dp[i][j] == INF) 
				cout<<"inf"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 


void fW(int graph[][V]) 
{ 
	distances between every pair of vertices */
	int dp[V][V], i, j, k; 

	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dp[i][j] = graph[i][j]; 

	for (k = 0; k < V; k++) 
	{ 
		for (i = 0; i < V; i++) 
		{ 
			for (j = 0; j < V; j++) 
			{ 
				if (dp[i][k] + dp[k][j] < dp[i][j]) 
					dp[i][j] = dp[i][k] + dp[k][j]; 
			} 
		} 
	} 
	print(dp); 
} 



int main() 
{ 

	int graph[V][V] = { {0, 5, INF, 10}, 
						{INF, 0, 3, INF}, 
						{INF, INF, 0, 1}, 
						{INF, INF, INF, 0} 
					}; 


	fW(graph); 

	return 0; 
} 


