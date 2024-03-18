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
}
