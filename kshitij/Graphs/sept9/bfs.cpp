    #include <iostream>
    #include <vector>
    #include<queue>
    using namespace std;
    void bfs(int node, int n, vector<bool> &visited, vector<vector<int>> &adjMatrix)
    {
      
      queue<int> q;
      q.push(node);
        visited[node] = true;

      while(!q.empty()){
        int top =  q.front();
        q.pop();
        cout << top << " ";
        for(int i = 1 ; i <= n ; i++){
            if( adjMatrix[top][i] && !visited[i]){
            q.push(i);
            visited[i] = true;
            }
        }
      }
    }
    int main()
    {
        cout << "enter  - ";
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        vector<bool> visited(n + 1, false);
        bfs(1, n, visited, adjMatrix);
    }