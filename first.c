#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	int i=1,no_of_edges,no_of_nodes,coordinates[10][10],j=0;
	char line[128],c[10],start,end;
	int weight[10][10];
	fp = fopen("text.txt","r");
	//printf("working!");
	if(fp==NULL)
	{
		printf("error");
		return;
	}
	
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		if(i==1)
		{
		no_of_nodes = (int)line[0]-48;
		no_of_edges = (int)line[2]-48;
		printf("\nno of edges = %d and no of nodes = %d",no_of_edges,no_of_nodes);
		for(int n=0;n<no_of_nodes;n++)
			weight[n][n] = 0;
		}
		else if(i==2)
		{
			//printf("%s",line);
			start = line[0];
			end = line[2];
			printf("\nstart symbol is %c and end symbol is %c",start,end);
		}
		else if(i>=3 && i<= no_of_nodes+2)
		{
			printf("\n%s",line);
			c[j] = line[4];
			coordinates[j][0] = (int)line[0]-48;
			coordinates[j][1] = (int)line[2]-48;
			printf("\n the coordinates of the node %c is (%d %d)",c[j],coordinates[j][0],coordinates[j][1]);
			j++;
		}
		else
		{
			//printf("\n in works");
			for(int l=0;l<no_of_nodes;l++)
			{
				if(line[0]==c[l])
				{
					for(int m=0;m<no_of_nodes;m++)
						if(line[2]==c[m])
						{	
							weight[i][m] = (int)line[4]-48;
							weight[m][i] = (int)line[4]-48;
						}
				}
			}
			
		}
		i++;
	}
	printf("\n");
	for(int l=0;l<no_of_nodes;l++)
	{
		for(int m=0;m<no_of_nodes;m++)
			printf("%d\t",weight[l][m]);
		printf("\n");
	}
	fclose(fp);
 }
