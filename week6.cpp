#include<stdio.h>
int main()
{
	int n,m,i,j,alloc[100][100],max[100][100],need[100][100],avail[100],total[10],count=0,temp=0,k,l,tank=0;
	printf("enter no of process :");
	scanf("%d",&n);
	printf("enter no of resource instances :");
	scanf("%d",&m);
	printf("enter total no of resource instances :\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&total[i]);
	}
	printf("enter allocation resource instances\n");
	for(i=0;i<n;i++)
	{
		printf("p[%d]\n",i+1);
		for(j=0;j<m;j++)
		{
			printf("alloc[%d][%d] :",i,j);
			scanf("%d",&alloc[i][j]);	
		}
	}
	printf("enter maximum allocation resource instances\n");
	for(i=0;i<n;i++)
	{
		printf("p[%d]\n",i+1);
		for(j=0;j<m;j++)
		{
			printf("max[%d][%d] :",i,j);
			scanf("%d",&max[i][j]);	
		}
	}
	printf("need resource instances for process\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		printf("p[%d]\n",i+1);
		for(j=0;j<m;j++)
		{
			printf("%d",need[i][j]);
		}
		printf("\n");
	}
	printf("enter available resource instances :\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&avail[j]);
	}
	while(1)
	{
		for(i=0;i<n;i++)
		{
			temp=0;
			for(j=0;j<m;j++)
			{
				if(need[i][j]<=avail[j])
				{
					temp++;
					if(temp==m)
					{
						for(k=i;k<i+1;k++)
						{
							for(l=0;l<m;l++)
							{
								avail[l]=avail[l]+max[k][l];
								need[k][l]=need[k][l]+total[l];
							}
						}						
					}	
				}
			}
		}
		for(j=0;j<m;j++)
		{
			if(total[j]==avail[j])
			{
				tank++;
			}
		}
		if(tank==m)
		{
			break;
		}
	}
	for(j=0;j<m;j++)
	{
		if(total[j]==avail[j])
		{
			count++;
		}
	}
	printf("\n---------bankers algorithm------------\n");
	if(count==m)
	{
		printf("\nsystem is in safe state");
	}
	else
	{
		printf("\nsystem is in unsafe state");
	}
}	
/* ouput :
enter no of process :5
enter no of resource instances :3
enter total no of resource instances :
28
15
14
enter allocation resource instances
p[1]
alloc[0][0] :0
alloc[0][1] :1
alloc[0][2] :0
p[2]
alloc[1][0] :2
alloc[1][1] :0
alloc[1][2] :0
p[3]
alloc[2][0] :3
alloc[2][1] :0
alloc[2][2] :2
p[4]
alloc[3][0] :2
alloc[3][1] :1
alloc[3][2] :1
p[5]
alloc[4][0] :0
alloc[4][1] :0
alloc[4][2] :2
enter maximum allocation resource instances
p[1]
max[0][0] :7
max[0][1] :5
max[0][2] :3
p[2]
max[1][0] :3
max[1][1] :2
max[1][2] :2
p[3]
max[2][0] :9
max[2][1] :0
max[2][2] :2
p[4]
max[3][0] :2
max[3][1] :2
max[3][2] :2
p[5]
max[4][0] :4
max[4][1] :3
max[4][2] :3
need resource instances for process
p[1]
743
p[2]
122
p[3]
600
p[4]
011
p[5]
431
enter available resource instances :
3
3
2
---------bankers algorithm------------

system is in safe state
--------------------------------
*/	
