/*Kahn's Algorithm

Description : Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.


Time Complexity: O(V+E). 
Auxiliary space: O(V). 

*/

//Topological Sort using Depth-First-Search DFS
#include<bits/stdc++.h> 
using namespace std; 

void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{ 	
	//marking the current vertex as visited
    visited[u]=true;
    
    //Processing all the vertices adjacent to the current vertex
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    //Pushing the vertex in stack
    st.push(u);
}


void topologicalSort(vector<int> adj[], int V) 
{ 
    bool visited[V]; 
	for(int i = 0;i<V; i++) // Marking all the vertices as not visited
		visited[i] = false;
	stack<int> st;
    
    //Processing the vertex one by one
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    //Printing the contents of stack
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
   
}

//fuction to add edges 
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V,E;
	cin>>V>>E;
	vector<int> adj[V];
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}

 
    cout<<"Topological Sort : \n"; 
    topologicalSort(adj,V);

	return 0; 
} 

