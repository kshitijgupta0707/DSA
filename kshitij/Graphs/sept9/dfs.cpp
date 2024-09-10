#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, int n, vector<bool> &visited, vector<vector<int>> &adjMatrix)
{
    cout << node << " ";
    visited[node] = true;

    for (int i = 1; i <= n; i++)
    {
        if (adjMatrix[node][i] && !visited[i])
        {
            dfs(i, n, visited, adjMatrix);
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

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(1, n, visited, adjMatrix);
        }
    }
}