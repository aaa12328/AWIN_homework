#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define GENETIC_LENGTH     14                    // ��]����
#define POPULATION_CNT     30000                 // ���s�ƶq
#define ITERA_CNT          100                   // ���N����
#define CROSSOVER_RATE     0.5                   // ��t�v
#define MUTATION_RATE      0.1                   // ���ܲv

int times=1;
int ans [4]={0};
int ans1[4]={0};
int ans2[4]={0};
int ans3[4]={0};
int ans4[4]={0};


// =====================================================
// �w�q���鵲�c
typedef struct tag_parent_t{
     int genes[GENETIC_LENGTH];
     double fitness;
     double dec_value;
}parent_t;

// GAPosRand(): �H�����o���ܦ�m
#define GAPosRand()            (rand()%GENETIC_LENGTH)
// BinaryRand(): �H������/1 ���
#define BinaryRand()           (rand()%2)
// SRand(): �H������~1 ���ü�
#define SRand()                ((double)rand()/(double)RAND_MAX)
// =====================================================

void timess();
// �i���l��
void initialize();          
// �ƻs, ���L�����(���t��), �M�w�C�ӥ���ƻs���t�����Ӽ�
void reproduction();    
// �ƻs, ���L�����(�H����)
void reproduction_rnd();  
// ��t, ��t����������i���t, [���I��t, ���I��t, mask]
void crossover();          
// ����, �v�@bit �C�C�T�{����
void mutation();
// �p���]�ҹ������A����
void cal_fitness(parent_t *x);    
// �p���]�������i���
void cal_xvalue(parent_t *x);    

// =====================================================

parent_t population[POPULATION_CNT];      // ����ƶq
parent_t pool[POPULATION_CNT];            // ��t��
parent_t best_gene;                       // �q�H�e��{�b�̦n����]


int main(int argc, char **argv)
{
     int i,j,loop=0;
     double a0,a1,a2,a3,a4;
   	 double a[5]={0};
     srand((unsigned)time(NULL));
     int c,c1,c2,c3,c4;
     printf("�п�J���Ѳ� 1 - 4  ��ơG");
     scanf("%d",&c);
     printf("�п�J���Ѳ� 5 - 8  ��ơG");
     scanf("%d",&c1);
     printf("�п�J���Ѳ� 9 - 12 ��ơG");
     scanf("%d",&c2);
     printf("�п�J���Ѳ� 13- 14 ��ơG");
     scanf("%d",&c3);
     printf("�п�J���Ѳ� 11- 16 ��ơG");
     scanf("%d",&c4);
     printf("�еy��..."); 
	 for(int w=3;w>=0;w--)
	 {
	 	ans[w]=c%10;
	 	c/=10;
	 }
	 for(int w=3;w>=0;w--)
	 {
	 	ans1[w]=c1%10;
	 	c1/=10;
	 }
	 for(int w=3;w>=0;w--)
	 {
	 	ans2[w]=c2%10;
	 	c2/=10;
	 }
	 for(int w=3;w>=0;w--)
	 {
	 	ans3[w]=c3%10;
	 	c3/=10;
	 }
	 for(int w=3;w>=0;w--)
	 {
	 	ans4[w]=c4%10;
	 	c4/=10;
	 }
	 
	 for(loop=0;loop<5;loop++)
	 {
	 	initialize();            // ��l��
     	for(i=0; i<ITERA_CNT; i++){
        	 reproduction();      // ���(���t��)
        	 //  reproduction_rnd();  // ���(�H����), ���ĳt�׺C
         	crossover();         // ��t
       	    mutation();          // ����f
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
     printf("(%04.0f, %04.0lf, %04.0lf, %04.0lf, %04.0lf)\n", a[0],a[1],a[2],a[3],a[4]);
     getchar();
     return 0;
}

void timess()
{
	times++;
}
// =====================================================
// binary 2 dec�A�N�V���餤���G�i��(genes) �A�ର��ڥi�Τ��Q�i��(dec_value)
void cal_xvalue(parent_t *x)
{
     int i, dec=0;
     for(i=0; i<GENETIC_LENGTH; i++){
         if(x->genes[i] ==1) dec = dec + (0x01 << i);
		if(dec>9999)
			dec=0;
     }
     x->dec_value = (double)dec;
}

// =====================================================
// �A���禡�Ax ���V���餤���Q�i��A�Ydec_value
void cal_fitness(parent_t *x)
{   

     int i = x->dec_value;
     int g[4]={0};
     g[0]=i/1000;
     g[1]=i/100%10;
     g[2]=i/10%10;
     g[3]=i%10;
    if(times==1)
	 x->fitness =abs(g[3]-ans[3])+abs(g[2]-ans[2])+abs(g[1]-ans[1])+abs(g[0]-ans[0]);
	else if(times==2)
	 x->fitness =abs(g[3]-ans1[3])+abs(g[2]-ans1[2])+abs(g[1]-ans1[1])+abs(g[0]-ans1[0]);
    else if(times==3)
	 x->fitness =abs(g[3]-ans2[3])+abs(g[2]-ans2[2])+abs(g[1]-ans2[1])+abs(g[0]-ans2[0]);
    else if(times==4)
	 x->fitness =abs(g[3]-ans3[3])+abs(g[2]-ans3[2])+abs(g[1]-ans3[1])+abs(g[0]-ans3[0]);
    else if(times==5)
	 x->fitness =abs(g[3]-ans4[3])+abs(g[2]-ans4[2])+abs(g[1]-ans4[1])+abs(g[0]-ans4[0]);
    
}

// =====================================================
// ��l��,
void initialize()
{

     int i, j;
     for(i=0; i<POPULATION_CNT; i++){
         for(j=0; j<GENETIC_LENGTH; j++){
              // �C�ӥ��骺��]���O�H����/1
              population[i].genes[j] = BinaryRand();
         }
         // �p������]���i���
         cal_xvalue(&population[i]);
         // �p�����������A����
         cal_fitness(&population[i]);

         // ��sbest_gene
         if(i==0) {
              memcpy(&best_gene,
                  &population[i],
                  sizeof(parent_t));
         } else if (population[i].fitness < best_gene.fitness){
              memcpy(&best_gene,
                  &population[i],
                  sizeof(parent_t));
         }
     }
}
// =====================================================
// �ƻs, ���L�����(���t��)
void reproduction()
{
     int i, j, cnt, has_copy=0;
     int Slack = POPULATION_CNT; // �ٳѴX�ӥi�ƨ�
     int pos1, pos2;
     double fitness_sum=0.0;

     // �p��Ҧ��A�����`�X
     for(i=0; i<POPULATION_CNT; i++) {
         fitness_sum += population[i].fitness;
     }

     // �p��C�ӥ������ƻs�X�Ө��t�����A�ê������ƻs
     for(i=0; i<POPULATION_CNT && Slack!=0; i++) {
         // �p�����ƻs�Ӽ�, �|�ˤ��J
         cnt = (int)(population[i].fitness/fitness_sum * POPULATION_CNT + 0.5);
         // �վ�i�ƻs�Ӽ�
         if(cnt > Slack) cnt=Slack;
         // �}�l�i��ƻs
         for(j=0; j<cnt; ++j, ++has_copy)
              memcpy(&pool[has_copy],
              &population[i],
              sizeof(parent_t));
         // �վ�Slack
         Slack-=cnt;
     }
     // �Y�٦��S�ƻs����
     while(has_copy < POPULATION_CNT){
         // �H���D�G�����P�V����X��
         pos1 = rand() % POPULATION_CNT;
         do{pos2=rand()%POPULATION_CNT;}while(pos1==pos2);
         // ����n����������t���h
         if(population[pos1].fitness > population[pos2].fitness) i = pos1;
         else i=pos2;
         memcpy(&pool[has_copy++],&population[i],sizeof(parent_t));
     }
}

// =====================================================
// �ƻs, ���L�����(�H����)
void reproduction_rnd()
{
     int i, pos;
     double fitness_sum=0.0; // �A�����`�X
     double column_prob[POPULATION_CNT];// �֭p���v
     double prob; // ?�����v

     // �p��Ҧ��A�����`�X
     for(i=0; i<POPULATION_CNT; i++) {
         fitness_sum += population[i].fitness;
     }
     // �p��֭p���v�֭p���t
     column_prob[0] = population[0].fitness / fitness_sum;
     for(i=1; i<POPULATION_CNT; ++i){
         column_prob[i] =
              column_prob[i-1] + population[i].fitness / fitness_sum;
     }

     // �}�l�H����POPULATION_CNT �ӬV������t��
     for(i=0; i<POPULATION_CNT; ++i){
         // ���Ͷü�
         prob=SRand();
         // ���o������@�϶�
         for(pos=0; pos < POPULATION_CNT-1; ++pos){
              if(prob <= column_prob[pos] )
                  break;
         }
         // �ܦ��Apos ���� [0, POPULATION_CNT-1]


         // �ƻs
         memcpy(&pool[i], &population[pos], sizeof(parent_t));
     }
}

// =====================================================
// ��t
//!< attention : �o�̥u�Ҽ{����ӼƬ����ƭ�,
//!< �Y����ӼƬ��_�ƭӻݦA���B�~�P�_�B�z,�_�h�o�ͰO����g�J���~�C

void crossover()
{
     int i, cnt=0;
     int pos=0;
     int p1, p2;
     double crossover_if;

     while(cnt < POPULATION_CNT) { //!< correct 2012.06.15
         // �H����G�ӭ���
         p1 = rand() % POPULATION_CNT;    
         do{p2=rand()% POPULATION_CNT;}while(p2==p1);

         crossover_if = SRand();// �M�w�O�_��t
         if(crossover_if > CROSSOVER_RATE) {
              // ����t, �N��t�����������^����
              memcpy( (void *)&population[cnt++],
                  (void *)&pool[p1],
                  sizeof(parent_t));
              memcpy( (void *)&population[cnt++],
                  (void *)&pool[p2],
                  sizeof(parent_t));
         }
         else {
              // ���I��t, ��t����A��^����
              do{ pos = GAPosRand();} while(pos==0);                
              // crossover
              for(i=0; i<pos; i++){
                  population[cnt].genes[i] = pool[p1].genes[i];
                  population[cnt+1].genes[i] = pool[p2].genes[i];
              }
              for(i=pos; i<GENETIC_LENGTH; i++) {
                  population[cnt+1].genes[i] = pool[p1].genes[i];
                  population[cnt].genes[i] = pool[p2].genes[i];
              }
              cnt+=2; // �w�ƨ�G��
         }          
     }
}
// =====================================================
// ����
void mutation()
{
     int i;
     int pos;
     for(i=0; i<POPULATION_CNT; i++){
         double mutation_if = SRand();
         if(mutation_if <= MUTATION_RATE){
              pos = GAPosRand();      // ���ܦ�m
              population[i].genes[pos] =
                  1 - population[i].genes[pos];
         }
         // ���ܧ���A��@������A����
         cal_xvalue(&population[i]);  // �����]�������i��x ��
         cal_fitness(&population[i]); // �A�N�i��x �ȥN�J�A���禡
         // �A��sbest_gene
         if (population[i].fitness < best_gene.fitness){
              memcpy(&best_gene,
                  &population[i],
                  sizeof(parent_t));
         }
     }
}

int abs(int ans)
{
	if(ans<0)
		ans=-ans;
	return ans;
}
// =====================================================

