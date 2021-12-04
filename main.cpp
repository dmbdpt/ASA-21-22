#include <iostream>

int main()
{
    int i = 0;
    int *list = (int *)malloc(sizeof(int));
    while (scanf("%i", list[i]))
    {
        list = (int *)malloc(sizeof(list) + sizeof(int));
    }
    return 0;
}w