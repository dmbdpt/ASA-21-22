#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> colour, colour_1;
int v1, v2, n;
vector<vector<int>> tree, tree_t;

bool is_acyclic(int v)
{
    colour[v - 1] = 1;
    for (int u : tree_t[v - 1])
    {
        if (colour[u - 1] == 0)
        {
            if(!is_acyclic(u)) 
                return false;
        }
        else if (colour[u - 1] == 1)
        {
            return false;
        }
    }
    colour[v - 1] = 2;
    return true;
}

bool read()
{
    int pai, filho, m;

    if (!scanf("%i %i", &v1, &v2))
        return false;

    if (!scanf("%i %i", &n, &m))
        return false;

    colour.resize(n, 0);
    colour_1.resize(n, 0);
    tree.resize(n);
    tree_t.resize(n);

    for (int i = 0; i < m; i++)
    {
        if (!scanf("%i %i", &pai, &filho))
            return false;

        if (tree[filho - 1].size() == 2)
            return false;

        tree[filho - 1].push_back(pai);
        tree_t[pai - 1].push_back(filho);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!colour[i - 1])
        {
            if (!is_acyclic(i))
            {
                return false;
            }
        }
    }
    return true;
}

void colour1_dfs(int v) {
    colour_1[v-1] = 1;
    for(int i : tree[v-1]) {
        if(colour_1[i-1] != 1)
            colour1_dfs(i);
    }
}

void colour2_dfs(int v) {
    if(colour_1[v-1]) {
        colour_1[v-1] = 2;
    } else {
        colour_1[v-1] = 3;
    }
    for(int i : tree[v-1]) {
        if(colour_1[i-1] < 2) 
            colour2_dfs(i);
    }
}

vector<int> lca() 
{
    vector<int> found;
    colour1_dfs(v1);
    colour2_dfs(v2);
    for(int i = 1; i <= n; i++) {
        if(colour_1[i-1] == 2) {
            found.push_back(i);
            for(int child : tree_t[i-1]) {
                if(colour_1[child - 1] == 2) {
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
    if (read())
    {
        vector<int> found = lca();
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