#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int abs(int ans);


int main (void)
{
	int num=20,num1=num-5,num2=num1-5,num3=num2-5;
	int guess[num] ={0},answer[num]={0},a,a1,a2,a3,b,times=0,best_cost=0,bestcost=0,upcost=0,downcost=0,x,y;
	int P_L = 0;//�H�@�w���v�������� 
	int startT = 3000;//��l�ū�
	
	double endT = 1e-8;//�����ū�
	
	double delta = 0.999;//�ū��ܤƲv
	
	int limit =  10000;;//���v��ܤW��,��ܤw�g������u�� 
		
	printf("�п�J20��ƥ��Ѳ�  1 -  %d ��ơG",num3);
	
	scanf("%d",&a3);
	
	printf("�п�J20��ƥ��Ѳ�  %d - %d ��ơG",num3+1,num2);
	scanf("%d",&a2);
	
	printf("�п�J20��ƥ��Ѳ� %d - %d ��ơG",num2+1,num1);
	scanf("%d",&a1);
		
	printf("�п�J20��ƥ��Ѳ� %d - %d ��ơG",num1+1,num);
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
	
	printf("�Ĥ@���q���G");
	for(int e=0;e<num;e++)
		printf("%d",guess[e]);
	printf("�t�Z���G %d\n",best_cost);
	
	int cost=0;
	while(startT > endT)
	{	
		if(best_cost == 0)
			break;
		guess_random=rand() % (num-1 - 0 + 1) + 0;
		count_random=rand() % (1 - 0 + 1) + 0;
	
		printf("�W�@���q�����G");
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
			printf("�t�Z���G%d ,�� %d ��� +1 ��t�Z�G%d \n",best_cost,guess_random+1,upcost);
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
			printf("�t�Z���G%d ,�� %d ��� -1 ��t�Z �G %d \n",best_cost,guess_random+1,downcost);
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
				printf("�t�Z���G%d ,�� %d ��� +1 ��t�Z  %d  \n",best_cost,guess_random+1,upcost);
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
				printf("�t�Z���G%d ,�� %d ��� -1 ��t�Z  %d  \n",best_cost,guess_random+1,downcost);
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
		printf("�G�� %d ���q���G",times);	
		for(int e=0;e<num;e++)
			printf("%d",guess[e]);
		printf("\t�t�Z���G%d \n\n",best_cost);
	}
	printf("-----------------------------------------------------------------------------\n");
	printf("�q������,���Ѭ��G");
	for(int e=0;e<num;e++)
		printf("%d",guess[e]);
	printf(",�@�q�F�G%d��",times);
}

int abs(int ans)
{
	if(ans<0)
		ans=-ans;
	return ans;
}
