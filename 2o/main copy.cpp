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

int lca(int v1, int v2, int n, vector<vector<int>> tree) 
{
    vector<int> colour(n, 0), colour1(n, 0), found;
    list<int> queque;
    int curr, found_n = 0, min_d = 999999;

    colour[v1-1] = 1;
    queque.push_back(v1);

    while(!queque.empty()) {

        curr = queque.front();
        queque.pop_front();

        for(int adj : (tree)[curr-1]) {
            colour[adj-1] = colour[curr-1] + 1;
            queque.push_back(adj);
        }
    }

    colour1[v2-1] = 1;
    queque.push_back(v2);

    while(!queque.empty()) {

        curr = queque.front();
        queque.pop_front();

        for(int adj : (tree)[curr-1]) {
            colour1[adj-1] = colour1[curr-1] + 1;
            queque.push_back(adj);
        }
    }

    for(int i = 0; i < n; i++) {
        if(colour[i] && colour1[i]) {
            if(min_d > min(colour[i], colour1[i])) {
                min_d = min(colour[i], colour1[i]);
                found.clear();
                found.push_back(i+1);
                found_n = 1;
            }
            else if(min_d == min(colour[i], colour1[i])) {
                found.push_back(i+1);
                found_n++;
            }
        }
    }
    for(int i : found) {
        printf("%d ", i);
    }
    return found_n;  
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