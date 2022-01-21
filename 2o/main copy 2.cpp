#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool is_acyclic(int v, vector<vector<int>> matrix, vector<int> colour)
{
    colour[v - 1] = 1;
    for (int u : matrix[v - 1])
    {
        if (colour[u - 1] == 0)
        {
            if (!is_acyclic(u, matrix, colour))
            {
                return false;
            }
        }
        else if (colour[u - 1] == 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    colour[v - 1] = 2;
    return true;
}

bool read(int *v1, int *v2, int* n, vector<vector<int>> **matrix_o, vector<vector<int>> **matrix_o_t)
{
    int pai, filho, m;

    if (!scanf("%i %i", v1, v2))
        return false;

    if (!scanf("%i %i", n, &m))
        return false;

    vector<int> colour(*n, 0);
    static vector<vector<int>> matrix(*n, vector<int>());
    static vector<vector<int>> matrix_t(*n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        if (!scanf("%i %i", &pai, &filho))
            return false;

        if (matrix[filho - 1].size() == 2)
            return false;

        matrix[filho - 1].push_back(pai);
        matrix_t[pai - 1].push_back(filho);
    }

    for (int i = 1; i <= *n; i++)
    {
        if (!colour[i - 1])
        {
            if (!is_acyclic(i, matrix, colour))
            {
                return false;
            }
        }
    }
    *matrix_o = &matrix;
    *matrix_o_t = &matrix_t;
    return true;
}

void colour1_dfs(vector<vector<int>> tree, vector<int> *colour, int v) {
    (*colour)[v-1] = 1;
    for(int i : tree[v-1]) {
        colour1_dfs(tree, colour, i);
    }
}

void colour2_dfs(vector<vector<int>> tree, vector<int> *colour, int v) {
    if((*colour)[v-1]) {
        (*colour)[v-1] = 2;
    }
    for(int i : tree[v-1]) {
        colour2_dfs(tree, colour, i);
    }
}

vector<int> lca(int v1, int v2, int n, vector<vector<int>> tree, vector<vector<int>> tree_t) 
{
    vector<int> colour(n, 0), found;
    colour1_dfs(tree, &colour, v1);
    colour2_dfs(tree, &colour, v2);
    for(int i = 1; i <= n; i++) {
        if(colour[i-1] == 2) {
            found.push_back(i);
            for(int child : tree_t[i-1]) {
                if(colour[child - 1] == 2) {
                    found.pop_back();
                    break;
                }
            }
        }
    }
    return found;
}

int main()
{
    int v1, v2, n;
    vector<vector<int>> *tree = NULL, *tree_t = NULL;
    read(&v1, &v2, &n, &tree, &tree_t);
    if (tree)
    {
        vector<int> found = lca(v1, v2, n, *tree, *tree_t);
        if(!found.size()) {
            printf("-\n");
        }
        else {
            for(int i : found) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    else
    {
        printf("0\n");
    }
    return 0;
}