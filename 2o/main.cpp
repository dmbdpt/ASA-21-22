#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

bool read(vector<vector<int>> matrix, int* v1, int* v2) {
  int a, b, c, d;
  scanf("%i %i\n", *v1, *v2);
  scanf("%i %i\n", c, d);
  vector<char> colour(c, 0);
  for(int i = 0; i < d; i++) {
    scanf("%i %i\n", a, b);
    if(matrix[a-1].size() == 2) return false;
    matrix[a-1].push_back(b);
  }
  for(int i = 1; i <= c; i++) {
    if(!colour[i-1]) {
      if(!is_acyclic(i, matrix, colour)) {
        return false;
      }
    }
  }
  return true;
}

bool is_acyclic(int v, vector<vector<int>> matrix, vector<char> colour) {
    colour[v-1] = 1;
    for (int u : matrix[v-1]) {
        if (colour[u-1] == 0) {
          if(!is_acyclic(u, matrix, colour)) {
            return false;
          }
        } else if(colour[u-1] == 1) {
            return false;
        } else {
          return true;
        }
    }
    colour[v-1] = 2;
    return true;
}

int main() {
  int *v1, *v2;
  vector<vector<int>> tree;
  if(read(tree, v1, v2)) {
    printf("true");
  }
  else {
    printf("false");
  }
  return 0;
}