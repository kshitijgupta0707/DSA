//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   
    void bfs(int sr , int sc , vector<vector<int>> & image ,  int newColor , int initialClr){
        
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int,int>> q;
        image[sr][sc] = newColor;   
        q.push({sr , sc});
        
        while(!q.empty()){
            
            pair<int,int> top = q.front();
            q.pop();
            int row = top.first;
            int col = top.second;
            
            if(row - 1 >= 0 && image[row-1][col] == initialClr ){
                image[row-1][col] = newColor;
                q.push({row-1 , col});
            }
            if(row + 1 < m && image[row+1][col] == initialClr ){
                image[row+1][col] = newColor;
                q.push({row+1 , col});
            }
            if(col - 1 >= 0 && image[row][col-1] == initialClr){
                image[row][col-1] = newColor;
                q.push({row , col-1});    
            }
            if(col + 1 < n && image[row][col+1] == initialClr){
                image[row][col+1] = newColor;
                q.push({row , col+1});
            }
        }
            }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
    
        
        bfs(sr , sc, image , newColor , image[sr][sc]);
         
         return image;
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends