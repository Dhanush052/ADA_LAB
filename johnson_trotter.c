#include<stdio.h>
#include<stdlib.h>

#define RIGHT_TO_LEFT 0
#define LEFT_TO_RIGHT 1

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int searchArray(int array[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == mobile)
            return i + 1;
    }
    return -1;  // Mobile not found
}

int getMobile(int array[], int dir[], int n)
{
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++)
        {
        // Direction 0 represents RIGHT TO LEFT.
        if (dir[array[i] - 1] == RIGHT_TO_LEFT && i != 0)
            {
            if (array[i] > array[i - 1] && array[i] > mobile_prev)
            {
                mobile = array[i];
                mobile_prev = mobile;
            }
        }

        if (dir[array[i] - 1] == LEFT_TO_RIGHT && i != n - 1)
        {
            if (array[i] > array[i + 1] && array[i] > mobile_prev)
            {
                mobile = array[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
        return 0;  // No mobile element found
    else
        return mobile;
}

void printOnePermutation(int array[], int dir[], int n, int pnum)
{
    int mobile = getMobile(array, dir, n);
    int pos = searchArray(array, n, mobile);

    if (dir[array[pos - 1] - 1] == RIGHT_TO_LEFT)
        swap(&array[pos - 1], &array[pos - 2]);
    else if (dir[array[pos - 1] - 1] == LEFT_TO_RIGHT)
        swap(&array[pos], &array[pos - 1]);


    for (int i = 0; i < n; i++)
    {
        if (array[i] > mobile)
            {
            if (dir[array[i] - 1] == LEFT_TO_RIGHT)
                dir[array[i] - 1] = RIGHT_TO_LEFT;
            else if (dir[array[i] - 1] == RIGHT_TO_LEFT)
                dir[array[i] - 1] = LEFT_TO_RIGHT;
        }
    }
    //printf("Permutation %d:\t",pnum+1);
    for (int i = 0; i < n; i++)
        printf(" %d ",array[i]);

    printf("\n");
}

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void printPermutation(int n)
{
    int array[n],dir[n];
    printf("%d Permutations are:\n",factorial(n));
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
        printf(" %d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        dir[i] = RIGHT_TO_LEFT;//initialize right to left for all
    }

    for (int i = 1; i < factorial(n); i++)
    {
        printOnePermutation(array, dir, n,i);
    }
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printPermutation(n);

    return 0;
}
