#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int>> read(int* v1, int* v2) {
  int a, b, c;
  scanf("%i %i\n", *v1, *v2);
  scanf("%i %i\n", a, c);
  vector<vector<int>> matrix(a, vector<int>(2));
  vector<char> colour(a, 0);
  for(int i = 0; i < c; i++) {
    scanf("%i %i\n", a, b);
    if(matrix[a-1].size() == 2) return;
    if(find(matrix[a-1].begin(), matrix[a-1].end(), b) != matrix[a-1].end()) return;
    matrix[a-1].push_back(b);
  }
  if(!is_acyclic(1, matrix, colour)) return;
  return matrix;
}

bool is_acyclic(int v, vector<vector<int>> matrix, vector<char> colour) {
    colour[v-1] = 1;
    bool a;
    for (int u : matrix[v-1]) {
        if (colour[u-1] == 0) {
          a = is_acyclic(u, matrix, colour);
          if(!a) {
            return false;
          }
        } else {
            return false;
        }
    }
    colour[v-1] = 0;
    return true;
}