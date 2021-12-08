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

int main()
{
    int problem_n;

    scanf("%i\n", &problem_n);

    switch(problem_n) {
        case PROBLEM_1 : {
            vector<int> nums = readListInput();
        } break;
        case PROBLEM_2 : {
            vector<int> nums1 = readListInput(), nums2 = readListInput();
            printf("%li %li", nums1.size(), nums2.size());
        }break;
    }
    return 0;
}


