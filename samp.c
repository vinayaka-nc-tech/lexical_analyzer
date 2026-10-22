
#include <stdio.h>

    int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int i = 0;
    float avg = 12.34;

    for (i = 0; i < 5; i++)
    {
        if (arr[i] >= 20 && arr[i] != 40)
        {
            avg = avg + arr[i];
        }
    }

    while (i > 0)
    {
        i--;
    }

    return 0;
}
