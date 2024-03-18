#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int	arr1[] = { 3, 4 }; // 0 0 0 3 0 0 0 4
	int	arr2[] = { 1, 2 };

	if (memchr(arr2, 1, sizeof(int) * 2) != NULL) 
	{
		printf("Found the byte!\n");
	} else {
		printf("Did not find the byte!\n");
	}
	return (0);
}
