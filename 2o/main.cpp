#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

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

vector<vector<int>>* read(int* v1, int* v2) {
  int a, b, c, d;
  if(!scanf("%i %i", v1, v2)) return NULL;
  if(!scanf("%i %i", &c, &d)) return NULL;
  static vector<vector<int>> matrix1(c);
  vector<char> colour(c, 0);
  for(int i = 0; i < d; i++) {
    if(!scanf("%i %i", &a, &b)) return NULL;
    if(matrix1[a-1].size() == 2) return NULL;
    matrix1[a-1].push_back(b);
  }
  for(int i = 1; i <= c; i++) {
    if(!colour[i-1]) {
      if(!is_acyclic(i, matrix1, colour)) {
        return NULL;
      }
    }
  }
  return &matrix1;
}

int main() {
  int *v1 = (int*)malloc(sizeof(int)), *v2 = (int*)malloc(sizeof(int));
  vector<vector<int>> *tree = read(v1, v2);
  if(tree) {
    printf("true\n");
  }
  else {
  }
  return 0;
}