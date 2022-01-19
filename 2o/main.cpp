#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

bool is_acyclic(int v, vector<vector<int>> matrix, vector<char> colour)
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

vector<vector<int>> *read(int *v1, int *v2)
{
    int pai, filho, n, m;

    if (!scanf("%i %i", v1, v2))
        return NULL;

    if (!scanf("%i %i", &n, &m))
        return NULL;

    static vector<vector<int>> matrix1(n);
    vector<char> colour(n, 0);

    for (int i = 0; i < m; i++)
    {
        if (!scanf("%i %i", &pai, &filho))
            return NULL;

        if (matrix1[filho - 1].size() == 2)
            return NULL;

        matrix1[filho - 1].push_back(pai);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!colour[i - 1])
        {
            if (!is_acyclic(i, matrix1, colour))
            {
                return NULL;
            }
        }
    }
    return &matrix1;
}

int main()
{
    int *v1 = (int *)malloc(sizeof(int)), *v2 = (int *)malloc(sizeof(int));
    vector<vector<int>> *tree = read(v1, v2);
    if (tree)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}