#include<stdio.h>

int abs(int ans);

int main (void)
{
	int answer[4]={0},a=0,ans=0,times=0,value=0,min=99;
	
	printf("�п�J���ѡG");
	scanf("%d",&a);
	for(int b=3 ; b>=0;b--)
	{
		answer[b]=a%10;
		a/=10;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
	 		for(int k=0;k<10;k++)
			{
				for(int l =0;l<10;l++)
				{
					value= abs(answer[0]-i)+abs(answer[1]-j)+abs(answer[2]-k)+abs(answer[3]-l);
					if(value<min)
					{
						min=value;
					}
					times++;
					printf("�q�� : %d%d%d%d , �ثe�̤p�t�Z�� %d \n",i,j,k,l,min); 
					if(l==answer[3])
					{
						ans=l;
						break;					
					}
				}
				if(k==answer[2])
				{
					ans=k*10+ans;
					break;
				}	
			}
			if(j==answer[1])
			{
				ans=j*100+ans;
				break;
			}
		}
		if(i==answer[0])
		{
			ans=i*1000+ans;
			break;
		}
	}
	printf("���׬��G%d ,�@�q���G %d ��",ans,times);
}

int abs(int ans)
{
	if(ans<0)
		ans=-ans;
	return ans;
}
