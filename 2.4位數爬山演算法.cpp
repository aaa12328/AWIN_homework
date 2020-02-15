#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int abs(int ans);


int main (void)
{
	int guess[4] ={0},answer[4]={0},a,b,times=0,best_cost=0,bestcost=0,upcost=0,downcost=0,x,y;

	printf("請輸入4位數正解：");
	scanf("%d",&a);
	
	for(int b=3 ; b>=0;b--)
	{
		answer[b]=a%10;
		a/=10;
	}
	
	int guess_random=0,count_random=0;
	
	srand( time(NULL) );

	for(int i=0;i<4;i++)
	{
		guess[i] = rand() % (9 - 0 + 1) + 0;
	}

	for(int j=0;j<4;j++)
	{
		bestcost=abs(guess[j]-answer[j]);
		best_cost=bestcost+best_cost;
	}	
	
	times++;
	printf("\n第一次猜測：%d%d%d%d  差距為 : %d\n\n",guess[0],guess[1],guess[2],guess[3],best_cost);
	
	while(best_cost != 0 )
	{	
		guess_random=rand() % (3 - 0 + 1) + 0;
		count_random=rand() % (1 - 0 + 1) + 0;
		
		printf("上一次較優猜測為：%d%d%d%d\t",guess[0],guess[1],guess[2],guess[3]);

		if(guess[guess_random]==0)
		{
			times++;
			x=guess[guess_random];
			guess[guess_random]+=1;
			upcost=abs(guess[0]-answer[0])+abs(guess[1]-answer[1])+abs(guess[2]-answer[2])+abs(guess[3]-answer[3]);
			printf("差距為： %d ,第 %d 位數 +1 後差距：%d \n",best_cost,guess_random+1,upcost);
			printf("故第 %d 次猜測： %d%d%d%d\t差距為： %d \n\n",times,guess[0],guess[1],guess[2],guess[3],upcost);
			if(upcost < best_cost)
			{
				best_cost = upcost;
			}
			else
			{
				guess[guess_random]=x;
			}
		}
		else if(guess[guess_random]==9)
		{
			times++;
			y=guess[guess_random];
			guess[guess_random]=guess[guess_random]-1;
			downcost=abs(guess[0]-answer[0])+abs(guess[1]-answer[1])+abs(guess[2]-answer[2])+abs(guess[3]-answer[3]);
			printf("差距為： %d ,第 %d 位數 -1 後差距 ： %d \n",best_cost,guess_random+1,downcost);
			printf("故第 %d 次猜測： %d%d%d%d\t差距為： %d \n\n",times,guess[0],guess[1],guess[2],guess[3],downcost);
			if(downcost < best_cost) 
			{
				best_cost = downcost;
			}
			else
			{
				guess[guess_random]=y;
			}
		}
		else
		{
			if(count_random==0)
			{
				times++;
				x=guess[guess_random];
				guess[guess_random]=guess[guess_random]+1;
				upcost=abs(guess[0]-answer[0])+abs(guess[1]-answer[1])+abs(guess[2]-answer[2])+abs(guess[3]-answer[3]);
				printf("差距為： %d ,第 %d 位數 +1 後差距  %d  \n",best_cost,guess_random+1,upcost);
				printf("故第 %d 次猜測： %d%d%d%d\t差距為： %d \n\n",times,guess[0],guess[1],guess[2],guess[3],upcost);
				if(upcost < best_cost)
				{
					best_cost = upcost;
				}
				else
				{
					guess[guess_random]=x;
				}
			}
			else if(count_random ==1)
			{
				times++;
				y=guess[guess_random];
				guess[guess_random]=guess[guess_random]-1;
				downcost=abs(guess[0]-answer[0])+abs(guess[1]-answer[1])+abs(guess[2]-answer[2])+abs(guess[3]-answer[3]);
				printf("差距為： %d ,第 %d 位數 -1 後差距  %d  \n",best_cost,guess_random+1,downcost);
				printf("故第 %d 次猜測： %d%d%d%d\t差距為： %d \n\n",times,guess[0],guess[1],guess[2],guess[3],downcost);
				if(downcost < best_cost)
				{
					best_cost = downcost;
				}
				else
				{
					guess[guess_random]=y;
				}
			}
		}	
			
	}
	printf("---------------------------------------------------------------\n");
	printf("猜測結束,正解為：%d%d%d%d,共猜測：%d次",guess[0],guess[1],guess[2],guess[3],times);
}

int abs(int ans)
{
	if(ans<0)
		ans=-ans;
	return ans;
}
