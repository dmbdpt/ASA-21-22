#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define PROBLEM_1 1
#define PROBLEM_2 2

vector<int> read()
{
    vector<int> v;
    string c;
    int n;

    getline(cin, c);
    istringstream input(c);
    while (input >> n)
    {
        v.push_back(n);
    }
    return v;
}

void findLargestSubsequences(vector<int> list, long unsigned int *maxSize, long unsigned int *nOfMaxSizeVectors)
{
    vector<vector<vector<int>>> maxSubLists(list.size(), vector<vector<int>>(1));
    maxSubLists[0][0].push_back(list[0]);
    for (size_t i = 1; i < list.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (list[i] > list[j])
            {
                if ((maxSubLists[i][0].size() < (maxSubLists[j][0].size())))
                {
                    maxSubLists[i].clear();
                    for (vector<int> &jvectors : maxSubLists[j])
                    {
                        maxSubLists[i].push_back(jvectors);
                    }
                }
                else if ((maxSubLists[i][0].size() == (maxSubLists[j][0].size())))
                {
                    maxSubLists[i].insert(maxSubLists[i].begin(), maxSubLists[j].begin(), maxSubLists[j].end());
                }
            }
        }
        for (vector<int> &maxSubList : maxSubLists[i])
        {
            maxSubList.push_back(list[i]);
        }
        if (maxSubLists[i][0].size() > *maxSize)
        {
            *maxSize = maxSubLists[i][0].size();
            *nOfMaxSizeVectors = maxSubLists[i].size();
        }
        else if (maxSubLists[i][0].size() == *maxSize)
        {
            *nOfMaxSizeVectors += maxSubLists[i].size();
        }
    }
}

int main()
{
    int ex;
    string c;
    getline(cin, c);
    ex = stoi(c);

    long unsigned int maxSize = 1, nOfMaxSizeVectors = 1;

    switch (ex)
    {
    case PROBLEM_1:
    {
        findLargestSubsequences(read(), &maxSize, &nOfMaxSizeVectors);
    }
    break;
    case PROBLEM_2:
    {
    }
    break;
    }

    cout << maxSize << " " << nOfMaxSizeVectors << '\n';

    return 0;
}
