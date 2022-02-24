/*
           Topological short
            
        shanto-swe029.github.io
*/

/*
        Input:
        5 4
        1 2
        2 3
        1 3
        1 5
        
        Output:
        1 4 2 5 3
 */

#include <bits/stdc++.h>
using namespace std;

std::vector < int > adj[500];

int main()
{
    int nodeCount, edgeCount;
    std::cin >> nodeCount >> edgeCount;
    
    std::vector < int > inDegree(nodeCount, 0);
    
    // Graph input
    for( int i = 0; i < edgeCount; i++ ) {
        int u, v;
        std::cin >> u >> v;
        inDegree[v]++;
        adj[u].push_back(v);
    }
    
    std::queue < int > sequenceTasks;
    
    for( int i = 1; i <= nodeCount; i++ ) {
        if( inDegree[i] == 0 ) {
            sequenceTasks.push(i);
        }
    }
    
    while( !sequenceTasks.empty() ) {
        int node = sequenceTasks.front();
        sequenceTasks.pop();
        for( int dependendentNode : adj[node] ) {
            inDegree[dependendentNode]--;
            if( inDegree[dependendentNode] == 0 ) {
                sequenceTasks.push(dependendentNode);
            }
        }
        
        std::cout << node << " ";
    }

    return 0;
}
