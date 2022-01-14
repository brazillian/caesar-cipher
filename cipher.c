#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


const char* text_file_to_string(char*);
void verify_and_call_functions(int, char*[]);
void encrypt(const char *);
void decrypt (const char*);
void print_options(void);

int main(int argc, char *argv[]) {
  if (argc > 2) {
    verify_and_call_functions(argc, argv);
  }else {
    print_options();
  }
  
}

void verify_and_call_functions(int argc, char *argv[]) {
  if (strcmp(argv[1], "encrypt") == 0 && strcmp(argv[2], "f") == 0) {
    const char *string = text_file_to_string(argv[3]);
    encrypt(string);
  }else if (strcmp(argv[1], "encrypt") == 0 && strcmp(argv[2], "n") == 0) {
    encrypt(argv[3]);
  }else if (strcmp(argv[1], "decrypt") == 0 && strcmp(argv[2], "f") == 0) {
    const char *string = text_file_to_string(argv[3]);
    decrypt(string);
  }else if (strcmp(argv[1], "decrypt") == 0 && strcmp(argv[2], "n") == 0) {
    decrypt(argv[3]);
  }else {
    printf("ERROR: Options not allowed or incorrect syntax\n\n");
    print_options();
  }
}

const char* text_file_to_string(char *path) {
  char* buffer = 0;
  long lenght;
  FILE *text_file = fopen(path, "r");

  if (text_file) {
    fseek(text_file, 0, SEEK_END);
    lenght = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);
    buffer = malloc(lenght + 1);
    if (buffer) {
      fread(buffer, 1, lenght, text_file);

    }
  fclose(text_file);
  buffer[lenght] = '\0';
  }else {
    printf("Cant read file %s\n", path);
    exit(1);
  }

  if (buffer) return buffer;

}

  
void encrypt(const char *string) {
  printf("String input:\n%s\n", string);
}

void decrypt(const char* string) {
  printf("String input:\n%s\n", string);
}


void print_options(void) {
  printf("The following options are avaible:\n\ncommand:\t\t\t\tmode:\t\t\t\tusage example:\nencrypt\t\t\t\t\tf/n\t\t\t\t./cipher encrypt f './test.txt'\n");
  printf("decrypt\t\t\t\t\tf/n\t\t\t\t./cipher decrypt n 'Hello World!'\n");
}




