#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN

void Exit(int sig);
char* RandomPhrase(char* nome, char* copia_nome, int* last_num);

int main(){
	signal(SIGINT, Exit);
	printf("Ciao, sono l'EVAPORATORE D'ACQUA e sono qui per il tuo bene!\n");
	printf("Come ti chiami? ");
	fflush(NULL);
	char nome[25];
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\r\n")] = 0;
	printf("\nPerfetto %s, iniziamo! Non mi chiudere fino a che non andrai in un posto migliore :)\n", nome);
	printf("Se ti odi e vuoi morire disidratato, spegnimi premendo Ctrl+C\n");
	printf("\n");
	fflush(NULL);
	int last_num;
	char copia_nome[500];
	while (true){
		srand(time(NULL));
		char* frase=RandomPhrase(nome, copia_nome, &last_num);
		MessageBox(
			NULL,
			frase,
			"Evaporatore d'acqua dice:",
			MB_ICONINFORMATION | MB_SYSTEMMODAL
		);
		fflush(NULL);
		sleep(900);
	}
	return EXIT_SUCCESS;
}

void Exit(int sig){
	printf("\n\nMi sto spegnendo! Spero tu abbia evaporato abbastanza acqua oggi! BYE :)");
	exit(EXIT_SUCCESS);
}

char* RandomPhrase(char* nome, char* copia_nome, int* last_num){
	int num=rand()/((RAND_MAX+1u)/12);
	while (num > 12 || num == *last_num){
		num=rand()/((RAND_MAX+1u)/12);
	}
	*last_num=num;
	for (int i=0; i<strlen(nome); i++){
		copia_nome[i]=nome[i];
	}
	for (int j=strlen(nome); j<500; j++){
		copia_nome[j]='\0';
	}
	switch (num){
	case 0:
		return strcat(copia_nome, ", perch\xe9 la tua borraccia \xe9 ancora piena???\n");
		break;
	case 1:
		return strcat(copia_nome, ", bevi acqua!! \n");
		break;
	case 2:
		return "Il mare \xe9 grande, non sparir\xe0 se bevi un goccio! \n";
		break;
	case 3:
		return strcat(copia_nome, ", pleaseeeee DRINK!! \n");
		break;
	case 4:
		return strcat(copia_nome, ", non stai dimenticando qualcosa? GLUGLUGLUGLU!!!");
		break;
	case 5:
		return  "Puoi bere le immagini con i tuoi occhi...ma l'acqua solo con la tua bocca. Quindi fallo ORA!";
		break;
	case 6:
		return "Anche se a una mucca dai da bere del cacao non ne mungerai cioccolata. Ma non importa, bevi lo stesso";
		break;
	case 7:
		return "Naturalmente non bisogna bere molto, ma spesso. (Vino)";
		break;
	case 8:
		return strcat(copia_nome, ", what are you drinking? Tea........quila!!");
		break;
	case 9:
		return "Se succede qualcosa di brutto si beve per dimenticare. Se succede qualcosa di bello si beve per festeggiare. E se non succede niente? Si beve per far succedere qualcosa. Quindi bevi!!";
		break;
	case 10:
		return "Polvere sei e polvere tornerai, ma tra una polvere e l'altra un buon bicchiere non fa mai male.";
		break;
	case 11:
		return "Se la sete non \xe9 presente, bevo per la sete futura.";
		break;
	case 12:
		return "Puoi condurre un cavallo all'acqua ma non puoi obbligarlo a bere. Io per\xf2 posso obbligare te! :)";
		break;
	}
	return "";
}
