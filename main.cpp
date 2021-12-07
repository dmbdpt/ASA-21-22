#include <iostream>

#define PROBLEM_1 1 
#define PROBLEM_2 2 


int main()
{
    int i = 0;
    int problem_n;
    int *list = (int *)malloc(sizeof(int));

    scanf("%i", problem_n);
    while (scanf("%i", list[i++]))
    {
        list = (int *)malloc(sizeof(list) + sizeof(int));
    }
    return 0;

    switch(problem_n) {
        case PROBLEM_1:
            break;
        case PROBLEM_2:
            break;
    }
}