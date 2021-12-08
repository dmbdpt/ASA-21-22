#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define PROBLEM_1 1
#define PROBLEM_2 2 

vector<int> readListInput() {
    string rawInput;
    vector<int> nums;
    getline(cin, rawInput);
    char *token, *rawInput_aux = strdup(rawInput.c_str());
    token = strtok(rawInput_aux, " ");
    while(token) {
        nums.push_back(stoi(token));
        token = strtok(NULL, " ");
    }
    return nums;
}

vector<vector<vector<int>>> findLargestSubsequences(vector<int> list) {
    vector<vector<vector<int>>> maxSubLists(list.size(), vector<vector<int>>(1));
    maxSubLists[0][0].push_back(list[0]);
    for (int i = 1; i < list.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (list[i] > list[j]) {
                if ((maxSubLists[i][0].size() < (maxSubLists[j][0].size()))) {
                    maxSubLists[i].clear();
                    for(vector<int> &jvectors : maxSubLists[j]) {
                        maxSubLists[i].push_back(jvectors);
                    }
                }
                else if((maxSubLists[i][0].size() == (maxSubLists[j][0].size()))) {
                    maxSubLists[i].insert(maxSubLists[i].begin(), maxSubLists[j].begin(), maxSubLists[j].end());
                }
            }
        }
        for(vector<int> &maxSubList : maxSubLists[i]) {
            maxSubList.push_back(list[i]);
        }
    }
    return maxSubLists;
}

void findLargestVectors(vector<vector<vector<int>>> vectors, int* maxSize, int* nOfMaxSizeVectors) {
    for(vector<vector<int>> v2d : vectors) {
        for(vector<int> v1d : v2d) {
            if(v1d.size() > *maxSize) {
                *maxSize = v1d.size();
                *nOfMaxSizeVectors = 1;
            }
            else if(v1d.size() == *maxSize) {
                *nOfMaxSizeVectors += 1;
            }
        }
    }
}

int main()
{
    int problem_n;

    scanf("%i\n", &problem_n);

    switch(problem_n) {
        case PROBLEM_1 : {
            vector<vector<vector<int>>> maxSubLists = findLargestSubsequences(readListInput());
            int maxSize, nOfMaxSizeVectors;
            findLargestVectors(maxSubLists, &maxSize, &nOfMaxSizeVectors);
            printf("%i %i", maxSize, nOfMaxSizeVectors);
        } break;
        case PROBLEM_2 : {
            vector<vector<vector<int>>> maxSubList1 = findLargestSubsequences(readListInput());
            vector<vector<vector<int>>> maxSubList2 = findLargestSubsequences(readListInput());
        }break;
    }
    return 0;
}

