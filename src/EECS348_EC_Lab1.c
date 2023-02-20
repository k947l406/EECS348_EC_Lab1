/*
============================================================================
Author: Ky Le
KUID: 3050474
Date: 2/19/2023
EECS 368 Extra Credit Lab 1
Last modified: 2/19/2023
Purpose: matching
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//This program will only support 5 programmers and departments
//Additional or reduced numbers will require adjustments
int main(void) {
	//markers to check if the programmer is taken
	int ptaken[5] = {0,0,0,0,0};
	//markers to check if the department has a programmer already
	int dhas[5] = {0,0,0,0,0};

	int pCount = 5; //number of programmers
	int dCount = 5; //number of departments
	int Programmers[5][5] = {{3,1,2,5,4},{4,3,1,5,2},{2,5,4,1,3},{4,5,2,1,3},{3,2,1,5,4}};
	int Departments[5][5] = {{1,5,3,2,4},{1,3,4,2,5},{3,4,2,5,1},{3,1,2,4,5},{4,3,1,2,5}};

	//puts("This is a test"); /* prints This is a test */
	//This block prints out the programmer's department preferences in order
	for (int i = 0; i < pCount; i++)
	{
		printf("Programmer #%d Preference: ", (i+1));
		for (int j = 0; j < dCount; j++)
		{
			printf("%d ", Programmers[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//This block prints out the department's preferences in order
	for (int i = 0; i < dCount; i++)
	{
		printf("Department #%d Preference: ", (i+1));
		for (int j = 0; j < pCount; j++)
		{
			printf("%d ", Departments[i][j]);
		}
		printf("\n");
	}




	for (int n = 0; n < 5; n++)
	{
		//reassignment of markers to check if the programmer is taken
		ptaken[n] = 0;
		//reassignment markers to check if the department has a programmer already
		dhas[n] = 0;
	}
	printf("\n");
	//loop through all the programmers and match each of them with a department
	//start by looping through each of the programmers to see which department wants them
	//printf("This assignment assigns by each department's first choice first.\n");
	//printf("This is not the expected lab outcome as the lab's tiebreaker for programmer #1 results in a three-way tiebreaker from programmer #2\n");
	for (int l = 0; l < 5; l++)
	{
		for (int i = 0; i < pCount; i++)
		{
			//set up an empty array of department l choices that match programmer i
			int want[5] = {0,0,0,0,0}; //five total departments
			//loop through each of the departments to see if they want programmer i
			for (int j = 0; j < dCount; j++)
			{
				if ((i+1) == Departments[j][l]) //counting starts at 0 but departments and programmers start at 1
				{
					//first check if department j already has a programmer
					//printf("Department #%d status: %d \n", (j+1), dhas[j]);
					if (0 != dhas[j])
					{
						//do nothing because department only wants 1 programmer
					}
					else
					{
						want[j] = 1; //set true for department j that it wants programmer i for choice l
						//printf("Department #%d wants programmer #%d\n", (j+1), (i+1));
					}
				}
				//now we go through the programmer i's choices and see which department number comes first
				//loop through each of the choices in priority order
				//if the want is a 1, that means yes, the department wants the programmer
				for (int k = 0; k < 5; k++)
				{
					if (0 == ptaken[i])
					{
						int choice = Programmers[i][k];
						//printf("Programmer #%d wants department #%d \n", (i+1), choice);
						if (1 == want[(choice-1)])
						{
							//printf("Department #%d will get programmer #%d \n", choice, (i+1));
							//end the loop because there is no need to go any further
							ptaken[i] = choice;
							dhas[choice-1] = i+1;
						}
					}
				}
				//printf("\n");
			}
		}
	}
	for (int h = 0; h < 5; h++)
	{
		printf("Department #%d will get programmer #%d \n", (h+1), ptaken[h]);
	}
	return 0;
}
