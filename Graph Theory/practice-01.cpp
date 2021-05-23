/*
	What's here?
	-------------------------------------------------------------------------------------
	
	From a directed graph - 
	1. Create an adjacent list
	2. For each node, find out how many nodes are connected with it along with the nodes.
	3. Find out the indegree and outdegree for each node.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int numNodes, numEdges;
	std::cin >> numNodes >> numEdges;

	std::vector < std::vector < int > > v; // outdegree edges
	std::vector < std::vector < int > > u; // indegree edges
	std::vector < int > loop;
	v.resize(numNodes);
	u.resize(numNodes);
	loop.resize(numNodes);

	int n1, n2;
	for( int i = 0; i < numEdges; i++ ) {
		std::cin >> n1 >> n2;
		v[n1 - 1].push_back(n2 - 1); // saving for outdegree edges
		if( n1 != n2 ) u[n2 - 1].push_back(n1 - 1); // saving for indegree edges
		else loop[n1 - 1]++; // counting self-loop
	}

	// connected nodes list
	for( int i = 0; i < numNodes; i++ ) {
		std::cout << "Node " << i + 1 << " is connected with " << u[i].size() + v[i].size() << " node(s) :: ";
		for( int j = 0; j < v[i].size(); j++ ) 
			std::cout << v[i][j] + 1 << ' ';
		for( int j = 0; j < u[i].size(); j++ ) 
			std::cout << u[i][j] + 1 << ' ';
		std::cout << endl;
	}
	std::cout << endl;

	// indegree
	for( int i = 0; i < numNodes; i++ ) {
		std::cout << "Node " << i + 1 << " has indegree :: " << u[i].size() + loop[i] << " >> ";
		for( int j = 0; j < u[i].size(); j++ ) 
			std::cout << u[i][j] + 1 << ' ';
		for( int j = 0; j < loop[i]; j++ ) 
			std::cout << i + 1 << ' ';
		cout << endl;
	}
	std::cout << endl;

	// outdegree
	for( int i = 0; i < numNodes; i++ ) {
		std::cout << "Node " << i + 1 << " has outdegree :: " << v[i].size() << " >> ";
		for( int j = 0; j < v[i].size(); j++ ) 
			std::cout << v[i][j] + 1 << ' ';
		cout << endl;
	}
	std::cout << endl;
	
	return 0;

}

//	ALHAMDULILLAH
