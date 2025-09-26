#include <stdio.h>
#include <stdlib.h>

typedef struct struct_node{
	int value;
	struct struct_node* pNext;	//important de préciser struc devant le nom temporaire
} Node;

Node* phanuel(int a){
	Node* pNew;
	pNew=malloc(sizeof(Node));
	if(pNew==NULL){
		printf("Pas de mémoire dispo");
		exit(3);
	}
	pNew->value=a;
	pNew->pNext=NULL;
	return pNew;
}

Node* begin_add(Node* pliste, int a){
	Node* pNew;
	pNew=phanuel(a);
	pNew->pNext=pliste;
	return pNew; //return pNew permet de ne pas modifier pliste plise=pNew
}

Node* end_add(Node* pliste, int a){
	//if list empty
	if(pliste==NULL){
		return phanuel(a);
	} else {
		Node* pNew=phanuel(a);
	//search for last node
		Node* p1=pliste;
		
		while(p1->pNext != NULL){
			p1= p1->pNext;	//pointer becomes pointer to next node
		}
		p1->pNext=pNew;
		return pliste;
	}
}

void rotting(Node* pliste){	//fonction qui efface les pointeurs d'une chaîne
	Node* p1=malloc(sizeof(Node));
	p1=pliste;
	do{
			free(p1);
			printf("space for %d has been freed\n",p1->value);
			p1= p1->pNext;	//pointer becomes pointer to next node
	}while(p1->pNext != NULL);
}

void truth(Node* pliste){
	//printf("checkpoint2\n");
	if(pliste==NULL){
		printf("no list \n");
		exit(62);
	}
	Node* temp=pliste;
	while(temp!=NULL){
		printf("%d",temp->value);
		temp=temp->pNext;
		if(temp!=NULL){
			printf("->");
		}
	}
	printf("\n");
}

int main(){
	/*Node* chain;
	int a=1;
	printf("Entrez un nombre:\n");
	scanf("%d",&a);
	chain=phanuel(a);
	printf("Entrez un nombre:\n");
	scanf("%d",&a);
	chain=begin_add(chain,a);
	printf("Entrez un nombre:\n");
	scanf("%d",&a);
	chain=end_add(chain,a);
	printf("checkpoint1\n");
	truth(chain);
	free(chain);*/
	Node* chain=NULL;
	int a=0, carey=2;
	char l='O';
	printf("Enter size of list:\n");
	scanf("%d",&a);
	chain=phanuel(carey);
	for(int i=1; i<=a;i++){
		carey*=2;
		end_add(chain,carey);
	}
	truth(chain);
	while(l!='N'){
		printf("Do you wish to see the next power of 2? (Y/N)\n");
		do{
			scanf("%c",&l);
			if((scanf("%c",&l))!=1 || (l!='Y' && l!='N')){
				printf("Command not recognized. Please try again.\n");
			}
		}while(l!='Y' && l!='N');
			if(l=='Y'){
				carey*=2;
				end_add(chain,carey);
				truth(chain);
			}
		}
		
	rotting(chain);
return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
