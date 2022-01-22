#include <iostream>
#include <vector>
using namespace std;

vector<int> colour;
int v1, v2, n;
vector<vector<int>> tree, tree_t;

bool is_acyclic(int v)
{
    colour[v - 1] = 1;
    for (int u : tree_t[v - 1])
    {
        if (colour[u - 1] == 0)
        {
            if (!is_acyclic(u))
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

    cin >> v1 >> v2;
    cin >> n >> m;

    colour.resize(n, 0);
    tree.reserve(n);
    tree_t.reserve(n);

    ios::sync_with_stdio(false);

    for (int i = 0; i < m; i++)
    {
        cin >> pai >> filho;

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

void colour1_dfs(int v)
{
    colour[v - 1] = 5;
    for (int i : tree[v - 1])
    {
        colour1_dfs(i);
    }
}

void colour2_dfs(int v)
{
    if (colour[v - 1] == 5)
    {
        colour[v - 1] = 6;
    }

    for (int i : tree[v - 1])
    {
        if (colour[i - 1] < 6)
            colour2_dfs(i);
    }
}

vector<int> lca()
{
    vector<int> found;
    colour1_dfs(v1);
    colour2_dfs(v2);
    for (int i = 1; i <= n; i++)
    {
        if (colour[i - 1] == 6)
        {
            int t = 1;
            for (int child : tree_t[i - 1])
            {
                if (colour[child - 1] == 6)
                {
                    t = 0;
                    break;
                }
            }
            if (t)
            {
                found.push_back(i);
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
        if (!found.size())
        {
            cout << "-\n";
        }
        else
        {
            for (int i : found)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "0\n";
    }
    return 0;
}