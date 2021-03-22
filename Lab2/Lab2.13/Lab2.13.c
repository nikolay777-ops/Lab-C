#include <stdio.h>
#include <stdlib.h>
#include "Lab2.13.h"
void printInf()
{
	printf("\nTriangle Calc. Developed by Calc Corp. Version 1.0.0");
}
void countingSide(int* x, int* y, double* side)
{
	int i;
	int Counter;
	Counter = 0;
	for(i = 0; i < 6; i += 2)
	{
		side[Counter] = sqrt(pow((x[i] - x[i+1]), 2) + pow((y[i] - y[i+1]), 2));
		Counter++;
	}
}
int existingTriangleByCoord(int* x, int* y)
{
	int i;
	int j;
	int dot;
	j = 2;
	dot = 0;
	for (i = 1; i < 6; i +=2)
	{
		if(x[i] == x[i + 1] && y[i] == y[i + 1])
		{
			dot++;
		}
	}
	if((x[0] == x[5]) && y[0] == y[5])
	{
		dot++;
	}
	return dot;
}
bool existingTriangleBySides(double* side)
{
	if(side[0] + side[1] > side[2])
	{
		if (side[0] + side[2] > side[1])
		{
			if(side[1] + side[2] > side[0])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
void maxValue(double* site)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		if(site[i+1] > site[i])
		{
			double temp;
			temp = site[i];
			site[i] = site[i+1];
            site[i+1] = temp;
        }
    }
}
void typeTriangle(double* site)
{
    while(true)
    {
        if(existingTriangleBySides(site))
        {
			maxValue(site);
            if(pow(site[0], 2) == (pow(site[1], 2) + pow(site[2], 2)))
            {
				printf("\nIt is Right Triangle.\n");
				break;
			}
			else
			{
				if(pow(site[0], 2) < (pow(site[1], 2) + pow(site[2], 2)))
				{
					printf("\nIt is Acute-Angled Triangle.\n");
					break;
				}
				else
				{
					if(pow(site[0], 2) > (pow(site[1], 2) + pow(site[2], 2)))
					{
						printf("\nIt is Obtuse Triangle\n");
						break;
					}
					else
					{
						if(((float)site[0] == (float)site[1])
						|| ((float)site[0] == (float)site[3]) 
						|| ((float)site[1] == (float)site[2]))
						{
							printf("\nIt is Isosceles Triangle\n");
							break;
						}
						else
						{
							if((int)site[0] == (int)site[1] == (int)site[2])
							{
								printf("\nIt is Equlateral Triangle\n");
								break;
							}
							else
							{
								printf("\nIt is Arbitary Triangle");
								break;
							}
						}
					}
				}
			}
		}
		else
		{
			printf("\nWe can't give type of triangle because it doesn't exists.");
		}
	}
}
void clear(void)
{
	while(getchar() != '\n');
}
void getCoordofTriangle(int* x, int* y)
{
    int k;
    int i;
    int j;
    k = 1;
    for(i = 0; i < 6; i++)
    {
        if( i % 2 != 0)
        {
			printf("Please enter the end x and y coordinates for %d side", k);
		}
		else
		{
			printf("Please enter beginning x and y coordinates for %d side", k);
		}
		while(scanf("%d %d", &x[i], &y[i]) != 2)
		{
			clear();
			printf("Incorrect input, please try again.");
		}
		if (i == 1 || i == 3 || i == 5)
		{
			k++;
		}
	}
}
float perimeter(double* site)
{
	if (existingTriangleBySides(site))
	{
		float perimeter = site[0] + site[1] + site[2];
		printf("\nPerimeter of triangle is %f ", perimeter);
		return perimeter;
	}
	else
	{
		printf("\nWe can't calculate perimeter of triangle because it doesn't exists.\n");
		return 0;
	}
}
void square(double* side)
{
    if(existingTriangleBySides(side) == true)
    {
        float square;
        float per;
		per = perimeter(side);
        per /= 2;
        square = sqrt(per * (per - side[0]) * (per - side[1]) * (per - side[2]));
		printf("\nSquare of triangle is %f ", square);
    }
    else
    {
        printf("We can't calculate square of triangle because it doesn't exists.\n");
    }
}

#ifndef TESTING

int main(void)
{
	int i;
	int perim;
    int* x;
    int* y;
    double* side;
	x = (int*)malloc(sizeof(int) * 6);
	if (!x)
	{
		printf("X wasn't created");
		exit(0);
	}
	y = (int*)malloc(sizeof(int) * 6);
	if (!y)
	{
		printf("Y wasn't created");
		exit(1);
	}
	side = (double*)malloc(sizeof(double) * 3);
	if(!side)
	{
		printf("Side wasn't created");
		exit(1);
	}
	getCoordofTriangle(x, y);
	if (existingTriangleByCoord(x,y) == 3)
	{
		countingSide(x, y, side);
		typeTriangle(side);
		for (i = 0; i < 3; i++)
		{
			printf("Side = %lf", side[i]);
		}
		square(side);
		printInf();
	}
	else
	{
		printf("We can't build trianble by such coordinates");
	}
	free(x);
    free(y);
    free(side);
    return 0;
}
#endif