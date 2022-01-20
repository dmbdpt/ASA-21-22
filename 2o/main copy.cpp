#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <list>
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

vector<vector<int>> *read(int *v1, int *v2, int* n)
{
    int pai, filho, m;

    if (!scanf("%i %i", v1, v2))
        return NULL;

    if (!scanf("%i %i", n, &m))
        return NULL;

    static vector<vector<int>> matrix1(*n);
    vector<int> colour(*n, 0);

    for (int i = 0; i < m; i++)
    {
        if (!scanf("%i %i", &pai, &filho))
            return NULL;

        if (matrix1[filho - 1].size() == 2)
            return NULL;

        matrix1[filho - 1].push_back(pai);
    }

    for (int i = 1; i <= *n; i++)
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

int lca(int v1, int v2, int n, vector<vector<int>> tree) {
    vector<int> colour(n, 0);
    list<int> queque;
    int curr, found = 0;;

    colour[v1] = 1;
    queque.push_back(v1);

    while(!queque.empty()) {

        curr = queque.front();
        queque.pop_front();

        for(int adj : tree[curr]) {
            colour[adj] = 1;
            queque.push_back(adj);
        }
    }

    queque.push_back(v2);
    if(colour[v2]) {
        printf("%d ", v2);
        found++;
    }

    while(!queque.empty()) {

        curr = queque.front();
        queque.pop_front();

        for(int adj : tree[curr]) {
            queque.push_back(adj);
            if(colour[adj]) {
                printf("%d ", adj);
                found++;
                if(found == 2) {
                    return found;
                }
            }
        }
    }
    return found;  
}

int main()
{
    int v1, v2, n;
    vector<vector<int>> *tree = read(&v1, &v2, &n);
    if (tree)
    {
        int found = lca(v1, v2, n, *tree);
        if(!found) {
            printf("-");
        }
        printf("\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}