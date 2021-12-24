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

int main()
{
    int ex;
    string c;
    getline(cin, c);
    ex = stoi(c);

    size_t maxSize = 1, nOfMaxSizeVectors = 1;

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
