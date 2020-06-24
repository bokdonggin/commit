
/*
* Date : 2020 06 24
*/

#include<stdio.h>

char my_data[5] = {'A', 'B', 'D', 'E'};
char c;

void main()
{

	int search_data, insert_data;

	int i;

	for (i = 0; i < 5; i++)
	{
		if (my_data[i] > 'C')
			break;
	}

	search_data = my_data[i];
	my_data[i] = 'C';
	i++; 

	for (; i < 5; i++)

	{
		insert_data = my_data[i];

		my_data[i] = search_data;

		search_data = insert_data;

	}

	for (i = 0; i < 5; i++)
		printf("%2c", my_data[i]);
    
	return 0;
}
