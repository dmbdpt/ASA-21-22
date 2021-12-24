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

void findLargestSubsequences(vector<int> list, int *maxSize, int *nOfMaxSizeVectors)
{
    int size = list.size();
    vector<int> max_size_list(size, 1), n_of_max_size_list(size, 1);

    if(size < 1) {
        *maxSize = 0;
        *nOfMaxSizeVectors = 0;
        return;
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[i] > list[j])
            {
                if ((max_size_list[j] + 1) > max_size_list[i])
                {
                    max_size_list[i] = max_size_list[j] + 1;
                    n_of_max_size_list[i] = n_of_max_size_list[j];
                }
                else if ((max_size_list[j] + 1) == max_size_list[i])
                {
                    n_of_max_size_list[i] += n_of_max_size_list[j];
                }
            }
        }
        if (max_size_list[i] > *maxSize)
        {
            *maxSize = max_size_list[i];
            *nOfMaxSizeVectors = n_of_max_size_list[i];
        }
        else if (max_size_list[i] == *maxSize)
        {
            *nOfMaxSizeVectors += n_of_max_size_list[i];
        }
    }
}

size_t findLongestCommonIncSubsequence(vector<int> list1, vector<int> list2, int list1_size, int list2_size)
{
    
}

int main()
{
    int ex;
    string c;
    getline(cin, c);
    ex = stoi(c);

    switch (ex)
    {
    case PROBLEM_1:
    {
        int maxSize = 1, nOfMaxSizeVectors = 1;
        findLargestSubsequences(read(), &maxSize, &nOfMaxSizeVectors);
        cout << maxSize << " " << nOfMaxSizeVectors << '\n';
    }
    break;
    case PROBLEM_2:
    {
        vector<int> list1 = read(), list2 = read();
        int list1_size = list1.size(), list2_size = list2.size(), maxSize;
        maxSize = findLongestCommonIncSubsequence(list1, list2, list1_size, list2_size);
        cout << maxSize << '\n';
    }
    break;
    }
    return 0;
}
