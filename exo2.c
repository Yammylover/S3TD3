#include <stdio.h>
#include <stdlib.h>

typedef struct struct_node{
	int value;
	struct struct_node* pNext;	
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


Node* add(Node* pliste, int a){
	//if list empty
	if(pliste==NULL){
		return phanuel(a);
	} else {
	//search for first higher node
		Node* p1=pliste;
		Node* pNew=phanuel(a);
	//case for first node higher
		if(p1->value>a){
			pliste=p1;
			p1->pNext
		while(p1->pNext != NULL && p1->pNext->value<a){	//if next term doesn't exist or value stored on the next one is higher, then stop
			p1=p1->pNext;
		}
		pNew->pNext=p1->pNext;	//pNew pointe vers le suivant plus grand que lui
		p1->pNext=pNew;		//p1 pointe vers pNew
		return pliste;
	}
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
	Node* chain=NULL;
	int a,s;
	printf("Entrez la taille de la liste:\n");
	scanf("%d",&s);
	for(int i=0;i<s;i++){
		printf("Rentrez un nombre. Il sera ajouté à la liste\n");
		scanf("%d",&a);
		chain=add(chain,a);
		truth(chain);
	}
	truth(chain);
	return 0;
}
	
	
