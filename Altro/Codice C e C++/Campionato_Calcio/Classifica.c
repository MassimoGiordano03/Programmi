/**
 * Classifica.c
 */

#include <stdio.h>
#include <string.h>

#define DIM 30
#define N 2

struct dati 
{
	char team[DIM];
	int pts;
	int goal;
};

int main()
{
	struct dati classifica[N];
	//FILE* fp;
	char test_team[DIM];
	int mod = 1;
	int i;
	int it;

	for(i = 0; i < N; i++) 
	{
		strcpy(classifica[i].team, "");
		classifica[i].pts = 0;
		classifica[i].goal = 0;
	}

	/*
	fp = fopen("Classifica.dat", "rb");
	for(i = 0; i < N; i++)
	{
		fread(&classifica, sizeof(classifica[i]), 1, fp);
	}
	fclose(fp);
	*/

	while(mod != 0) 
	{
		printf("Modalita: \n 1 per inserire le squadre;\n 2 per eliminarne una;\n 3 per aggiungere goal fatti e subiti;\n 4 per mostrare la classifica.\n");

		scanf("%d", &mod);

		/**
		 * Funzione di confronto tra le squadre inserite
		 */
		if(mod == 1) 
		{
			printf("Inserire lo spazio per la squadra, 1 o 2...\n");
			scanf("%d", &it);
			fflush(stdin); 
			printf("Che squadra vuoi aggiungere? ");
			gets(test_team);

			for(i = 0; i < N; i++) {
				while(strcmp(test_team, classifica[i].team) == 0) {

					printf("Squadra esistente! Inserire di nuovo... \n");
					gets(test_team);
				}
			}
			strcpy(classifica[it-1].team, test_team);
		}

		/**
		 * Cancellazione delle squadre
		 */
		if(mod == 2) 
		{
			printf("Quale squadra vuoi eliminare, %s o %s? \n", classifica[0].team, classifica[1].team);
			fflush(stdin);
			gets(test_team);

			for(i = 0; i < N; i++) 
			{
				if(strcmp(test_team, classifica[i].team) == 0) 
				{
					strcpy(classifica[i].team, "");
					classifica[i].pts = 0;
					classifica[i].goal = 0; 
				}
			}
		}

		/**
		 * Inserimento goal fatti e subiti da parte di una delle squadre
		 */
		if(mod == 3)
		{
			printf("Quale squadra ha segnato, %s o %s? \n", classifica[0].team, classifica[1].team);
			fflush(stdin);
			gets(test_team);

			for(i = 0; i < N; i++) 
			{
				if(strcmp(test_team, classifica[i].team) == 0) 
				{
					classifica[i].goal++;
				}
			}
		}

		/**
		 * Stampa risultato della partita
		 */
		if(mod == 4)
		{
			if(classifica[0].goal > classifica[1].goal)
			{
				printf("La partita è finita, ha vinto %s, assegnati 3 punti a %s!!\n\n", classifica[0].team, classifica[0].team);
			} 
			else if(classifica[0].goal < classifica[1].goal)
			{
				printf("La partita è finita, ha vinto %s, assegnati 3 punti a %s!!\n\n", classifica[1].team, classifica[1].team);
			}
			else if(classifica[0].goal == classifica[1].goal) 
			{
				printf("La partita è finita in pareggio. 1 punto a testa!!\n\n");
			}
			mod = 0;
		}
	}
	/*
	fp = fopen("Classifica.dat", "wb");

	for(i = 0; i < N; i++)
	{
		fwrite(&classifica, sizeof(classifica[i]), 1, fp);
	}
	fclose(fp);
	*/

	return 0;
}