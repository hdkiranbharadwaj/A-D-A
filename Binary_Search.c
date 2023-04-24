#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Search(int*,int,int);
void analyser(int);
void main()
{
	int i=0;
	for(i=0;i<2;i++)
		analyser(i);

	
	
	system("gnuplot>load 'command.txt'");
	
}
void analyser(int p)
{
	int *a, n, k, i, o;
	FILE *f,*t;
	double timee;
    	clock_t st, et;
        f=fopen("L_searchdata.txt","a");
        if(p==0)
        {
		t=fopen("worst_case.txt","w");
	}
	else
	{
		t=fopen("best_case.txt","w");
	}
	srand(time(NULL));
	for(n=100;n<=30000;n=(n<10000?n*10:n+10000))
	{
		a=(int*)malloc(n*sizeof(int));

		for(i=0;i<n;i++)
		{
			*(a+i)=i+100;
			fprintf(f,"%d\t",*(a+i));
		}
		k=(p==0)?*(a+n-1):*(a+((n-1)/2));
		o=0;
		o=Search(a,k,n);
		if(o!=-1)
		{
			fprintf(t,"%d\t%d\n", n, o);
			printf("\nTime taken is %d\n\n",o);
		}
		else
		printf("Element not found");
		free(a);
	}
	fclose(f);
	fclose(t);
}
int Search(int *a, int k, int n)
{
	int lb=0, ub=n-1, mid, count=0;
	while(lb<ub)
	{
		count++;
		mid=(lb+ub)/2;
		if(*(a+mid)==k)
		{
			return count;
		}
		else if(*(a+mid)>k)
				lb=mid+1;
		else
			 ub=mid-1;
	}
	return count;
}
