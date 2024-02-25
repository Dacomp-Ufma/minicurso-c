#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////questão 1.2
//void palindromo(char v[]){
//	
//	int i,j=strlen(v), c=0;
//	for (i=0;i<strlen(v);i++){
//		j--;
//		if(v[i]!=v[j]){
//			c++;
//			break;
//		}
//	}
//	if (c==0){
//		return printf("é palindromo");
//	}
//	else{
//		return printf("n é palindromo");
//	}
//}




////questão 1.3
//void inverso(char nome[]){
//	char *ptraux;
//	ptraux = (char*) malloc(strlen(nome)*sizeof(char));
//	int i, j=strlen(nome);
//	
//	for(i=0;i<strlen(nome);i++){
//		j--;
//		ptraux[i] = nome[j];
//	}
//	
//	for(i=0;i<strlen(nome);i++){
//		printf("%c", ptraux[i]);
//	}
//	
//	free(ptraux);
//}




////questão 1.5
//void rembranco(char nome[]){
//int i, aux;
//
//for (i=0;i<strlen(nome);i++){
//	if(nome[i]==' ' && nome[i+1]!=' '){
//		aux = nome[i];
//		nome[i] = nome[i+1];
//		nome[i+1] = aux;
//		i = i-2;
//	}
//}
//
//printf("%s", nome);
//}




////questao 1.6
//void remrep(char nome[]){
//	int i,j,aux;
//for(i=0;i<strlen(nome);i++){
//	//manter os espaços
//	if(nome[i]==' '){
//		continue;
//	}
//	for(j=0;j<strlen(nome);j++){
//		if(nome[i]==nome[j] && i!=j){
//			nome[j] = '~';
//		}
//	}
//}
//
//for(i=0;i<strlen(nome);i++){
//	
//	if(nome[i]=='~' && nome[i+1]!='~'){
//		aux = nome[i];
//		nome[i] = nome[i+1];
//		nome[i+1] = aux;
//		i = i-2;
//	}
//}
//
//printf("%s", nome);
//}




////questão 1.8
//void romanos(char nome[]){
//	int soma[strlen(nome)];
//
//int i;
//for(i=0;i<strlen(nome);i++){
//	if(nome[i]=='I'){soma[i] = 1;}
//	
//	if(nome[i]=='V'){soma[i] = 5;}
//	
//	if(nome[i]=='X'){soma[i] = 10;}
//	
//	if(nome[i]=='L'){soma[i] = 50;}
//	
//	if(nome[i]=='C'){soma[i] = 100;}
//	
//	if(nome[i]=='D'){soma[i] = 500;}
//	
//	if(nome[i]=='M'){soma[i] = 1000;}
//}
//
//
//for(i=0;i<strlen(nome);i++){
//	if(soma[i]<soma[i+1] && soma[i]!=0){
//		soma[i] = soma[i+1]-soma[i];
//		soma[i+1] = 0;
//	}
//}
//
//int total = 0;
//for(i=0;i<strlen(nome);i++){
//	total = soma[i]+total;
//}
//
//printf("%d", total);
//}



////questao 1.9
//int iguais(char s[], char p[]){
//    if (strlen(s)>strlen(p)){
//    printf("falso");
//    return 0;
//  }
//
//  
//    
//  int i;
//  for (i=0;i<strlen(s);i++){
//    if(s[i]==p[i]){
//      continue;
//    }
//
//    if(p[i] == '.'){
//      p[i] = s[i];
//    }
//
//    if(p[i] == '*'){
//      p[i] = p[i-1]+(s[i]-p[i-1]);
//    }
//
//  }
//
//  if(strcmp(p,s)==0){
//    printf("verdadeiro");
//    return 0;
//  }
//
//  printf("falso");
//}



////questão 2.1
//int crianca(int *g,int tamg,int *s, int tams){
//  
//g = (int*)malloc(tamg*sizeof(int));
//s = (int*)malloc(tams*sizeof(int));  
//
//int i,j;
//for(i=0;i<tamg;i++){
//  printf("quanto a criança [%d] deseja?", i+1);
//  scanf("%d", &g[i]); 
//}
//
//for(i=0;i<tams;i++){
//  printf("insira um valor para o biscoito[%d]", i+1);
//  scanf("%d", &s[i]);
//}
//
//int contador=0;
//  
//for(i=0;i<tamg;i++){
//  if(g[i]==0){
//    contador++;
//    continue;
//  }
//  for(j=0;j<tams;j++){
//    if(g[i]<=s[j]){
//      contador++;
//      s[j]=0;
//      break;
//    }
//  }
//  
//}
//
// return printf("%d", contador);
// }
//
//int main(){
//int *g;
//int *s;
//crianca(g,3,s, 3);
//free(g);
//free(s);
//}



////questão 2.2
//char naorepetidos(char nome[]){
//	char *nomeptr = NULL;
//	
//	nomeptr = &nome[0];
//	int i,j, contador = 0;
//	for(i=0;i<strlen(nome);i++){
//		
//		for(j=0;j<strlen(nome);j++){
//			if(nomeptr[i] == nomeptr[j] && i!=j){
//				contador++;
//			}
//		}
//		
//		if (contador ==0){
//			return printf("%c", nomeptr[i]);
//		}
//		
//		contador=0;	
//	}
//	
//	printf("nenhum!");
//	
//	free(nomeptr);
//
//}



////questao 2.3
//void invertido(char nome[]){
//	char *nomeptr = NULL;
//	nomeptr = &nome[0];
//	int i;
//	for (i=(strlen(nome)-1);i>=0;i--){
//		printf("%c", nomeptr[i]);
//	}
//}



////questao 2.4
//void maior(int num[], int numsize){
//  
//	int *ptrnum = NULL;
//	ptrnum = &num[0];
//	
//	int *maior;
//	maior = (int*) malloc(sizeof(int));
//	maior[0] = ptrnum[0];
//	
//	int i;
//	for(i=0;i<numsize;i++){
//		if(ptrnum[i]>=maior[0]){
//			maior[0] = ptrnum[i];
//		}	
//	}
//	
//	printf("%d", maior[0]);
//}



////questao 2.5
//void trocarvalores(int a, int b){
//	printf("valor de a=%d, valor de b=%d", a, b);
//	int *aptr = NULL;
//	aptr = &a;
//	int *bptr = NULL;
//	bptr = &b;
//	int *store;
//	store = (int*) malloc(sizeof(int));
//	*store = *aptr;
//	*aptr = *bptr;
//	*bptr = *store;
//	printf("\nvalor de a=%d, valor de b=%d", a, b);
//	free(aptr);
//	free(bptr);
//	free(store);
//}



////questao 2.6
//void alfabeto(){
//	char *alfa;
//alfa = (char*)malloc(sizeof(char));
//*alfa = 'a';
//
//while((*alfa) <= 'z' ){
//	printf("%c", *alfa);
//	*alfa = *alfa+1;
//}
//
//free(alfa);
//}



////questao 2.7
//int main(){
//int *array;
//array = (int*) malloc(sizeof(int));
//
//int num;
//int indice =0;
//int tam = 1;
//int loop = 0;
//while(loop==0){
//	
//	scanf("%d", &num);
//  
//	
//	if (num!=0){
//    array[indice] = num;
//    tam++;
//		array = (int*) realloc(array, (tam*sizeof(int)));
//    indice++;
//	}
//	
//	if (num==0){
//		break;
//	}
//  
//}
//
//int i;
//for(i=0;i<tam-1;i++){
//  printf("%d",array[i]);
//}
//  
//}



////questao 2.8
//int main(){
//  //criando carrinho(que será uma matriz/ponteiro de ponteiro)
//  char **carrinho;
//  carrinho = (char**) malloc(sizeof(char*));
//  char produto[100];
//
//  //tamanho, indice, entrada
//  int tam = 1;
//  int entrada;
//  int indice = 0;
//  int i;
//  
//  //criando o loop
//  int loop = 0;
//  while (loop==0){
//  	printf("\n\nDeseja adicionar algum produto no carrinho? \n 1=Sim 2=Nao: ");
//  	scanf("%d", &entrada);//verificando entrada
//
//      if (entrada==1){
//      	
//        indice++;
//        tam++;
//        carrinho = (char**) realloc(carrinho, tam*(sizeof(char*)));
//        
//        printf("qual o produto? ");
//      	scanf("%s", produto);//adicionando um valor para o vetor "produto"
//        carrinho[indice] = malloc(100*sizeof(char));//adicionando produto no carrinho(linha da matriz)
//        strcpy(carrinho[indice],produto);
//    	}
//    
//    	if(entrada ==2){
//        break;
//    	}
//	
//  }
//
//for(i=0;i<tam;i++){
//	printf("\n %s", carrinho[i]);
//}
//free(carrinho);
//
//	
//}



////questão 2.8
//
//void add_produto(char **carrinho, int indice, int tam, int tamstring){
//		carrinho[indice] = (char*) malloc(sizeof(char)*tamstring);
//		scanf("%s", carrinho[indice]);
//		tam++;
//		carrinho = (char**) realloc(carrinho,sizeof(char*)*tam);
//		
//}
//
//int main(){
//	int entrada;
//	int tam=0;
//	int indice=0;
//	int tamstring = 20;
//	int loop = 0;
//	int i,j;
//	
//	char **carrinho=NULL;
//	carrinho = (char**) malloc(sizeof(char*));
//	
//	char produto[20];
//	
//	while (loop==0){
//	printf("\n\n\n1");
//	printf("\n2");
//	printf("\n3\n");
//	scanf("%d", &entrada);
//	
//	if(entrada==1){
//		tam++;
//		add_produto(carrinho, indice, tam, tamstring);
//		indice++;
//		printf("tamanho do carrinho: %d", tam);
//	
//	}
//	
//	if(entrada==2){
//		scanf("%s", produto);
//		for(i=0;i<tam-1;i++){
//
//			if(strcmp(produto,carrinho[i])==0){
//				printf("%s", carrinho[i]);
//				strcpy(carrinho[i], carrinho[tam-1]);
//				tam--;
//				carrinho = (char**) realloc(carrinho, sizeof(char*)*tam);
//				indice--;
//			
//			}
//		}
//	}
//	
//	if(entrada==3){
//		break;
//	}
//	
//}
//
//for(i=0;i<tam;i++){
//	printf("%s\n", carrinho[i]);
//}
//	return 0;
//}



////questao 3.1
//typedef struct{
//	int ID;
//	char sexo[20];
//	float teste1;
//	float teste2;
//	float resultado;
//}aluno;
//
//void addaluno(aluno estudantes[], int totalaluno){
//	int i,j,contador=0;
//  
//	for(i=0;i<totalaluno;i++){
//	printf("ID: ");
//	scanf("%d", &estudantes[i].ID);
//	printf("SEXO(MASC / FEM / N BINARIO): ");
//	scanf("%s", estudantes[i].sexo);
//	printf("TESTE1: ");
//	scanf("%f", &estudantes[i].teste1);
//	printf("TESTE2: ");
//	scanf("%f", &estudantes[i].teste2);
//	estudantes[i].resultado = (estudantes[i].teste1+estudantes[i].teste2)/2;
//	printf("\n \n \n");
//	}
//  
//}
//
//void addalunodepois(aluno estudantes[], int totalaluno){
//	int i,j,contador=0;
//  
//  for(j=0;j<totalaluno;j++){
//  if(strcmp(estudantes[j].sexo,"alunoremovido")==0){
//	printf("ID: ");
//	scanf("%d", &estudantes[j].ID);
//	printf("SEXO(MASC / FEM / N BINARIO): ");
//	scanf("%s", estudantes[j].sexo);
//	printf("TESTE1: ");
//	scanf("%f", &estudantes[j].teste1);
//	printf("TESTE2: ");
//	scanf("%f", &estudantes[j].teste2);
//	estudantes[j].resultado = (estudantes[j].teste1+estudantes[j].teste2)/2;
//	printf("\n \n \n");
//  contador=1;
//  break;
//  }
//  }
//	
//}
//
//void remaluno(aluno estudantes[], int totalaluno, int id){
//  int i;
//  for(i=0;i<totalaluno;i++){
//  if(estudantes[i].ID==id){
//    strcpy(estudantes[i].sexo,"alunoremovido");
//  }
//  }
//}
//
//void editaraluno(aluno estudantes[],int totalaluno, int id){
//	int i;
//	for(i=0;i<totalaluno;i++){
//	if(id==estudantes[i].ID){
//		printf("EDITAR SEXO: ");
//		scanf("%s", estudantes[i].sexo);
//		printf("EDITAR TESTE1: ");
//		scanf("%f", &estudantes[i].teste1);
//		printf("EDITAR TESTE2: ");
//		scanf("%f", &estudantes[i].teste2);
//	}
//    }
//}
//
//void mostraralunos(aluno estudantes[], int totalaluno){
//	int i;
//	for(i=0;i<totalaluno;i++){
//    if(strcmp(estudantes[i].sexo,"alunoremovido")!=0){
//		
//		printf("ID: %d\n", estudantes[i].ID);
//		printf("TESTE1: %f\n", estudantes[i].teste1);
//		printf("TESTE2: %f\n", estudantes[i].teste2);
//		printf("SEXO: %s\n", estudantes[i].sexo);
//		printf("RESULTADO: %.1f\n", estudantes[i].resultado);
//		printf("\n");
//    }
//		}
//}
//
//void maiornota(aluno estudantes[], int totalaluno){
//		int i; 
//		float maior;
//		maior = estudantes[0].resultado;
//		for(i=0;i<totalaluno;i++){
//			if(estudantes[i].resultado>=maior){
//				maior = estudantes[i].resultado;
//			}
//		}
//		printf("MAIOR NOTA DA TURMA: %.1f", maior);
//}
//
//void menornota(aluno estudantes[], int totalaluno){
//		int i; 
//		float menor;
//		menor = estudantes[0].resultado;
//		for(i=0;i<totalaluno;i++){
//			if(estudantes[i].resultado<=menor){
//				menor = estudantes[i].resultado;
//			}
//		}
//		printf("MAIOR NOTA DA TURMA: %.1f", menor);
//}
//
//void encontraraluno(aluno estudantes[], int totalaluno, int id){
//	int i;
//	for(i=0;i<totalaluno;i++){
//	if(estudantes[i].ID==id){
//		printf("ESTE ID PERTENCE AO ALUNO[%d]\n", i+1);
//		printf("ID: %d\n", estudantes[i].ID);
//		printf("TESTE1: %f\n", estudantes[i].teste1);
//		printf("TESTE2: %f\n", estudantes[i].teste2);
//		printf("SEXO: %s\n", estudantes[i].sexo);
//		printf("RESULTADO: %.1f\n", estudantes[i].resultado);
//		printf("\n");
//		break;
//	}
//	}
//	
//}
//
//void ordenarpontuacao(aluno estudantes[], int totalaluno){
//			aluno store;
//			int i,j;
//			for(i=0;i<totalaluno;i++){
//				for(j=0;j<totalaluno;j++){
//					if(estudantes[j].resultado<estudantes[i].resultado){
//						store.ID = estudantes[i].ID;
//						strcpy(store.sexo,estudantes[i].sexo);
//						store.teste1 = estudantes[i].teste1;
//						store.teste2 = estudantes[i].teste2;
//						store.resultado = estudantes[i].resultado;
//						
//						estudantes[i].ID = estudantes[j].ID;
//						estudantes[i].teste1 = estudantes[j].teste1;
//						estudantes[i].teste2 = estudantes[j].teste2;
//						estudantes[i].resultado = estudantes[j].resultado;
//						strcpy(estudantes[i].sexo, estudantes[j].sexo);
//						
//						estudantes[j].ID = store.ID;
//						estudantes[j].teste1 = store.teste1;
//						estudantes[j].teste2 = store.teste2;
//						estudantes[j].resultado = store.resultado;
//						strcpy(estudantes[j].sexo, store.sexo);
//					}
//				}
//			}
//}
//
//int main(){
//	int i,j,totalaluno=2,id,maximo=0;
//	aluno *estudantes;
//
//	estudantes = (aluno*) malloc(totalaluno*sizeof(aluno));
//	
//	int loop = 0;
//	while (loop==0){
//	
//		printf("\n\n\n-----------------MENU-----------------");
//		printf("\n1.Adicionar registros de estudante");
//		printf("\n2.Deletar registros de estudante");
//		printf("\n3.Atualizar registros de estudante");
//		printf("\n4.Ver registros de todos os estudantes");
//		printf("\n5.Mostrar aluno com maior nota total");
//		printf("\n6.Mostrar aluno com menor total");
//		printf("\n7.Encontrar aluno por ID");
//		printf("\n8.Ordenar os registros por pontuacao total");
//		printf("\n9.Nao desejo mais adicionar nada\n");
//		int num;
//		scanf("%d", &num);	
//		
//		if(num==1){
//      if(maximo==0){
//			  addaluno(estudantes, totalaluno);
//        maximo++;
//      }
//      if(maximo!=0){
//       addalunodepois(estudantes, totalaluno);
//      }
//		}
//		
//		if(num==2){
//			printf("DIGITE O ID DO ALUNO QUE DESEJA REMOVER: ");
//			scanf("%d", &id);
//			remaluno(estudantes, totalaluno, id);
//		}
//		
//		if(num==3){
//			printf("DIGITE O ID DO ESTUDANTE QUE VOCÊ DESEJA EDITAR: ");
//			scanf("%d", id);
//			editaraluno(estudantes, totalaluno, id);
//		}
//		
//		if(num==4){
//			mostraralunos(estudantes, totalaluno);
//		}
//		
//		if(num==5){
//			maiornota(estudantes, totalaluno);
//		}
//		
//		if(num==6){
//			menornota(estudantes, totalaluno);
//		}
//		
//		if(num==7){
//			printf("\nDIGITE O ID: ");
//			scanf("%d", &id);
//			encontraraluno(estudantes,totalaluno,id);
//	
//		}
//		
//		if(num==8){
//			ordenarpontuacao(estudantes, totalaluno);
//		}
//		
//		if(num==9){
//			break;
//		}
//		
//	}
//
//  
//}



////questão 3.2
//typedef struct{
//	int numerador,denominador;
//}fracao;
//
//void soma_fracao(fracao p1, fracao p2){
//  	if (p1.denominador == p2.denominador){
//  	fracao soma = {p1.numerador+p2.numerador,p1.denominador+p2.denominador};
//    printf("%d %d", soma.numerador, soma.denominador);
//	}
//
//  if(p1.denominador != p2.denominador){
//    fracao soma = {((p1.numerador * p2.denominador)+(p2.numerador*p1.denominador)),          p1.denominador*p2.denominador};
//    printf("%d %d", soma.numerador, soma.denominador);
//  }
//}
//
//int main(){
//	fracao p1= {5,1};
//	fracao p2= {3,2};
//	soma_fracao(p2,p1);
//}



////questao 3.3
//typedef struct{
//	int x,y;
//}ponto;
//
//void calcular_distancia(ponto p,ponto q){
//	float distancia = sqrt(pow(q.x-p.x,2)  + pow(q.y-p.y,2));
//	printf("%f", distancia);
//}
//
//int main(){
//	ponto p = {2,3};
//	ponto q = {10,12};
//	calcular_distancia(p,q);
//}



////questao 3.4 e questao 3.5
//typedef struct{
//	char nome[101];
//	char endereco[201];
//	int telefone;
//}contato;
//
//void addpessoa(contato *agenda,int tamagenda,int *contador){
//  printf("CONTATO[%d]: \n", *contador);
//  printf("Nome do contato: ");
//  gets(agenda[*contador].nome);
//  fflush(stdin);
//  printf("Endereço do contato: ");
//  gets(agenda[*contador].endereco);
//  fflush(stdin);
//  printf("telefone do contato: ");
//  scanf("%d", &agenda[*contador].telefone);
//  *contador = *contador+1;
//  fflush(stdin);
//}
//
//void achar_contato(contato *agenda, char buscar[], int tamagenda){
//	int i;
//	  for(i=0;i<tamagenda;i++){
//  	if(strcmp(agenda[i].nome,buscar)==0){
//  		printf("Número associado ao nome buscado: %d", agenda[i].telefone);
//	  }
//  }
//}
//
//int main(){
//  char buscar[101];
//  int i,tamagenda=2;
//  contato *agenda;
//  int *contador;
//  contador = (int*)malloc(sizeof(int));
//  *contador = 0;
//  
//  agenda = (contato*) malloc(sizeof(contato)*tamagenda);
//
//  for(i=0;i<tamagenda;i++){
//    addpessoa(agenda,tamagenda,contador);
//  }
//  
//  printf("DIGITE O NOME DA PESSOA QUE VOCê DESEJA ENCONTRAR O CONTATO: ");
//  gets(buscar);
//  achar_contato(agenda,buscar, tamagenda);
//
//}



////questão 3.6
//typedef struct{
//	char modelo[100];
//	int ano;
//}carro;
//
//int main(){
//	int tam=1;
//	int indice = 0;
//	carro *catalogo;
//	catalogo = (carro*) malloc(tam*sizeof(carro));
//	
//	int loop=0;
//	while(loop==0){
//		printf("MODELO DO CARRO: ");
//		gets(catalogo[indice].modelo);
//		fflush(stdin);
//		printf("ANO DO CARRO: ");
//		scanf("%d", &catalogo[indice].ano);
//		if (catalogo[indice].ano<0){
//		break;
//		}
//		fflush(stdin);
//		tam++;
//		indice++;
//		catalogo = (carro*) realloc(catalogo, tam*sizeof(carro));
//		}
//		
//		return 0;
//	}
	
	
	
////questao 3.7
//typedef struct{
//	int registro;
//	char autor[100];
//	char titulo[100];
//	int disponibilidade;
//	// 0 para disponivel, 1 para não disponivel
//}livro;
//
//
//void addlivro(livro *biblioteca, int *contador, int tam){
//	printf("AUTOR DO LIVRO[%d]: ", *contador);
//	gets(biblioteca[*contador].autor);
//	fflush(stdin);
//	printf("TITULO DO LIVRO: ");
//	gets(biblioteca[*contador].titulo);
//	fflush(stdin);
//	printf("REGISTRO DO LIVRO: ");
//	scanf("%d", &biblioteca[*contador].registro);
//	fflush(stdin);
//	biblioteca[*contador].disponibilidade = 0;
//	*contador = *contador+1;
//	
//}
//
//void exibir_livro(livro *biblioteca, int registronum,int tam){
//	int i;
//	for(i=0;i<tam;i++){
//		if(registronum==biblioteca[i].registro){
//			printf("TITULO: %s", biblioteca[i].titulo);
//			printf("\nAUTOR: %s", biblioteca[i].autor);
//			if( (biblioteca[i].disponibilidade)==0){
//			printf("\nDISPONIBILIDADE: DISPONIVEL");
//			}
//			else{
//			printf("DISPONIBILIDADE: NAO DISPONIVEL");
//			}
//		}
//	}
//}
//
//void buscar(livro *biblioteca, char buscar_autor[],int tam ){
//	int i;
//	for(i=0;i<tam;i++){
//		if(strcmp(biblioteca[i].autor,buscar_autor)==0){
//			printf("TITULO: %s", biblioteca[i].titulo);
//			printf("\nAUTOR: %s", biblioteca[i].autor);
//			if( (biblioteca[i].disponibilidade)==0){
//			printf("\nDISPONIBILIDADE: DISPONIVEL");
//			}
//		else	{
//			printf("DISPONIBILIDADE: NAO DISPONIVEL");
//				}
//			}
//			printf("\n\n");
//	}
//	fflush(stdin);
//}
//
//int main(){
//
//	char buscar_autor[100];
//	int loop = 0, num, tam=1,registronum,i;
//	int *contador;
//	contador = (int*) malloc(sizeof(int));
//	*contador = 0;
//	
//	livro *biblioteca = NULL;
//	biblioteca = (livro*) malloc(tam*sizeof(livro));
//	
//	while (loop==0){
//		printf("\n\n\n\n\n-------------menu-------------");
//		printf("\n1.Exibir informacoes de um livro");
//		printf("\n2.Adicionar um novo livro");
//		printf("\n3.Exibir todos os livros da biblioteca de um determinado autor");
//		printf("\n4.Exibir o número total de livros na biblioteca");
//		printf("\n5.Sair\n");
//		
//		scanf("%d", &num);
//		fflush(stdin);
//		
//		if(num==1){
//			if(*contador!=0){
//				printf("DIGITE O REGISTRO DO LIVRO: ");
//				scanf("%d", &registronum);
//				fflush(stdin);
//				exibir_livro(biblioteca, registronum,tam);
//			}
//		}
//		
//		if(num==2){
//			addlivro(biblioteca, contador, tam);
//			tam++;
//			biblioteca = (livro*) realloc(biblioteca, tam*sizeof(livro));
//		}
//		
//		if(num==3){
//			fflush(stdin);
//			printf("DIGITE O NOME DO AUTOR QUE VOCE DESEJA BUSCAR: ");
//			gets(buscar_autor);
//			buscar(biblioteca, buscar_autor,tam);
//		}
//		
//		if(num==4){
//			printf("QUANTIDADE TOTAL DE LIVROS: %d", *contador);
//		}
//		
//		if(num==5){
//			break;
//		}
//	}
//	
//	return 0;
//	
//}



////escrever em um arquivo
//int main(){
//	FILE *arq=NULL;
//	arq = fopen("arq.txt", "w");
//	char str[100];
//	char nome[] = "mikael";
//	
//	
//	fwrite (nome, sizeof(char), strlen(nome), arq);
//	
//	return 0;
//}



////uso de scanf em arquivos
//  while((feof(arq)==0)){
//    fscanf(arq,"%s", nome);
//    printf("%s", nome);
//  }
//  }



////questao 4.1
//void palavras(FILE *arq, int tam, char nome[]){
//	int contarpalavras=0,caracteres=0;
//	int i;
//	while(fgets(nome,tam,arq)!=NULL){
//    printf("%s", nome);
//    contarpalavras++;
//    for(i=0;i<strlen(nome);i++){
//      caracteres++;
//      if(nome[i]=='\n'){
//        caracteres--;
//      }
//    }
//  }
//
//  printf("\nQuantidade de caracteres: %d", caracteres);
//  printf("\nQuantidade de palavras: %d", contarpalavras);
//}
//
//int main(){
//  
//  FILE *arq;
//  arq = fopen("arquivo.txt", "r");
//  int tam = 10000;
//  char nome[tam];
//  
//  palavras(arq, tam, nome);
//
//  return 0;
//
//}


////questao 5.1
//int main(){
//	
//	int custos[4][4] = {
//	{90, 80, 75, 70},
//	{35, 85, 55, 65},
//	{125, 95, 90, 95},
//	{45, 110, 95, 115}
//};	
//	
//	int tamlin = 4;
//	int tamcol = 4;
//	int menorvalor;
//	
//	int menoresvalores[]={0,0,0,0};
//	int indice=0;
//	
//	int i,j,auxi,auxj;
//	menorvalor = custos[0][0];
//	int contador = 0;
//	
//	while(contador<tamlin){
//	
//	for(i=0;i<tamlin;i++){
//		
//		for(j=0;j<tamcol;j++){
//			if(custos[i][j]<menorvalor && custos[i][j]!=0){
//				menorvalor = custos[i][j];
//				auxi = i;
//				auxj = j;
//			}
//		}
//		
//	}
//	
//	
//	for(j = 0; j<tamcol;j++){
//		custos[auxi][j] = 0;
//	}
//	
//	
//	for(i=0; i<tamlin;i++){
//		custos[i][auxj] = 0;
//	}
//	
//	menoresvalores[indice] = menorvalor;
//	printf("%d\t", menoresvalores[indice]);
//	indice++;
//	printf("\n\n\n\n\n");
//	
//	for(i=0;i<tamlin;i++){
//		for(j=0;j<tamcol;j++){
//			printf("\t%d", custos[i][j]);
//		}
//		printf("\n");
//	}
//	
//	contador++;
//	menorvalor = 1000;
//	
//}
//
//	return 0;
//}



////questao 4.1
//int main(){
//  
//  FILE *arq;
//  arq = fopen("arquivo.txt", "r");
//  char nome[100];
//  int contarpalavras=0;
//  int caracteres=0;
//  int i;
//
//  
//  while(fgets(nome,100,arq)!=NULL){
//    printf("%s", nome);
//    contarpalavras++;
//    for(i=0;i<strlen(nome);i++){
//      caracteres++;
//      if(nome[i]=='\n'){
//        caracteres--;
//      }
//    }
//    
//  }
//
//  
//  printf(" \n %d", caracteres);
//}



////uso de scanf em arquivos
//  while((feof(arq)==0)){
//    fscanf(arq,"%s", nome);
//    printf("%s", nome);
//  }
//  }



////escrevendo em arquivo;
//int main(){
//	FILE *arq=NULL;
//	arq = fopen("arq.txt", "w");
//	char str[100];
//	char nome[] = "mikael";
//	
//	
//	while(fwrite (nome, sizeof(char), strlen(nome), arq));
//	
//	return 0;
//}



////questao 4.2
//int main(){
//  char str[10];
//  FILE *arq;
//  arq = fopen("arq.txt", "r");
//  char nome_arq[] = "arq.txt";
//
//  FILE *arq2;
//  arq2 = fopen("arq2.txt", "w");
//  char nome_arq_renomeado[] = "arq2.txt";
//  char nome_arq_teste[] = "desgraça.txt";
//  
//  char removida[] = "aula";
//  
//  while(feof(arq)==0){
//    fscanf(arq, "%s", str);
//    if (strcmp(removida, str)!=0){
//    fprintf(arq2, "%s", str );
//    }
//  }
//  remove(nome_arq);
//  rename(nome_arq_renomeado, nome_arq);
//
//  
//}



////questao 4.3
//int main(){
//  char str[10];
//  int i;
//  int tamstr = 10;
//
//  int contador=0;
//  
//  FILE *arq = NULL;
//  arq = fopen("arq.txt", "r");
//  
//  // FILE *arq2 = NULL;
//  // arq2 = fopen("arq2.txt", "w");
//
//  while(fgets(str, tamstr, arq)!=NULL){
//    
//    for(i=0;i<strlen(str);i++){
//      if(str[i] != ' '){
//        contador++;
//        
//      }
//    }
//
//    //toda linha vai ter um \n, logo o menor valor possivel do contador será 1
//    if (contador > 1){
//      printf("%s", str);
//    }
//
//    contador = 0;
//  }
//}
//
//int main(){
//  char str[10];
//  FILE *arq;
//  arq = fopen("arq.txt", "r");
//
//  char palavra_escolhida[] = "aula"
//
//  while(feof(arq)==0){
//    fscanf(arq, "%s", str);
//    printf("%s", str);
//  }
//
//}




////questao 4.4
//int main(){
//  
//  char str[10];
//  FILE *arq;
//  arq = fopen("arq.txt", "r");
//  char removida[] = "hoje";
//  
//  while(feof(arq)==0){
//    fscanf(arq, "%s", str );
//    if(strcmp(removida, str)){
//      printf("%s\n", str);
//    }
//  }
//  
//}



////questao 4.5
//void renomeararquivo(FILE *arq, char nome_antigo[],char novo_nome[]){
//  rename(nome_antigo, novo_nome);
//}
//
//int main(){
//  FILE *arq = NULL;
//  arq = fopen("arq.txt", "r");
//  char nome_antigo[] = "arq.txt";
//  char novo_nome[] = "sexo2.txt";
//  
//  renomeararquivo(arq, nome_antigo, novo_nome);
//  fclose(arq);
//  
//}



////questao 4.6
//int main(){
//  char str[100];
//  char palavra[] = "iae mano";
//  FILE *arq = NULL;
//  arq = fopen("arq.txt", "r");
//  
//  int linha = 4;
//  int contador = 1;
//  
//  while(fgets(str, 100, arq)!=NULL){
//    if(contador == linha){
//      printf("%s\n", palavra);
//    }
//    else{
//      printf("%s", str);
//    }
//    contador++;
//  }
//  
//  fclose(arq);
//  
//}



////questao 4.7 a)
//int main(){
//  FILE *senha=NULL;
//  senha = fopen("senha.txt", "r");
//
//  
//  int k= 3;
//  int i;
//  char str[100];
//  int n = 10;
//  
//  while(fgets(str,100, senha)!=NULL){
//    
//    if(strlen(str)>n){
//      continue;
//    } 
//    
//    for(i=0;i<strlen(str);i++){
//      
//      if(str[i]=='\n' || str[i]==' '){
//        continue;
//      }
//      if(str[i]+k>'z'){
//        str[i] = (((str[i]+k)-'z')-1)+'a';
//        continue;
//      }
//      str[i] = str[i]+k;
//    }
//    
//    printf("%s", str);
//  }
//
//
//}



//////questao 4.7 b)
//int main(){
//
//  char str[10];
//  FILE *bd=NULL;
//  bd = fopen("bd.txt", "r");
//  int n = 10;
//  int k = 3;
//  int i;
//
//  while(fgets(str, 10, bd)!=NULL){
//    if (strlen(str)>n){
//      continue;
//    }
//    
//    for(i=0;i<strlen(str); i++){
//      if(str[i]==' ' || str[i]=='\n'){
//        continue;
//      }
//      
//      if(str[i]-k<'a'){
//        str[i] = 'z'-(k-(str[i]-'a'))+1;
//        printf("%c", str[i]);
//        continue;
//      }
//      
//      str[i] = str[i]-k;
//      printf("%c", str[i]);
//    }
//    
//    printf("\n");
//  }
//}



////questao 4.8
//int main(){
//  char str[100];
//  char str2[100];
//  FILE *arq=NULL;
//  arq = fopen("arq.txt", "r");
//
//  FILE *arq2=NULL;
//  arq2 = fopen("arq2.txt", "r");
//
//  FILE *arq3=NULL;
//  arq3 = fopen("arq3.txt", "w");
//
////foi necessario dar um enter na ultima linha do primeiro arquivo
//  while(feof(arq)==0 || feof(arq2)==0){
//    if(fgets(str, 100, arq)!=NULL){
//      fprintf(arq3, "%s", str);
//    }
//    
//    if(fgets(str2, 100, arq2)!=NULL){
//      fprintf(arq3, "%s", str2);
//    }
//   
//  }
//
//}

