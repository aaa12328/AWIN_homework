#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int abs(int ans);


int main (void)
{
	int num=20,num1=num-5,num2=num1-5,num3=num2-5;
	int guess[num] ={0},answer[num]={0},a,a1,a2,a3,b,times=0,best_cost=0,bestcost=0,upcost=0,downcost=0,x,y;
	int P_L = 0;//以一定概率接受次數 
	int startT = 3000;//初始溫度
	
	double endT = 1e-8;//結束溫度
	
	double delta = 0.999;//溫度變化率
	
	int limit =  10000;;//概率選擇上限,表示已經接近最優解 
		
	printf("請輸入20位數正解第  1 -  %d 位數：",num3);
	
	scanf("%d",&a3);
	
	printf("請輸入20位數正解第  %d - %d 位數：",num3+1,num2);
	scanf("%d",&a2);
	
	printf("請輸入20位數正解第 %d - %d 位數：",num2+1,num1);
	scanf("%d",&a1);
		
	printf("請輸入20位數正解第 %d - %d 位數：",num1+1,num);
	scanf("%d",&a);
	
	for(int b=num-1 ; b>=0;b--)
	{
		answer[b]=a%10;
		a/=10;
	}
	for(int b=num-6 ; b>=0;b--)
	{
		answer[b]=a1%10;
		a1/=10;
	}
	for(int b=num-11 ; b>=0;b--)
	{
		answer[b]=a2%10;
		a2/=10;
	}
	for(int b=num-16 ; b>=0;b--)
	{
		answer[b]=a3%10;
		a3/=10;
	}

	int guess_random=0,count_random=0;
	srand( time(NULL) );

	for(int i=0;i<num;i++)
	{
		guess[i] = rand() % (9 - 0 + 1) + 0;
	}

	for(int j=0;j<num;j++)
	{
		bestcost=abs(guess[j]-answer[j]);
		best_cost=bestcost+best_cost;
	}	
	times++;
	
	printf("第一次猜測：");
	for(int e=0;e<num;e++)
		printf("%d",guess[e]);
	printf("差距為： %d\n",best_cost);
	
	int cost=0;
	while(startT > endT)
	{	
		if(best_cost == 0)
			break;
		guess_random=rand() % (num-1 - 0 + 1) + 0;
		count_random=rand() % (1 - 0 + 1) + 0;
	
		printf("上一次猜測為：");
		for(int e=0;e<num;e++)
			printf("%d",guess[e]);
		printf("\t");
		cost=0;
		if(guess[guess_random]==0)
		{
			times++;
			x=guess[guess_random];
			guess[guess_random]+=1;
			for (int q=0;q<num;q++)
			{
				bestcost=abs(guess[q]-answer[q]);
				cost=bestcost+cost;				
			} 
			upcost=cost;
			printf("差距為：%d ,第 %d 位數 +1 後差距：%d \n",best_cost,guess_random+1,upcost);
			if(upcost < best_cost)
			{
				best_cost = upcost;
			}
			else
			{
				double rd = rand() / (RAND_MAX + 1.0);
				if(exp(- cost / startT) > rd )
				{
					guess[guess_random]=x;
					
					P_L++; 
				} 
				if(P_L == limit)
					break;
		
				startT *= delta;
			}
		}
		else if(guess[guess_random]==9)
		{
			times++;
			y=guess[guess_random];
			guess[guess_random]=guess[guess_random]-1;
			for (int q=0;q<num;q++)
			{
				bestcost=abs(guess[q]-answer[q]);
				cost=bestcost+cost;				
			} 
			downcost=cost;
			printf("差距為：%d ,第 %d 位數 -1 後差距 ： %d \n",best_cost,guess_random+1,downcost);
			if(downcost < best_cost) 
			{
				best_cost = downcost;
			}
			else
			{
				double rd = rand() / (RAND_MAX + 1.0);
				if(exp(- cost / startT) > rd )
				{
					guess[guess_random]=y;
					
					P_L++;
				} 
				if(P_L == limit)
					break;
		
				startT *= delta;
			}
		}
		else
		{
			if(count_random==0)
			{
				times++;
				x=guess[guess_random];
				guess[guess_random]=guess[guess_random]+1;
				for (int q=0;q<num;q++)
				{
					bestcost=abs(guess[q]-answer[q]);
					cost=bestcost+cost;				
				} 
				upcost=cost;
				printf("差距為：%d ,第 %d 位數 +1 後差距  %d  \n",best_cost,guess_random+1,upcost);
				if(upcost < best_cost)
				{
					best_cost = upcost;
				}
				else
				{
					double rd = rand() / (RAND_MAX + 1.0);
				if(exp(- cost / startT) > rd )
				{
					guess[guess_random]=x;
					
					P_L++; 
				} 
				if(P_L == limit)
					break;
					
				startT *= delta;
				}
			}
			else if(count_random ==1)
			{
				times++;
				y=guess[guess_random];
				guess[guess_random]=guess[guess_random]-1;
				for (int q=0;q<num;q++)
				{
					bestcost=abs(guess[q]-answer[q]);
					cost=bestcost+cost;				
				} 
				downcost=cost;
				printf("差距為：%d ,第 %d 位數 -1 後差距  %d  \n",best_cost,guess_random+1,downcost);
				if(downcost < best_cost)
				{
					best_cost = downcost;
				}
				else
				{
				double rd = rand() / (RAND_MAX + 1.0);
				if(exp(- cost / startT) > rd )
				{
					guess[guess_random]=y;
					
					P_L++; 
				} 
				if(P_L == limit)
					break;
					
				startT *= delta;
				}
			}
		}	
		printf("故第 %d 次猜測：",times);	
		for(int e=0;e<num;e++)
			printf("%d",guess[e]);
		printf("\t差距為：%d \n\n",best_cost);
	}
	printf("-----------------------------------------------------------------------------\n");
	printf("猜測結束,正解為：");
	for(int e=0;e<num;e++)
		printf("%d",guess[e]);
	printf(",共猜了：%d次",times);
}

int abs(int ans)
{
	if(ans<0)
		ans=-ans;
	return ans;
}
