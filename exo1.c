#include <stdio.h>
#include <stdlib.h>

typedef struct struct_node{
	struct struct_node* pprevious;
	struct struct_node* pnext;
	char mot[20];
} Node;

int comparemot(char* mot1, char* mot2){
	if(mot1==NULL || mot2==NULL){
		printf("Erreur 37\n");
		exit(37);
	}
	int i=0;
	while(mot1[i]!='\0' && mot2[i]!='\0'){	//vérifie pour la longueur de mot1, que mot1 est avant mot2, sinon retourne 0
		if(mot1[i]>mot2[i]){
			return 0;	//mot1 après, pour mot1 plus petit ou égal
		}
		i++;
	}
	if(mot1[i]!='\0' && mot2[i]=='\0'){	//si mot1 est plus grand que mot2 mais que mot 1 et mot2 sont égaux pour la longueur de mot2 retourne 0
		return 0;	//mot 1 plus grand et après
	}
	return 1;	//mot 1 avant 
}
void insertliste(char* mot, Node* pliste){
	if(mot==NULL || pliste==NULL){
		printf("Erreur 67\n");
		exit(67);
	}
	Node* pNew=malloc(sizeof(Node));
	if(pNew==NULL){
		printf("Erreur 68\n");
		exit(68);
	}
	strcpy(pNew->mot,mot);
	pNew->pnext=NULL;
	pNew->pprevious=p
}

int main(){

return 0;
}
