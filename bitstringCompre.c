#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//EXECUTA COM -lm

/*char* converte (int texto_str) {

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
*/
int main(void) {

	int texto_str, maxColor, i, j, media, k, texto_strG, texto_strB, mediaB, mediaG, novaLarguraI, novaAlturaI, janela;
	float largura, altura, novaLargura, novaAltura;
	char type[3];
	
	printf("Tamanho da janela desejada: \n");
	scanf("%d", &janela);
	FILE *arq = fopen("first2.ppm", "r");
	FILE *arq2 = fopen("comprimido.ppm", "w");
	
	fscanf(arq, "%s", type);
	fprintf(arq2, "%s\n", type);
	
	fscanf(arq, "%f %f", &largura, &altura);

	novaLargura = largura/sqrt(janela);
	novaAltura = altura/sqrt(janela);
	novaLargura = floor(novaLargura);
	novaAltura = ceil(novaAltura);
	
	novaLarguraI = (int) novaLargura;
	novaAlturaI = (int) novaAltura;
	
	fprintf(arq2, "%d %d\n", novaLarguraI, novaAlturaI);
	printf("%d %d\n", novaLarguraI, novaAlturaI);
	
	fscanf(arq, "%d", &maxColor);
	fprintf(arq2, "%d\n", maxColor);
	
	//i = 1;
	k = 0;
	for(j = 0; j < (altura * largura); j++) {
		
		fscanf(arq, "%d", &texto_str);
		texto_str += texto_str;
		
		fscanf(arq, "%d", &texto_strG);
		texto_strG += texto_strG;
		
		fscanf(arq, "%d", &texto_strB);
		texto_strB += texto_strB;
		
		k++;
		if (k == janela) {
			media = texto_str/janela;
			mediaG = texto_strG/janela;
			mediaB = texto_strB/janela;
			fprintf(arq2, "%d %d %d\n", media, mediaG, mediaB);
			
			texto_str = 0;
			texto_strG = 0;
			texto_strB = 0;
			k = 0;
		}	
			//char* bitString = converte(texto_str);
			//printf("Linha %d : %s\n", i, bitString);
			//i++;
	}
	
	fclose(arq);
	fclose(arq2);
	arq = fopen("comprimido.ppm", "r");
	arq2 = fopen("descomprimido.ppm", "w");
	
	fscanf(arq, "%s", type);
	fprintf(arq2, "%s\n", type);
	
	fscanf(arq, "%f %f", &largura, &altura);
	largura = largura * sqrt(janela);
	altura = altura * sqrt(janela);
	novaLargura = ceil(largura);
	novaAltura = floor(altura);
	novaLarguraI = (int) novaLargura;
	novaAlturaI = (int) novaAltura;
	
	fprintf(arq2, "%d %d\n", novaLarguraI, novaAlturaI);
	printf("descomprimido: %d %d\n", novaLarguraI, novaAlturaI);
	
	fscanf(arq, "%d", &maxColor);
	fprintf(arq2, "%d\n", maxColor);
	
	//i = 1;
	for(j = 0; j < (altura * largura); j++) {
		fscanf(arq, "%d %d %d", &texto_str, &texto_strG, &texto_strB);
		for	(k = 0; k < janela; k++) {
			fprintf(arq2, "%d %d %d\n", texto_str, texto_strG, texto_strB);
		}
	}
	fclose(arq);
	fclose(arq2);
	
	//getch();
	return(0);
}
