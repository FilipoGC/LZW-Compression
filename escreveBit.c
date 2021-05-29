#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void print(vector<int> saida) {
	int i;
	for(i = 0; i < saida.size(); i++) {
		cout << saida.at(i) << endl;	
	}

}

vector<int> lzwEncoding (string bits) {
	unordered_map<string, int> mp;
	string ch = ""; 
	ch += char(0); 
	mp[ch] = 0;
	
	string ch2 = ""; 
	ch2 += char(1); 
	mp[ch2] = 1;
	 
	string p = "";
	string c = "";
	p += bits[0];
	int code = 2;
	vector<int> saida;
	for(int i = 0; i < bits.length(); i++) {
		if(i != bits.length() - 1) { 
			c += bits[i + 1];
		}
		if(mp.find(p + c) != mp.end()) {
			p = p + c;
		}
		else {
			//cout << "String\tsaida\tAdittion\n";
			//cout << p << "\t" << mp->at(p) << "\t\t" << p + c << "\t" << code << endl; 
			//printf("linha 28\n");
			saida.push_back(mp[p]);
			mp.insert(make_pair(p + c, code));
			code++;
			p = c;
			printf("contador: %d\n", code);
		}
		c = "";
	}
	//printf("em baixo: \n");
	cout << p << endl;
	saida.push_back(mp[p]);
	return saida;
}

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

void lzwDecoding(vector<int> op, FILE *arq4) {  
    unordered_map<int, string> mp; 
    
    string ch = ""; 
	ch += char(0); 
	mp[0] = ch;
	
	string ch2 = ""; 
	ch2 += char(1); 
	mp[1] = ch2;

    int old = op[0], n; 
    string s = mp[old]; 
    string c = "";
    fprintf(arq4, "%s\n", s);
    c += s[0]; 
    int count = 2; 
    for (int i = 0; i < op.size() - 1; i++) { 
        n = op[i + 1]; 
        if (mp.find(n) == mp.end()) { 
            s = mp[old]; 
            s = s + c; 
        } 
        else { 
            s = mp[n]; 
        }  
        fprintf(arq4, "%s\n", s);
        c = ""; 
        c += s[0]; 
        mp[count] = mp[old] + c; 
        count++; 
        old = n; 
    } 
} 
int main(void) {
	
	//unordered_map<string, int>* mp = new unordered_map<string, int> ();
	//vector<int>* saida = new vector<int> ();
	
	int code = 2;
	string p = "";
	int texto_str, largura, altura, maxColor, i, j;
	char type[3];
	FILE *arq = fopen("first2.ppm", "r");
	FILE *arq2 = fopen("EmBit.txt", "w");
	
	fscanf(arq, "%s", type);
	fprintf(arq2, "%s\n", type);
	
	fscanf(arq, "%d %d", &largura, &altura);
	char* larguraBit = converte(largura);
	char* alturaBit = converte(altura);
	fprintf(arq2, "%s %s\n", larguraBit, alturaBit);
	
	
	fscanf(arq, "%d", &maxColor);
	char* colorBit = converte(maxColor);
	fprintf(arq2, "%s\n", colorBit);
	
	i = 1;
	
	for(j = 0; j < (altura * largura); j++) {
		fscanf(arq, "%d", &texto_str); 	
		char* bitStringR = converte(texto_str);
		printf("ta no: %d\n\n\n", j);
		p += bitStringR;
		
		
		fscanf(arq, "%d", &texto_str); 	
		char* bitStringG = converte(texto_str);
		p += bitStringG;
		
		fscanf(arq, "%d", &texto_str); 	
		char* bitStringB = converte(texto_str);
		p += bitStringB;
		
		fprintf(arq2, "%s %s %s\n", bitStringR, bitStringG, bitStringB);
		i++;
	}
	vector<int> saida = lzwEncoding(p);
	FILE *arq3 = fopen("comprimido.txt", "w");
	
	fprintf(arq3, "%s\n", type);
	fprintf(arq3, "%s %s\n", larguraBit, alturaBit);
	fprintf(arq3, "%s\n", colorBit);
	
	for (int k = 0; k < saida.size(); k++) {
		fprintf(arq3, "%c\n", saida.at(k));
	}
	fclose(arq3);
	FILE *arq4 =fopen("descomprimido.txt", "w");
	
	lzwDecoding(saida, arq4);
	fclose(arq4);
	
	print(saida);
	fclose(arq);
	fclose(arq2);
	
	//getch();
	return(0);
}
