#include <stdio.h>
#include <string.h>

int	main(void)
{
	char buffer[10];

	memset(buffer, 'c', sizeof(char) * 5);
	memset(buffer+5, 'd', sizeof(char) * 5);

	int	i;
	
	i = 0;
	while (i < 10)
	{
		printf("%c", buffer[i]);
		i++;
	}
	printf("\n");

	int	arr1[] = {3, 4};
	int	arr2[] = {1, 2};

	memset(arr1, 0, 2 * sizeof(int));
	printf("%d %d\n", arr1[0], arr1[1]);
	return (0);
}
