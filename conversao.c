#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n; // Número de entrada
	int r; // Resultado do deslocamento
	int i; // Contador
	char bitString[8] = "";
	
	printf("Digite o numero: ");
	scanf("%d", &n);

	// Utiliza um número de 32 bits como base para a conversão.
	for(i = 7; i >= 0; i--) {
	// Executa a operação shift right até a última posição da direita para cada bit.
		r = n >> i;
		if(r & 1) {
			strcat(bitString, "1");
     	} else {
			strcat(bitString, "0");
		}
	}
	printf(" bitstring = %s\n", bitString);

	printf("\n");

}
