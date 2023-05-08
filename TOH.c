#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int toh(int,int*);
void analyser(int);
void main()
{
	int i=0;
	analyser(i);
	system("gnuplot>load 'command.txt'");
	
}
void analyser(int p)
{
	int *a, n, o, *count ,k;
	count=&k;
	FILE *t;
        if(p==0)
        {
		t=fopen("toh.txt","w");
	}
	
	srand(time(NULL));
	for(n=100;n<=30000;n=(n<10000?n*10:n+10000))
	{
		
		*count=0;
		toh(n,count);
		o=*count;
		if(o!=-1)
		{
			fprintf(t,"%d\t%d\n", n, o);
			printf("\nTime taken is %d\n\n",o);
		}
	}
	fclose(t);
}
int toh(int n,int* count)
{
        if(n==1)
	(*count)=(*count)+1;
		
	else
		toh(n-1,count);
		*count=(*count)+1;
		toh(n-1,count);
}
