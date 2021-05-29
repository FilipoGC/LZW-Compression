#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* converte (int texto_str) {

	int r; // Resultado do deslocamento
	int i; // Contador
	char* bitString = (char*) malloc(8 * sizeof(char));

	for(i = 7; i >= 0; i--) {
		r = texto_str >> i;
		if(r & 1) strcat(bitString, "1");
		else strcat(bitString, "0");
	}
	return bitString;
}

int main(void) {

	int texto_str, largura, altura, maxColor, i, j;
	char type[3];
	FILE *arq = fopen("first2.ppm", "r");
	fscanf(arq, "%s", type);
	fscanf(arq, "%d %d", &largura, &altura);
	fscanf(arq, "%d", &maxColor);
	i = 1;
	
	for(j = 0; j < (altura * largura); j++) {
		fscanf(arq, "%d", &texto_str); 	
		char* bitStringR = converte(texto_str);
		fscanf(arq, "%d", &texto_str); 	
		char* bitStringG = converte(texto_str);
		fscanf(arq, "%d", &texto_str); 	
		char* bitStringB = converte(texto_str);
		
		printf("Linha %d : %s %s %s\n", i, bitStringR, bitStringG, bitStringB);
		i++;
	}
	
	fclose(arq);
	
	//getch();
	return(0);
}
