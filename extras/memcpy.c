#include <stdio.h>
#include <string.h>

int	main()
{
	char src[] = "copy this";
	char dest[100];

	memcpy(dest, src, strlen(src) + 1);

	printf("src: %s\n", src);
	printf("dst: %s\n", dest);

	double src_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double dest_array[5];

	memcpy(dest_array, src_array, sizeof(src_array));

	for (int i = 0; i < 5; i++)
		printf("dest_array[%d] = %f\n", i, dest_array[i]);

	return (0);
}
