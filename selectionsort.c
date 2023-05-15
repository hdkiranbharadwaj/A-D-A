//Bubble sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int selection_sort(int*,int);
void analyser();
int main()
{
	analyser();
 	system("gnuplot>load 'command.txt'");
}

void analyser()
{

	int key,size,*search_array,index,o;
	clock_t st,et;
 	double t,t1;
	srand(time(NULL));
	FILE *fp2;

	fp2=fopen("Selection.txt","w");

	for(size=100;size<=30000;size=(size<10000?size*10:size+10000))
	{
	search_array=(int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++)
	{
		*(search_array+i)=rand()%size;
	}
		o=selection_sort(search_array,size);
		printf("%d\n",o);
		fprintf(fp2,"%d\t%d\n",size,o);
		free(search_array);
	}
	fclose(fp2);

	}



int selection_sort(int* a,int size)
{
	int count=0,i,j,temp,min;
	for(i=0;i<size;i++)		
	{	min=i;
		for(j=0;j<size-i-1;j++)
		{
			count++;
			if(*(a+j)>*(a+min))
			{
				min=j;
			}			
		}
		temp=*(a+i);
		*(a+i)=*(a+min);
		*(a+min)=temp;
	}
	return count;
}

	



	
