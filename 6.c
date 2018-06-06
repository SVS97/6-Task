#include <stdio.h>

#define N 10

struct retdata {
	int min, max;
	float avg;
};

int super_func(int *arr, unsigned int len, struct retdata *ret)
{
	int cnt;
	int min, max, avg;

	avg = 0;

	if (len == 0)
	{
		//cheking by 0 length of string
		return -1;
	}

	min = max = *arr;
	// min and max elements of array
	for (cnt = 0; cnt < len; cnt++)
	{
		min = (min > *arr) ? *arr : min;
		max = (max < *arr) ? *arr : max;

		avg += *arr;

		arr++;
	}
	// appeal to the structure
	ret->min = min;
	ret->max = max;
	ret->avg = (float)avg / len;

	return 0;
}

int main(void)
{
	int testArray[N] = { 0,1,2,3,4,5,6,7,8,9 };
	struct retdata data;
	// checking incorrect input
	if (super_func(&testArray, N, &data) == -1)
	{
		printf("Error\n");
	}
	else
	{

		printf("Min = %d\n", data.min);
		printf("Max = %d\n", data.max);
		printf("Avg = %.2f\n", data.avg);
	}


}