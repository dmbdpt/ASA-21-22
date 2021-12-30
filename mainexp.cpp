#include <iostream>
#include <algorithm>
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

void read2(vector<int>* v1, vector<int>* v2) {
    string s1, s2;
    int n;

    vector<int> v1sorted;
    getline(cin, s1);
    istringstream input1(s1);
    while (input1 >> n)
    {
        (*v1).push_back(n);
        v1sorted.push_back(n);
    }

    sort(v1sorted.begin(), v1sorted.end());
    getline(cin, s2);
    istringstream input2(s2);
    while (input2 >> n)
    {
        if(binary_search(v1sorted.begin(), v1sorted.end(), n)) {
            (*v2).push_back(n);
        }
    }
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
    vector<int> max_common_sublist(list2_size, 0);
    int max_inc_common_sub_curr, max_inc_common_sub_final = 0;
  
    for (int i=0; i < list1_size; i++)
    {
        max_inc_common_sub_curr = 0;
  
        for (int j=0; j < list2_size; j++)
        {
            if (list1[i] == list2[j])
            {
                max_common_sublist[j] = max(max_common_sublist[j], max_inc_common_sub_curr + 1);
            }
            if (list1[i] > list2[j])
            {
                max_inc_common_sub_curr = max(max_common_sublist[j], max_inc_common_sub_curr);
            }   
        }
    }

    for (int i=0; i < list2_size; i++)
    {
        max_inc_common_sub_final = max(max_common_sublist[i], max_inc_common_sub_final);
    }
    
    return max_inc_common_sub_final;
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
        vector<int> list1, list2;
        read2(&list1, &list2);
        int list1_size = list1.size(), list2_size = list2.size(), maxSize;
        maxSize = findLongestCommonIncSubsequence(list1, list2, list1_size, list2_size);
        cout << maxSize << '\n';
    }
    break;
    }
    return 0;
}