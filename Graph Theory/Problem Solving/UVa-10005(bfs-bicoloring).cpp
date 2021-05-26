/*
			BISMILLAHIR-RAHMANIR-RAHIM
					SWExSh4n.t0
						SUST
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 210

std::vector < int > g[MAX_NODES];

void bfs ( int n, int src )
{
	bool color[n], vis[n];
	for( int i = 0; i < n; i++ ) 
		color[i] = false, vis[i] = false;
	int u, v;
	std::queue < int > q;
	q.push( src );

	while( !q.empty() ) {
		u = q.front(); q.pop();
		for( int i = 0; i < g[u].size(); i++ ) {
			v = g[u][i];
			if( !vis[v] ) {
				color[v] = !color[u];
				vis[v] = true;
				q.push(v);
			}
			else if( color[u] == color[v] ) {
				std::cout << "NOT BICOLORABLE." << endl;
				return;
			}
		}
	}
	std::cout << "BICOLORABLE." << endl;
	return;
}

int main()
{
	int n, e, u, v;

	while( std::cin >> n ) {
		if( n == 0 ) return 0;

		std::cin >> e; // number of edges
		for( int i = 0; i < e; i++ ) {
			std::cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u); // if the graph is bidirected
		}

		bfs( n, 0 );

		for( int i = 0; i < n; i++ ) g[i].clear(); // clear memory
	}

	return 0;
}

//	ALHAMDULILLAH
