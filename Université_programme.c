#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
	float examen;
	float td;
	float Tp;
	float moy; }Note;


typedef struct{ 
char nome[20];       char prenom[20];
long int  Matricule;
Note   str;         Note  Ana;	       
Note   Algo;        Note  phi; 	
Note   Alg;         float ter;
float Moyyen_general;
float eng;       	float Moyen_s1;
float Tech;      float Moyen_s2;
Note  propa;	Note  outils;
int cred_s1;    int cred_gen;
int cred_s2; 	char Desicion[30];  }Etudiant;
	

	
//Couleur 	
	
	
void red(){
  printf("\033[1;31m");
}
	
	
void yellow(){
  printf("\033[1;33m");
}
	
	
void green(){
  printf("\033[0;32m");
}
	
void bleu(){
  printf("\033[0;34m");
}
		
	
	
	
void Purple(){
  printf(" \033[0;35m");
}
		
void reset(){
  printf("\033[0m");
}	
	
	
	
//Universco		
	
	
void Menu(){

printf("\n*************** | UNIVERSCO | *************");
printf("\n*                                         *");
printf("\n*   University of Saida Dr.Moulay TAHAR   *");
printf("\n*                                         *");
printf("\n*                                         *");	
	
printf("\n*     1)----> ESPACE ETUDIANT             *\n*");	

	Purple();
printf("    2)----> ESPACE ADMINISTRAT          ");	
reset();	
printf("*\n*                                         *");
printf("\n*                                         *");	
	
printf("\n***************************************"
       "****");
printf("\033[0m"); 
	}			
	

	
	
	
// main	
	
	
int main(void){

	
		
char choix;				
Menu();	
do{	
printf("\n\nSaisissez lespace[1-2] : ");			
scanf("%c",&choix);
}while(choix !='1' && choix !='2');			
	
if(choix=='1'){					
long int motpass,matrcule;	

ETIQ2:				
printf("\n\nMATRICUL : ");
scanf("%ld",&matrcule);
printf("\n\nMOT DE PASS : ");
scanf("%ld",&motpass);	
	printf("\n\n");
if(matrcule != motpass)
{
printf("\n\nIl n'y a aucun étudiant avec ce matricule !");
goto ETIQ2;
}	

char filename[20];
char u;
sprintf(filename,"%ld",matrcule);	
    FILE *f;
    
    if (f = fopen(filename, "r")) 
    {
    	
    while(!feof(f)){
    	
       fscanf(f,"%c",&u);
       	printf("%c",u);   
	        }
    }
    else
    {
printf("\n\nIl n'y a aucun étudiant avec ce matricule !");    
    goto ETIQ2;
    fclose(f);
    }
  
      }else
      {
      	

	
	
//Choix 2 ESPACE ADMINISTRAT
	
	
int NbEtud=1;
Etudiant Ta;
Ta.cred_s1=0;
Ta.cred_s2=0;
Ta.cred_gen=0;
float mb=0,t=0;
char FileName[45];	
		
ETIQ1:	
 
	printf("\n\nEtudiant %d ",NbEtud);
	printf("\n\n Nome: ");
	scanf("%s",Ta.nome);
 	
	printf("\n Prenome: ");
	scanf("%s",Ta.prenom);
	printf("\n Matricule: ");
	scanf("%ld",&Ta.Matricule);
 
sprintf(FileName,"%ld",Ta.Matricule);  
   
 		
FILE *f=fopen(FileName,"w"); 
 
if(f==NULL){printf("\n\nERROR\n\n");
	goto ETIQ1;}else{ 		
 		
 		
 		
//Notes S1 		
 		
	printf("\n\n==>> ENTREZ LES NOTES \n");
 			
	printf("\n\n# Analyse 1:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.Ana.td);
	printf("Examen: ");
	scanf("%f",&Ta.Ana.examen);
Ta.Ana.moy=(((Ta.Ana.examen*3)+(Ta.Ana.td*2))/5);
	printf("moyen: %.2f",Ta.Ana.moy);
	
	printf("\n\n# Algebre 1:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.Alg.td);
	printf("Examen: ");
	scanf("%f",&Ta.Alg.examen);
Ta.Alg.moy=(Ta.Alg.examen*3+Ta.Alg.td*2)/5;	
	printf("moyen: %.2f",Ta.Alg.moy);

	printf("\n\n# Algorithmique 1:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.Algo.td);
	printf("TP: ");
	scanf("%f",&Ta.Algo.Tp);
	printf("Examen: ");
	scanf("%f",&Ta.Algo.examen);
Ta.Algo.moy=((Ta.Algo.examen*3)+(Ta.Algo.td+Ta.Algo.Tp))/5;
	printf("moyen: %.2f",Ta.Algo.moy);

	
	
    printf("\n\n# Structure Machine 1:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.str.td);
	printf("Examen: ");
	scanf("%f",&Ta.str.examen);
Ta.str.moy=((Ta.str.examen*3)+(Ta.str.td*2))/5;	
    printf("moyen: %.2f",Ta.str.moy);

	
	printf("\n\n# Physique 1:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.phi.td);
	printf("Examen: ");
	scanf("%f",&Ta.phi.examen);
Ta.phi.moy=((Ta.phi.examen*3)+(Ta.phi.td*2))/5;	
	printf("moyen: %.2f",Ta.phi.moy);


	printf("\n\n# Terminology:  ");
	printf("\n\nExamen: ");
	scanf("%f",&Ta.ter);
	printf("moyen: %.2f",Ta.ter);

	
	printf("\n\n# English:  ");
	printf("\n\nExamen: ");
	scanf("%f",&Ta.eng);
	printf("moyen: %.2f",Ta.eng);
	
	
	
// Calcul cred s1
 			
if(Ta.Ana.moy>=10){Ta.cred_s1=6;}
if(Ta.Alg.moy>=10){Ta.cred_s1=Ta.cred_s1+5;}	

mb=((Ta.Alg.moy*3)+(Ta.Ana.moy*4))/7;
if(mb>=10){Ta.cred_s1=11;}
mb=0;	

if(Ta.Algo.moy>=10){t=6;}
if(Ta.str.moy>=10){ t=t+5;}
mb=((Ta.Algo.moy*4)+(Ta.str.moy*3))/7;
if(mb>=10){t=11;}
Ta.cred_s1=Ta.cred_s1+t;
mb=0;  t=0;	
		

if(Ta.phi.moy>=10){Ta.cred_s1=Ta.cred_s1+4;}	
		
if(Ta.ter>=10){t=2;}	
if(Ta.eng>=10){t=t+2;}
mb=(Ta.eng+Ta.ter)/2;	
if(mb>=10){t=4;}
Ta.cred_s1=Ta.cred_s1+t;	



//Calcul Moyyen S1

Ta.Moyen_s1=((Ta.Alg.moy*3)+(Ta.Algo.moy*4)+(Ta.Ana.moy*4)+Ta.eng+Ta.ter+(Ta.phi.moy*2)+(Ta.str.moy*3))/18;	
		
if(Ta.Moyen_s1>=10){Ta.cred_s1=30;}
	
printf("\n\n\n   MOYYEN S1: %.2f\n",Ta.Moyen_s1);
printf("\n   Créd: %d",Ta.cred_s1);
 	



//Ecrire dans le fichier s1

	
fprintf(f,"##############################################");
fprintf(f,"#\n#\n#    Relevé de notes : L1 - Socle commun MI");
fprintf(f,"\n#\n#     Nome: %s",Ta.nome);
fprintf(f,"\n#     Prenome: %s",Ta.prenom);
fprintf(f,"\n#     Spécialité: Math informatique");
fprintf(f,"\n#     Matricule: %ld",Ta.Matricule);
	
	
	
fprintf(f,"\n#\n#     S1: \n#\n#     1_Analyse 1:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.Ana.td,Ta.Ana.examen,Ta.Ana.moy);

fprintf(f,"\n#\n#     2_Algebre 1:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.Alg.td,Ta.Alg.examen,Ta.Alg.moy);

fprintf(f,"\n#\n#     3_Algorithme 1:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.Algo.td,Ta.Algo.examen,Ta.Algo.moy);
	
fprintf(f,"\n#\n#     4_Sructure Machine 1:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.str.td,Ta.str.examen,Ta.str.moy);
	
	
fprintf(f,"\n#\n#     5_Physique 1:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.phi.td,Ta.phi.examen,Ta.phi.moy);


fprintf(f,"\n#\n#     6_Terminology:\n#     Examen: %.2f\n#    moyyen: %.2f",Ta.ter,Ta.ter);
	
fprintf(f,"\n#\n#     7_English:\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.eng,Ta.eng);	

	
	
	
fprintf(f,"\n#\n#\n#                     MOYYEN S1 : %.2f\n#\n",Ta.Moyen_s1);
fprintf(f,"#         Créd s1: %d\n#\n#\n",Ta.cred_s1);
 

 
 
 mb=0,t=0;
	
 // Notes S2
 printf("\n\n\n\n S2");

	printf("\n\n==>> ENTREZ VOS NOTE \n");
	
	printf("\n\n# Analyse 2:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.Ana.td);
	printf("Examen: ");
	scanf("%f",&Ta.Ana.examen);
Ta.Ana.moy=(((Ta.Ana.examen*3)+(Ta.Ana.td*2))/5);
	printf("moyen: %.2f",Ta.Ana.moy);
	
	printf("\n\n# Algebre 2:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.Alg.td);
	printf("Examen: ");
	scanf("%f",&Ta.Alg.examen);
Ta.Alg.moy=(Ta.Alg.examen*3+Ta.Alg.td*2)/5;	
	printf("moyen: %.2f",Ta.Alg.moy);

	printf("\n\n# Algorithmique 2:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.Algo.td);
	printf("TP: ");
	scanf("%f",&Ta.Algo.Tp);
	printf("Examen: ");
	scanf("%f",&Ta.Algo.examen);
Ta.Algo.moy=((Ta.Algo.examen*3)+(Ta.Algo.td+Ta.Algo.Tp))/5;
	printf("moyen: %.2f",Ta.Algo.moy);

	
	
    printf("\n\n# Structure Machine 2:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.str.td);
	printf("Examen: ");
	scanf("%f",&Ta.str.examen);
Ta.str.moy=((Ta.str.examen*3)+(Ta.str.td*2))/5;	
    printf("moyen: %.2f",Ta.str.moy);

	
	printf("\n\n# Physique 2:  ");
	printf("\n\nTD: ");
	scanf("%f",&Ta.phi.td);
	printf("Examen: ");
	scanf("%f",&Ta.phi.examen);
Ta.phi.moy=((Ta.phi.examen*3)+(Ta.phi.td*2))/5;	
	printf("moyen: %.2f",Ta.phi.moy);


printf("\n\n# probalilités et statistique :  ");
 	printf("\n\nTD: ");
	scanf("%f",&Ta.propa.td);
	printf("Examen: ");
	scanf("%f",&Ta.propa.examen);
Ta.propa.moy=((Ta.propa.examen*3)+(Ta.propa.td*2))/5;
	printf("moyen: %.2f",Ta.propa.moy);

	
 
 printf("\n\n# Outils :  ");
 	printf("\n\nTD: ");
	scanf("%f",&Ta.outils.td);
	printf("Examen: ");
	scanf("%f",&Ta.outils.examen);
Ta.outils.moy=((Ta.outils.examen*3)+(Ta.outils.td*2))/5;
	printf("moyen: %.2f",Ta.outils.moy);

	
 
	printf("\n\n# Technologie :  ");
	printf("\nExamen: ");
	scanf("%f",&Ta.Tech);
	printf("\nmoyen: %.2f",Ta.Tech);
	
 
 
 
	
//calcul cred s2	
	
if(Ta.Ana.moy>=10){Ta.cred_s2=6;}
if(Ta.Alg.moy>=10){Ta.cred_s2=Ta.cred_s2+4;}	

mb=((Ta.Alg.moy*2)+(Ta.Ana.moy*4))/6;
if(mb>=10){Ta.cred_s2=10;}
mb=0;	

if(Ta.Algo.moy>=10){t=6;}
if(Ta.str.moy>=10){ t=t+4;}
mb=((Ta.Algo.moy*4)+(Ta.str.moy*2))/6;
if(mb>=10){t=10;}
Ta.cred_s2=Ta.cred_s2+t;
mb=0;  t=0;	
		

if(Ta.phi.moy>=10){Ta.cred_s2=Ta.cred_s2+3;}	
if(Ta.outils.moy>=10){Ta.cred_s2=Ta.cred_s2+2;}
if(Ta.propa.moy>=10){Ta.cred_s2=Ta.cred_s2+3;}	
if(Ta.Tech>=10){Ta.cred_s2=Ta.cred_s2+2;}	


// Cred Moyyen S2

Ta.Moyen_s2=((Ta.Alg.moy*2)+(Ta.Algo.moy*4)+(Ta.Ana.moy*4)+Ta.Tech+Ta.outils.moy+(Ta.propa.moy*2)+(Ta.str.moy*2)+(Ta.phi.moy*2))/18;	
		
if(Ta.Moyen_s2>=10){Ta.cred_s2=30;}
	
printf("\n\n\n   MOYYEN S2: %.2f\n",Ta.Moyen_s2);
printf("\n   Créd S2: %d",Ta.cred_s2);
 
 
//calcul Moyenne générale
 
Ta.Moyyen_general=(Ta.Moyen_s1+Ta.Moyen_s2)/2;
 
 
// Cred general

if(Ta.Moyyen_general>=10)
{
Ta.cred_gen=60;	
}else
{
	Ta.cred_gen=Ta.cred_s1+Ta.cred_s2;
}	




 
//DÉCISION
 
 if(Ta.cred_gen==60)
 {
 strcpy(Ta.Desicion,"Admis(e)");
 	green();
 }else if
(Ta.cred_gen>=30 && Ta.cred_s1!=0 && Ta.cred_s2!=0){ 
strcpy(Ta.Desicion,"Admis(e) avec dettes");
	yellow();}
 else
 {red();
 	strcpy(Ta.Desicion,"Ajourné(e)");
 }
	
	
	
	
	
	
printf("\n\n\n\n\n    MOYYEN GLE: %.2f\n",Ta.Moyyen_general);
	
printf("\n    Créd: %d",Ta.cred_gen);
	
	
printf("\n\n    DÉCISION : %s",Ta.Desicion);
	
	
	
// Ecrire dans le fichier s2
			
fprintf(f,"#\n#\n#     S2: \n#\n#     1_Analyse 2:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.Ana.td,Ta.Ana.examen,Ta.Ana.moy);

fprintf(f,"\n#\n#     2_Algebre 2:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.Alg.td,Ta.Alg.examen,Ta.Alg.moy);

fprintf(f,"\n#\n#     3_Algorithme 2:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.Algo.td,Ta.Algo.examen,Ta.Algo.moy);
	
fprintf(f,"\n#\n#     4_Sructure Machine 2:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.str.td,Ta.str.examen,Ta.str.moy);
	
	
fprintf(f,"\n#\n#     5_Physique 2:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.phi.td,Ta.phi.examen,Ta.phi.moy);

fprintf(f,"\n#\n#     6_probalilités et statistique:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.propa.td,Ta.propa.examen,Ta.propa.moy);
	
fprintf(f,"\n#\n#     7_Outils:\n#     TD: %.2f\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.outils.td,Ta.outils.examen,Ta.outils.moy);	
	
fprintf(f,"\n#\n#     8_Technology:\n#     Examen: %.2f\n#     moyyen: %.2f",Ta.eng,Ta.eng);	
	
	
fprintf(f,"\n#\n#\n#                     MOYYEN S2 : %.2f\n#\n",Ta.Moyen_s2);
fprintf(f,"#         Créd s2: %d\n#\n#\n",Ta.cred_s2);
 
 
 


fprintf(f,"#\n#\n#\n#\n#    MOYYEN GLE: %.2f\n#\n",Ta.Moyyen_general);
fprintf(f,"#    CRÉD: %d\n#\n#\n",Ta.cred_gen);
 
fprintf(f,"#    DÉCISION: %s\n#\n#\n",Ta.Desicion);
  

 
 
 fprintf(f,"##############################################");
fclose(f);
}

reset();
printf("\n\n\n");
printf("\n Entrez 1 -----------> pour saisir un nouveau Etudian.\n Entrez autre chose -> pour Quiter.\n\n ");



char choix2=getch();

if(choix2=='1')
{
	NbEtud++;
	system("cls");
	goto ETIQ1;

}


}






return 0;}

















