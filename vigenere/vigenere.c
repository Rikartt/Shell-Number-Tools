#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
void readInputString(char *str[], char output[3][256], int amtargs) { //reads argv and takes the first argument as the key and all subsequent text as the plaintext.
    strcpy(output[0], str[1]); //mode, e or d
    strcpy(output[1], str[2]); //take key input
    for (int i=3;i<amtargs;i++) { //loop that builds plaintext
        strcat(output[2], str[i]); 
        if (i < amtargs - 1) {
            strcat(output[2], " ");
        }
    }
}
void invalidinputerr(char *argv[]) {
    fprintf(stderr, "Error: invalid input.\n Input of %s is as follows: \n  %s [mode: e(ncrypt)|d(ecrypt)] [key] [plaintext / ciphertext] \n", argv[0], argv[0]);
    exit(1);
}
void encrypt (char key[], char plaintext[], char ciphertext[]) {
    int j = 0; //the index we should have in the key, because when encrypting we skip spaces and punctuation.
    for (int i=0;i<strlen(plaintext);i++) {
        char newlet = plaintext[i];
        if (isalpha((unsigned char)plaintext[i])) {
            if isupper((unsigned char)plaintext[i]) {
                newlet = 'A'+(26+toupper(plaintext[i])+toupper(key[j%strlen(key)])-2*'A')%26;
            } else {
                newlet = 'a'+(26+tolower(plaintext[i])+tolower(key[j%strlen(key)])-2*'a')%26;
            }
            j++;
        }
        ciphertext[i] = newlet;
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void decrypt (char key[], char ciphertext[], char plaintext[]) {
    int j = 0; //the index we should have in the key, because when encrypting we skip spaces and punctuation.
    for (int i=0;i<strlen(ciphertext);i++) {
        char newlet = ciphertext[i];
        if (isalpha((unsigned char)ciphertext[i])) {
            if isupper((unsigned char)ciphertext[i]) {
                newlet = 'A'+(26+(toupper(ciphertext[i]))-(toupper(key[j%strlen(key)])))%26;
            } else {
                newlet = 'a'+(26+(tolower(ciphertext[i]))-(tolower(key[j%strlen(key)])))%26;
            }
            j++;
        }
        plaintext[i] = newlet;
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main(int argc, char *argv[]) {
    char *end = NULL;
    char input[3][256] = {0};
    if (argc<4) {
        invalidinputerr(argv);
    }
    readInputString(argv,input,argc);
    if (tolower(input[0][0]) == 'e') {
        char ciph[256]; encrypt(input[1],input[2], ciph);
        printf("%s\n", ciph);
    }
    if (tolower(input[0][0]) == 'd') {
        char plain[256]; decrypt(input[1],input[2], plain);
        printf("%s\n", plain);
    }
}