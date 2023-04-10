#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Search(int*,int,int);
void main()
{
	int *a, n, k, i, o;
	FILE *f,*t;
	double timee;
    clock_t st, et;
        f=fopen("L_searchdata.txt","a");
	t=fopen("time.txt","w");
	srand(time(NULL));

	for(n=100;n<=30000;n=(n<10000?n*10:n+10000))
	{
		a=(int*)malloc(n*sizeof(int));

		for(i=0;i<n;i++)
		{
			*(a+i)=rand()%n;
			fprintf(f,"%d\t",*(a+i));
		}
	
		k=*(a+n-1)=-1;
		st=clock();
		o=Search(a,k,n);
		et=clock();
		
		timee=(double)(et-st)/CLOCKS_PER_SEC;
		
		if(o!=-1)
		{
			fprintf(t,"%d\t%f\n", n, timee);
			printf("\nTime taken is %f\n\n",timee);
		}
		else
		printf("Element not found");
		free(a);
	}
	fclose(f);
	fclose(t);
	//system("gnuplot>load 'command.txt'");
	
}
int Search(int *a, int k, int n)
{
	int i, count=0;
	for(i=0;i<n;i++)
	{
		count++;
		if(*(a+i)==k)
		{
			printf("Count : %d",count);
			return i+1;
		}
	}
	printf("Count : %d",count);
	return -1;
}
