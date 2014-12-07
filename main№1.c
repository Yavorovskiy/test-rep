#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ERROR { printf("[error]\n"); return 0; }
int is_prime(int n)
{
	if (n<=1) return 0;
	int sqrt_of_n=(int)sqrt((double)n);
	for (int i=2; i<=sqrt_of_n; i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int lesser_prime(int* arr, size_t n) 
{
	int ret_value=0;
	if (n<=0||arr==NULL) return ret_value;
	for (int i=0; i<(int)n; i++)
	{
		if (is_prime(*(arr+i)))
		{
			if (ret_value==0) ret_value=*(arr+i);
			else if (*(arr+i)<ret_value) ret_value=*(arr+i);
		}
		if (ret_value==2) break;
	}
	return ret_value;	
}
int main()
{
	int* arr=NULL;
	size_t n=0;
	if (scanf("%zu", &n) != 1) ERROR;
	if (n<=0) ERROR;
	arr=(int*)malloc(n*sizeof(int));
	if (arr == NULL) ERROR;
	for (int i=0; i<(int)n; i++) 
	{
		if (scanf("%i", arr+i) != 1) {
			free(arr);
			ERROR;
		}
	}
	int rezult=lesser_prime(arr,n);
	if (rezult==0) printf("[error]\n");
	else printf("%i\n", rezult);
	free(arr);
	return 0;
}