#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

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

void exer1(vector<int> a)
{
    vector<vector<int>> final;
    for(int i : a){
        
    }
}

void exer2()
{
}

int main()
{
    int ex;
    string c;
    getline(cin, c);
    ex = stoi(c);

    if (ex == 1)
        exer1(read());
    else
        exer2();
    return 0;
}
