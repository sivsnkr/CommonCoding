#include <stdio.h>

int main(void)
{
    int arr[200000] = {0};
    for (int i = 0; i < 200000; i++)
        arr[i] = 2;
    printf("%d\n", arr[1000]);
}