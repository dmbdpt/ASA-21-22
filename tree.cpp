#include <iostream>
#include <vector>
using namespace std;

struct Tree
{
    int val;
    vector<Tree> children;
    Tree *prev;

    Tree(int n)
    {
        val = n;
        prev = NULL;
    }
};

Tree create_tree()
{
    Tree tree(0);
    return tree;
}

Tree insert_node(Tree tree, int n)
{
    if (tree.children.size() == 0)
    {
        tree.children.push_back(Tree(n));
    }
    else
    {
        for (Tree child : tree.children)
        {
            if (child.val < n)
            {
                insert_node(child, n);
            }
        }
    }
    return tree;
}

void print_tree(Tree tree)
{
    for(Tree t: tree.children){
        cout<<t.val<<' ';
        print_tree(t);
    }
}