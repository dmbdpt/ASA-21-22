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

vector<int> ancestor(int v1, vector<vector<int>> tree)
{
    vector<int> final;
    if (!tree[v1 - 1].empty())
        for (int parent : tree[v1 - 1])
        {
            if (parent != 0)
            {
                final.push_back(parent);
                vector<int> parentanc = ancestor(parent, tree);
                final.insert(final.end(), parentanc.begin(), parentanc.end());
            }
        }
    return final;
}

vector<int> lca(int v1, int v2, vector<vector<int>> tree)
{
    vector<int> ancestor1 = ancestor(v1, tree);
    ancestor1.push_back(v1);
    vector<int> ancestor2 = ancestor(v2, tree);
    ancestor2.push_back(v2);
    sort(ancestor1.begin(), ancestor1.end());
    sort(ancestor2.begin(), ancestor2.end());
    vector<int> final;
    set_intersection(ancestor1.begin(), ancestor1.end(), ancestor2.begin(), ancestor2.end(), back_inserter(final));
    for (int i : final)
    {
        for (int j : tree[i - 1])
        {
            vector<int>::iterator f = find(final.begin(), final.end(), j);
            if (f != final.end())
            {
                final.erase(f);
            }
        }
    }
    return final;
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
    int v1, v2;
    vector<vector<int>> *tree = read(&v1, &v2);
    if (tree)
    {
        vector<int> final = lca(v1, v2, *tree);
        if (!final.size())
        {
            printf("0\n");
            return 0;
        }
        for (int i : final)
        {
            if (i != 0)
                printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        printf("-\n");
    }
    return 0;
}