#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void interpretCommands(size_t numberOfArgs, char *argsValue[]);
char* encryptText(char *textArgument, char mode[6]);
char* decryptText(char *textArgument, char mode[6]);
const char* extractTextOfFile (char *path);

int main(size_t argc, char *argv[] ) {
  interpretCommands(argc, argv);
  return 0;
}

void interpretCommands(size_t numberOfArgs, char *argsValue[]) {
  if (numberOfArgs < 3) {
    if (strcmp(argsValue[1], "encrypt") == 0 && strcmp(argsValue[2], "-f") == 0) {
      encryptText(argsValue[2], "-f");
    }
    else if (strcmp(argsValue[1], "encrypt") == 0 && strcmp(argsValue[2], "-f") != 0 ){
      encryptText(argsValue[2], "normal");
    }
    else if (strcmp(argsValue[1], "decrypt")== 0 && strcmp(argsValue[2], "-f") == 0) {
      decryptText(argsValue[2], "-f");
    }
    else if (strcmp(argsValue[1], "decrypt") == 0 && strcmp (argsValue[2], "-f") !=0) {
      decryptText(argsValue[2], "normal");
    }
  }else {
    printf("exceeded command limits");
  }    
}


char* encryptText(char *argsValueOfText, char mode[6]) {
  if (strcmp(mode, "-f") == 0) {
    char text = extractTextOfFile(argsValueOfText);
    printf("%s", text);
  }else {
    printf("%s", argsValueOfText);

  }


}
char* decryptText(char *argsValueOfText, char mode[6]) {
  printf("aqui");

}

const char* extractTextOfFile (char* path) {
  FILE* textFile = fopen(path, "r");
  if (textFile == NULL) {
    printf("Cannot open file!!!");
    exit(EXIT_FAILURE);
  }

  fseek(textFile, 0L, SEEK_END);
  char *extractedText[ftell(textFile)];
  int count = 0;
  
  for ( char c = fgetc(textFile); c != EOF; c = fgetc(textFile), count++) {
    extractedText[count] = c;
  }
  
  return extractedText;

}
