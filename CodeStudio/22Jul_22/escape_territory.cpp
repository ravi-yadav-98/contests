#include <bits/stdc++.h>
using namespace std;
/*
You are Ninja on a mission. You are somewhere in the enemy territory, and now you want to escape the enemy territory.
A enemy territory can be represented by a Grid ‘COST’ of size ‘N * M’. Where ‘COST[i][j]’ means the money to escape the ‘jth’ cell from the ‘ith’ row. The starting position will have ‘COST[i][j]’ equal to ‘0’.
Given that you can move in 8 directions (right, left, up, down and diagonally upper left, diagonally lower left, diagonally upper right, diagonally lower right), your task is to escape enemy territory with spending minimum money.
You can only escape territory from any of the ‘4’ corners of the grid. Can you find the minimum cost to escape enemy territory?
Example :
N = 3 , M = 3,
COST =  [ [ 1, 8, 9 ],
          [ 6, 5, 0 ],
          [ 7, 9, 8 ] ]
You can escape by reaching the top left corner (0,0) by following the path (1,2) -> (1,1) -> (0,0), so total cost is ‘6’ no other paths.
*/


/*
    Time Complexity : O(N^2 * M^2)
    Space Complexity : O(N * M)
    
    where 'N * M' is the size of matrix 'COST'. 
*/

int escapeEnemy(int n, int m, vector < vector < int > > cost) {
   // 'INF' signifies infinity.
   int INF = 1e9;

   // Matrix of size 'N * M' initialising with value 'INF'.
   vector < vector < int > > dis(n, vector < int > (m));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

         // Only source will have 'DIS' equals '0'.
         if (cost[i][j] == 0) {
            dis[i][j] = 0;
         } else {
            dis[i][j] = INF;
         }
      }
   }

   int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
   int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
   // Relaxing each edge 'N * M' times.
   for (int times = 0; times < n * m; times++) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            // Finding all connected vertex to 'COST[i][j]'.
            for (int k = 0; k < 8; k++) {
               int curr_x = dx[k] + i, curr_y = dy[k] + j;
               if (curr_x >= 0 && curr_x < n && curr_y >= 0 && curr_y < m) {
                  dis[i][j] = min(dis[i][j], dis[curr_x][curr_y] + cost[i][j]);
               }
            }
         }
      }
   }
   // Finding minimum of all '4' corners.
   int ans = min({
      dis[0][0],
      dis[n - 1][0],
      dis[0][m - 1],
      dis[n - 1][m - 1]
   });
   return ans;
}
int main(void)
{


    int n = 3;
    int m = 3;

    vector < vector < int > > cost = {{1, 1, 2},{8,0,1},{2,5,6}};
    cout<< escapeEnemy(n,m,cost);

  return 0;
}