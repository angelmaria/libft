#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int	arr1[] = {1, 2 };
	short int	arr2[] = {1, 2 };

	if (memcmp(arr1, arr2, 2 * sizeof(short int)) == 0)
	{
		printf("Arrays are the same\n");
	} else 
	{
		printf("Arrays are not the same\n");
	}
	return (0);
}
