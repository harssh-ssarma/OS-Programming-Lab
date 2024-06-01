#include <stdio.h>
int main()
{
	int count = 0, m, n, process, temp, resource;
	int allocation_table[5] = {0, 0, 0, 0, 0};
	int available[5], current[5][5], maximum_clAim[5][5];
	int maximum_resources[5], running[5], safe_state = 0;
	printf("Enter The Total Number Of Processes: ");
	scanf("%d", &process);
	for(m = 0; m < process; m++)
	{
		running[m] = 1;
		count++;
	}
	printf("Enter The Total Number Of Resources To Allocate: ");
	scanf("%d", &resource);
	printf("Enter The Claim Vector: ");
	for(m = 0; m < resource; m++)
	{
		scanf("%d", &maximum_resources[m]);
	}
	printf("Enter Allocated Resource Table: ");
	for(m = 0; m < process; m++)
	{
		for(n = 0; n < resource; n++)
		{
			scanf("%d", &current[m][n]);
		}
	}
	printf("Enter The Maximum Claim Table: ");
	for(m = 0; m < process; m++)
	{
		for(n = 0; n < resource; n++)
		{
			scanf("%d", &maximum_clAim[m][n]);
		}
	}
	printf("The Claim Vector: ");
	for(m = 0; m < resource; m++)
	{
		printf("\t%d ", maximum_resources[m]);
	}
	printf("\nThe Allocated Resource Table\n");
	for(m = 0; m < process; m++)
	{
		for(n = 0; n < resource; n++)
		{
			printf("\t%d", current[m][n]);
		}
		printf("\n");
	}
	printf("The Maximum Claim Table\n");
	for(m = 0; m < process; m++)
	{
		for(n = 0; n < resource; n++)
		{
			printf("\t%d", maximum_clAim[m][n]);
		}
		printf("\n");
	}
	for(m = 0; m < process; m++)
	{
		for(n = 0; n < resource; n++)
		{
			allocation_table[n] = allocation_table[n] + current[m][n];
		}
	}
	printf("Allocated Resources");
	for(m = 0; m < resource; m++)
	{
		printf("\t%d", allocation_table[m]);
	}
	for(m = 0; m < resource; m++)
	{
		available[m] = maximum_resources[m] - allocation_table[m];
	}
	printf("\nAvailable Resources:");
	for(m = 0; m < resource; m++)
	{
	printf("\t%d", available[m]);
	}
	
	while(count != 0)
	{
		safe_state = 0;
		for(m = 0; m < process; m++)
		{
			if(running[m])
			{
				temp = 1;
				for(n = 0; n < resource; n++)
				{
					if(maximum_clAim[m][n] - current[m][n] > available[n])
					{
						temp = 0;
						break;
					}
				}
				if(temp)
				{
					printf("\nProcess %d Is In Execution \n", m + 1);
					running[m] = 0;
					count--;
					safe_state = 1;
					for(n = 0; n < resource; n++)
					{
						available[n] = available[n] + current[m][n];
					}
					break;
				}
			}
		}
		if(!safe_state)
		{
			printf("\nThe Processes Are In An Unsafe State\n");
			break;
		}
		else
		{
			printf("\nThe Process Is In A Safe State \n");
			printf("\nAvailable Vector\n");
			for(m = 0; m < resource; m++)
			{
				printf("\t%d", available[m]);
			}
			printf("\n");
		}
	}
	return 0;
}
