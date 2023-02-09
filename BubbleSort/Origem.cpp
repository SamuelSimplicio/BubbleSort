#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bolhaRecursiva(int p[], int w) { // bubbleSort recursivo passando vetor e tamanho por parametro usando 'ponteiros'.
	int i, j, aux;
	while (w >= 1)
	{
		for ( i = 0; i < w - 1; i++)
		{
			if (p[i] > p[i + 1]) {
				aux = p[i];
				p[i] = p[i + 1];
				p[i + 1] = aux;
			}
		}
		return bolhaRecursiva(p, w - 1);
	}
	return *p;
}

int main() {

	srand(time(NULL));

	int aux, i, j, * p, tam;

	printf("Quantos numeros voce quer digitar: "); 
	scanf_s("%d", &tam);

	p = (int*)malloc(tam * sizeof(int)); // alocação dinamica atraves de ponteiros.

	if (p == NULL) {
		printf("Erro na Alocacao de Memoria!!");
		exit(1);
	}
	
	printf("\nDigite %d numeros em sequencia: \n", tam);


	for ( i = 0; i < tam; i++){
		scanf_s("%d", &p[i]);
	}

	printf("\nNumero desordenados: ");

	for ( i = 0; i < tam; i++){
		printf("%d ", *(p + i));
	}

	printf("\nNumeros ordenados (BubbleSort): \n"); // Ordenação.

	for ( i = tam - 1; i >= 1; i--){  // metodo interativo bubbleSort.
		for ( j = 0; j < i; j++)
		{
			if (p[j] > p[j + 1])  // usando o metodo mais economico. 
			{
				aux = p[j];
				p[j] = p[j + 1];
				p[j + 1] = aux;
			}
		}
	}

	for ( i = 0; i < tam; i++){
		printf("%d ", *(p + i)); // imprime vetor ordenado
	}

	printf("\nMisturando o vetor novamente: ");  // misturando novamente usando rant time, para implementar valores aleatorio.
	for ( i = 0; i < tam; i++)
	{
		p[i] = rand() % 100; 
	}
	printf("\n");
	for ( i = 0; i <  tam; i++)
	{
		printf("%d ", *(p + i));
	}

	printf("\n");
	bolhaRecursiva(p, tam); // função recursiva para organizar novamente o vetor.

	for (i = 0; i < tam; i++)
	{
		printf("%d ", *(p + i));
	}
	

	// toda organização é feita em ordem crescente.
	return 0;
}