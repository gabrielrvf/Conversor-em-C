//
//  main.c
//  Logica Computacional Programa
//
//  Created by Gabriel Vilarouca on 01/06/20.
//  Copyright © 2020 Gabriel Vilarouca. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include<math.h>

int tipoDeValor;

void calculadoraUm(void);
void calculadoraDois(void);
void decimalParaOctal(int);
void decimalParaHexadecimal(int);
void decimalParaBinario(int);
void continuar(void);

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "Portuguese");
    printf("Lógica Computacional - Gabriel Rosa Vilarouca Farias\n");
    calculadoraUm();
    return 0;
}

void calculadoraUm(void){
    printf("\n-------------------------------");
    printf("\nCALCULADORA\n\n");
    printf("Qual tipo de valor será adicionado?\n");
    printf("1 para BINÁRIO\n");
    printf("2 para DECIMAL\n");
    printf("3 para OCTAL\n");
    printf("4 para HEXADECIMAL\n");
    printf("0 para SAIR\n\n");
    printf("Digite o número correspondente e aperte ENTER para confirmar: ");
    scanf("%i", &tipoDeValor);
    if(tipoDeValor == 0){
        printf("\n-------------------------------");
        printf("\nAté logo :D\n");
        return;
    }else if (tipoDeValor == 1){
        printf("\n-------------------------------");
        printf("\nBINÁRIO\n\n");
        calculadoraDois();
    }else if (tipoDeValor == 2){
        printf("\n-------------------------------");
        printf("\nDECIMAL\n\n");
        calculadoraDois();
    }else if (tipoDeValor == 3){
        printf("\n-------------------------------");
        printf("\nOCTAL\n\n");
        calculadoraDois();
    }else if (tipoDeValor == 4){
        printf("\n-------------------------------");
        printf("\nHEXADECIMAL\n\n");
        calculadoraDois();
    }else{
        printf("\n-------------------------------");
        printf("\nVALOR INVÁLIDO");
        calculadoraUm();
    }
}

void calculadoraDois(void){
    if (tipoDeValor == 1){
        int bin, dec = 0, i;
        printf("Entre com o valor binário: ");
        scanf("%d", &bin);
        int valor = bin;
        for(i = 0; bin > 0; i++)
        {
            dec = dec + pow(2, i) * (bin % 10);
            bin = bin / 10;
        }
        printf("\n");
        printf("\n-------------------------------");
        printf("\n\n");
        printf("Binário: %d", valor);
        printf("\nDecimal: %d", dec);
        decimalParaOctal(dec);
        decimalParaHexadecimal(dec);
        continuar();
    }else if (tipoDeValor == 2){
        int dd;
        printf ("Entre com o valor decimal: ");
        scanf("%d", &dd);
        printf("\n");
        printf("\n-------------------------------");
        printf("\n\n");
        printf("Decimal: %d", dd);
        decimalParaOctal(dd);
        decimalParaHexadecimal(dd);
        decimalParaBinario(dd);
        continuar();
    }else if (tipoDeValor == 3){
        int valor_decimal = 0, sequencia = 0, valor_octal;
        printf ("Entre com o valor octal: ");
        scanf("%d", &valor_octal);
        printf("\n");
        printf("\n-------------------------------");
        printf("\n\n");
        printf("Octal: %d", valor_octal);
           while(valor_octal != 0)
           {
               valor_decimal += (valor_octal % 10) * pow(8, sequencia);
               ++sequencia;
               valor_octal /= 10;
           }
        printf("\nDecimal: %d", valor_decimal);
        decimalParaHexadecimal(valor_decimal);
        decimalParaBinario(valor_decimal);
        continuar();
    }else if (tipoDeValor == 4){
        int h;
        printf ("Entre com o valor hexadecimal: ");
        scanf ("%X",&h);
        printf("\n");
        printf("\n-------------------------------");
        printf("\n\n");
        printf ("Decimal: %d",h,h);
        decimalParaOctal(h);
        decimalParaHexadecimal(h);
        decimalParaBinario(h);
        continuar();
    }
}

void decimalParaOctal(n){
    int i = 1,a;
    int octal = 0;

    if(n<=7) {
        octal=n;
    }
    else {
        while(n>=8) {
            a=n%8;
            n=n/8;
            octal = octal + a * i;
            i *= 10;
        }
        n=n%8;
        octal = octal + n * i;
        printf("\nOctal: %d", octal);
    }
}

void decimalParaHexadecimal(num)
{
     printf ("\nHexadecimal: %2X",num,num);
}

void decimalParaBinario(num){
    int r;
    int i;
    int k;
    printf("\nBinário: ");
    for(i = 31; i >= 0; i--) {
       r = num >> i;
       if(r & 1) {
           k = 1;
           printf("1");
       } else if (k == 1){
           printf("0");
       }
    }
}

void continuar(void){
    printf("\n\n-------------------------------");
    printf("\nO QUE DESEJA FAZER?\n\n");
    printf("1 para CONTINUAR");
    printf("\n0 para SAIR");
    printf("\n\nDigite o número correspondente e aperte ENTER para confirmar: ");
    int cc;
    scanf("%i", &cc);
    if (cc == 1){
        calculadoraUm();
    }else if (cc == 0){
        printf("\n-------------------------------");
        printf("\nAté logo :D\n");
        return;
    }else{
        printf("\n-------------------------------");
        printf("\nVALOR INVÁLIDO!");
        continuar();
    }
}
