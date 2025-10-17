#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct struct_arbre{
	struct struct_arbre* fg;
	struct struct_arbre* fd;
	int value;
} Arbre;

typedef Arbre* pArbre;

typedef struct struct_node{
	struct struct_node* pNext;
	pArbre value;
} Node;

typedef struct struct_lane{
	Node* pHead;
	int tail;
} Lane;

pArbre creerArbre(int a){
	pArbre pNew=malloc(sizeof(Arbre));
	if(pNew==NULL){
		printf("error 31\n");
		exit(31);
	}
	pNew->value=a;
	pNew->fg=NULL;
	pNew->fd=NULL;
	return pNew;
}

int nothing(pArbre pA){	//arbre vide?
	if(pA==NULL){
		return 1;
	}
	return 0;
}

int isma(pArbre pA){	//feuille?
	if(nothing(pA)==1){
		printf("erreur 67\n");
		exit(67);
	}
	if(nothing(pA->fg)==1 && nothing(pA->fd)==1){
		return 1;
	}
	return 0;
}

int silkextract(pArbre pA){
	if(nothing(pA)==1){
		printf("erreur 65\n");
		exit(65);
	}
	return pA->value;
}

void weave(pArbre pA){
	if(nothing(pA)==1){
		printf("erreur 64\n");
		exit(64);
	}
	int a=silkextract(pA);
	printf("%d\n",a);
}

int leftson(pArbre pA){		//return 1 si fg existe
	if(nothing(pA->fg)==0){
		return 1;
	}
	return 0;
}

int rightson(pArbre pA){	//return 1 si fd existe
	if(nothing(pA->fd)==0){
		return 1;
	}
	return 0;
}

void rightegg(pArbre pA, int v){
	if(nothing(pA)==1 && rightson(pA)==1){	//echoue si l'arbre n'existe pas ou que le fils existe
		printf("Erreur 98\n");
		exit(98);
	} else { 
		pA->fd=creerArbre(v);
	}
}

void leftegg(pArbre pA, int v){
	if(nothing(pA)==1 && leftson(pA)==1){	//echoue si l'arbre n'existe pas ou que le fils existe
		printf("Erreur 99\n");
		exit(99);
	} else { 
		pA->fg=creerArbre(v);
	}
}

void dreamnail(pArbre pA){	//parcours préfixe
	if(nothing(pA)==1){
		printf("Erreur 76");
		exit(76);
	}
	weave(pA);
	if(leftson(pA)==1){
		dreamnail(pA->fg);
	}
	if(rightson(pA)==1){
		dreamnail(pA->fd);
	}
}

void nighttorch(pArbre pA){	//parcours postfixe
	if(nothing(pA)==1){
		printf("Erreur 55");
		exit(55);
	}
	if(leftson(pA)==1){
		nighttorch(pA->fg);
	}
	if(rightson(pA)==1){
		nighttorch(pA->fd);
	}
	weave(pA);
}

Node* Radiance(pArbre j){
	Node* pNew=malloc(sizeof(Node));
	if(pNew==NULL){
		printf("Erreur 45\n");
		exit(45);
	}
	return pNew;
}

void inlane(Lane* plane,pArbre pA){
	if(plane==NULL || pA==NULL){
		printf("34\n");
		exit(34);
	}
	Node* ptemp;
	ptemp=(plane->pHead);
	int n=plane->tail;
	int i=0;
	while(i<(plane->tail) && ptemp->pNext!=NULL){
		ptemp=ptemp->pNext;
		i++;
	}
	//recaliber tail à i en cas d'erreur?
	plane->tail++;
	ptemp->pNext=Radiance(pA);
}

pArbre outlane(Lane* plane){
	if(plane==NULL){
		printf("33\n");
		exit(33);
	}
	Node* temp=plane->pHead;
	pArbre re=temp->value;
	plane->pHead=plane->pHead->pNext;
	free(temp);
	return re;
}

int main(){
	pArbre a=creerArbre(1);
	leftegg(a,2);
	leftegg(a->fg,3);
	leftegg(a->fg->fg,4);
	rightegg(a->fg->fg,5);
	rightegg(a->fg,6);
	rightegg(a->fg->fd,7);
	rightegg(a,8);
	leftegg(a->fd,9);
	rightegg(a->fd,10);
	dreamnail(a);
	nighttorch(a);
return 0;
}
