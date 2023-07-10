#include <stdio.h>
#include <stdlib.h>
struct item
{
    int number;
    int weight;
    int value;
};
typedef struct item itm;
int max, n;

void getdata(itm *Head)
{
    printf("Enter the number of items and the max capacity of the knapsack: \n");
    scanf("%d%d", n, max);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the weight and value of the %d item\n", i);
        scanf("%d%d", &(Head[i]->weight), &(Head[i]->value));
    }
    print("%d", Head[1]->value);
}
void main()
{
    itm Head[10];
    getdata(&Head);
}
