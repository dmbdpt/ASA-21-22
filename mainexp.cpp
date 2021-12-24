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
    size_t size = list.size();
    vector<size_t> max_size_list(size, 1), n_of_max_size_list(size, 1);

    if(size < 1) {
        *maxSize = 0;
        *nOfMaxSizeVectors = 0;
        return;
    }

    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
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

size_t findLongestCommonSubsequence(vector<int> list1, vector<int> list2, size_t list1_size, size_t list2_size)
{
    if(list1_size == 0 || list2_size == 0)
    {
        return 0;
    }
    if(list1[list1_size-1] == list2[list2_size-1])
    {
        return 1 + findLongestCommonSubsequence(list1, list2, list1_size-1, list2_size-1);
    }
    else
    {
        return max(findLongestCommonSubsequence(list1, list2, list1_size, list2_size-1), findLongestCommonSubsequence(list1, list2, list1_size-1, list2_size));
    }
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
        size_t maxSize = 1, nOfMaxSizeVectors = 1;
        findLargestSubsequences(read(), &maxSize, &nOfMaxSizeVectors);
        cout << maxSize << " " << nOfMaxSizeVectors << '\n';
    }
    break;
    case PROBLEM_2:
    {
        vector<int> list1 = read(), list2 = read();
        size_t list1_size = list1.size(), list2_size = list2.size(), maxSize;
        maxSize = findLongestCommonSubsequence(list1, list2, list1_size, list2_size);
        cout << maxSize << '\n';
    }
    break;
    }
    return 0;
}
