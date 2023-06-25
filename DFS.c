#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int a[MAX][MAX], visited[MAX], n, acyclic = 1;
int count = 1, cc = 1;

void dfs(int v)
{
    int i;
    count += 1;
    visited[v] = count;
    printf("%d->", v);
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] && visited[i] != 0)
        {
            acyclic = 0;
        }

        if (a[v][i] && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

void DFS(int start)
{
    int i;
    visited[start] = count;
    printf("\n%d->", start);
    for (int i = 1; i <= n; i++)
    {
        if (a[start][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
    if (count < n)
    {
        cc += 1;
        printf("\nThe graph is disconnected the other connected component is:");
        i = 1;
        while (visited[i] != 0 && i <= n)
        {
            i++;
        }
        count++;
        DFS(i);
    }
}

void checkcyclicity()
{
    if (acyclic)
        printf("\nGraph is acyclic");
    else
        printf("\nGraph is cyclic");
    if (cc == 1)
        printf("\nThe graph is strongly connected");
    else
        printf("The Total number of connected components are:%d", cc);
}

void main()
{
    int i, j;
    int start;
    printf("enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter the starting vertex:");
    scanf("%d", &start);
    for (i = 1; i <= n; i++) // Setup
    {
        visited[i] = 0;
    }
    DFS(start);
    printf("\n");
    checkcyclicity();
}
