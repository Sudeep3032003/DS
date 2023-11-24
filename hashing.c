#include <stdio.h>
#define size 7

int arr[size];
int i;

void init()
{
    for (i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;

    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision: arr[%d] has element %d already!\n", key, arr[key]);
        int original_key = key;
        key = (key + 1) % size;

        while (key != original_key)
        {
            if (arr[key] == -1)
            {
                arr[key] = value;
                printf("%d inserted at arr[%d]\n", value, key);
                return;
            }
            key = (key + 1) % size;
        }

    }
}

void del(int value)
{
    int key = value % size;
    if (arr[key] == value)
    {
        arr[key] = -1;
        printf("%d is deleted from arr[%d]\n", value, key);
    }
    else
        printf("%d not present in the hash table\n", value);
}

void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
        printf("Search Found\n");
    else
    {
        int i = 1;
        int originalKey = key;

            key = (originalKey + i) % size;
            i++;

        arr[key] = value;
        printf("%d stored at arr[%d]\n", value, key);
    }
}

int main()
{
    init();
    insert(12);
    insert(15);
    insert(22);
    insert(35);
    insert(40);
    del(22);
    del(15);
    search(12);
    return 0;
}
