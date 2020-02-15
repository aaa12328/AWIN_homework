/*******************************************************************/
/*                                                                 */
/*     filename : GaMain.c                                         */
/*     author   : edison.shih/edisonx                              */
/*     compiler : Visual C++ 2008                                  */
/*     date     : 2010.02.14                                       */
/*     maintain : 2011.11.21                                       */
/*     maintain : 2012.06.15                                       */
/*                                                                 */
/*         A.L.L.      R.I.G.H.T.S.     R.E.S.E.R.V.E.             */
/*                                                                 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "GA.h"

int main(int argc, char **argv)
{
     int i,j,loop=0;
     double a0,a1,a2,a3,a4;
	double a[5]={0};
     srand((unsigned)time(NULL));
	 for(loop=0;loop<5;loop++)
	 {
	 	initialize();            // 初始化
     	for(i=0; i<ITERA_CNT; i++){
        	 reproduction();      // 選擇(分配式)
        	 //  reproduction_rnd();  // 選擇(隨機式), 收斂速度慢
         	crossover();         // 交配
       	  mutation();          // 突變f
     	}
     a[loop]=best_gene.dec_value;
     timess();
	 }

     printf("\n =========================\n");
     printf(" %3d times..\n", i);
     for(j=0; j<POPULATION_CNT; j++){
         printf("(%.0f, %.0lf) \n", population[j].dec_value, population[j].fitness);
     //    if(j%4==3) printf("\n");
     }
     printf("\n =========================\n");
     printf(" ever find best gene : ");
     printf("(%.0lf, %.0lf, %.0lf, %.0lf, %.0lf)\n", a[0],a[1],a[2],a[3],a[4]);
     getchar();
     return 0;
}
