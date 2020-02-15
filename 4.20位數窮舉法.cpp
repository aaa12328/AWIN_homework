#include<stdio.h>

int abs(int ans);

int main (void)
{
	int num=20,num1=num-5,num2=num1-5,num3=num2-5;
	int guess[num] ={0},answer[num]={0},a,a1,a2,a3,b,times=0,ans=0,value=0,min=180;
	
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
	for(int i=0;i<10;i++)
	{
		for(int i1=0;i1<10;i1++)
		{
			for(int i2=0;i2<10;i2++)
			{
		 		for(int i3=0;i3<10;i3++)
				{
					for(int i4 =0;i4<10;i4++)
					{
						for(int i5=0;i5<10;i5++)
						{
							for(int i6=0;i6<10;i6++)
							{
								for(int i7=0;i7<10;i7++)
								{
									for(int i8=0;i8<10;i8++)
									{
										for(int i9=0;i9<10;i9++)
										{
											for(int i10=0;i10<10;i10++)
											{
												for(int i11=0;i11<10;i11++)
												{
													for(int i12=0;i12<10;i12++)
													{
														for(int i13=0;i13<10;i13++)
														{
															for(int i14=0;i14<10;i14++)
															{
																for(int i15=0;i15<10;i15++)
																{
																	for(int i16=0;i16<10;i16++)
																	{
																		for(int i17=0;i17<10;i17++)
																		{
																			for(int i18=0;i18<10;i18++)
																			{
																				for(int i19=0;i19<10;i19++)
																				{
																					value= abs(answer[0]-i)+abs(answer[1]-i1)+abs(answer[2]-i2)+abs(answer[3]-i3)+abs(answer[4]-i4)+abs(answer[5]-i5)+abs(answer[6]-i6)+abs(answer[7]-i7)+abs(answer[8]-i8)+abs(answer[9]-i9)+abs(answer[10]-i10)+abs(answer[11]-i11)+abs(answer[12]-i12)+abs(answer[13]-i13)+abs(answer[14]-i14)+abs(answer[15]-i15)+abs(answer[16]-i16)+abs(answer[17]-i17)+abs(answer[18]-i18)+abs(answer[19]-i19);
																					if(value<min)
																					{
																						min=value;
																					}
																					times++;
																					printf("猜測:%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",i,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19);
																					printf(",差距為：%d\n",min);
																					if(i19==answer[19])
																					{
																						break;
																					}
																				}
																				if(i18==answer[18])
																				{
																					break;
																				}															
																			}
																			if(i17==answer[17])
																			{
																				break;
																			}																		
																		}
																		if(i16==answer[16])
																		{
																			break;
																		}																	
																	}
																	if(i15==answer[15])
																	{
																		break;
																	}																
																}
																if(i14==answer[14])
																{
																	break;
																}															
															}
															if(i13==answer[13])
															{
																break;
															}														
														}					
														if(i12==answer[12])
														{							
															break;
														}								
													}
													if(i11==answer[11])
													{							
														break;
													}																
												}					
												if(i10==answer[10])
												{							
													break;
												}										
											}	
											if(i9==answer[9])
											{							
												break;
											}													
										}	
										if(i8==answer[8])
										{							
											break;
										}												
									}
									if(i7==answer[7])
									{							
										break;
									}
								}
								if(i6==answer[6])
								{							
									break;
								}
							}
							if(i5==answer[5])
							{							
								break;
							}
						}
						if(i4==answer[4])
						{							
							break;
						}
					}
					if(i3==answer[3])
					{							
						break;
					}
				}
				if(i2==answer[2])
				{							
					break;
				}
			}
			if(i1==answer[1])
			{							
				break;
			}
		}
		if(i==answer[0])
		{							
			break;	
		}
	}
	printf("共猜測： %d 次",times);
}

int abs(int ans)
{
	if(ans<0)
		ans=-ans;
	return ans;
}
