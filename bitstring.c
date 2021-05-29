#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* converte (int numero) {

	int r; // Resultado do deslocamento
	int i; // Contador
	char* bitString = (char*) malloc(8 * sizeof(char));

	for(i = 7; i >= 0; i--) {
		r = numero >> i;
		if(r & 1) strcat(bitString, "1");
		else strcat(bitString, "0");
	}
	return bitString;
}

int main(void) {

	int numero, largura, altura, Cor, i, j;
	char type[3];
	FILE *arq = fopen("first2.ppm", "r");
	fscanf(arq, "%s", type);
	fscanf(arq, "%d %d", &largura, &altura);
	fscanf(arq, "%d", &Cor);
	i = 1;
	
	for(j = 0; j < (altura * largura * 3); j++) {
		fscanf(arq, "%d", &numero); 	
		char* bitString = converte(numero);
		printf("linha %d : %s\n", i, bitString);
		i++;
	}
	
	fclose(arq);
	
	//getch();
	return(0);
}
