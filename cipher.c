#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


const char* text_file_to_string( char*);
void verify_and_call_functions(int, char*[]);
void encode(const char *);
void decode (const char*);
void print_options(void);

int main(int argc, char *argv[]) {
  if (argc > 2) {
    verify_and_call_functions(argc, argv);
  }else {
    print_options();
  }
  
}

void verify_and_call_functions(int argc, char *argv[]) {
  if (strcmp(argv[1], "encode") == 0 && strcmp(argv[2], "f") == 0) {
    const char *string = text_file_to_string(argv[3]);
    encode(string);
  }else if (strcmp(argv[1], "encode") == 0 && strcmp(argv[2], "n") == 0) {
    encode(argv[3]);
  }else if (strcmp(argv[1], "decode") == 0 && strcmp(argv[2], "f") == 0) {
    const char *string = text_file_to_string(argv[3]);
    decode(string);
  }else if (strcmp(argv[1], "decode") == 0 && strcmp(argv[2], "n") == 0) {
    decode(argv[3]);
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

  
void encode(const char *string) {
  char text_encoded[strlen(string)];
  
  for (size_t i = 0; i < strlen(string); i++) {
    size_t ascii_value = string[i] - '\0';
    if ((ascii_value > 87 && ascii_value < 91) || (ascii_value > 119 && ascii_value < 123)) {
      text_encoded[i] = ascii_value - 23;
    }else if (ascii_value > 64 || ascii_value > 96){
      text_encoded[i] = ascii_value + 3;
    }else {
      text_encoded[i] = ascii_value;
    }
  }
  printf("TEXT encode OUTPUT:\n%s\n", text_encoded);
}

void decode(const char* string) {
  char text_decoded[strlen(string)];

  for (size_t i = 0; i < strlen(string); i++) {
    size_t ascii_value = string[i] - '\0';
    if((ascii_value > 64 && ascii_value < 68) || (ascii_value > 96 && ascii_value < 100)) {
      text_decoded[i] = ascii_value + 23;
    }else if (ascii_value > 67 || ascii_value > 99) {
      text_decoded[i] = ascii_value - 3;
    }else {
      text_decoded[i] = ascii_value;
    }
  }

  printf("TEXT decoded OUTPUT:\n%s\n", text_decoded);
}



void print_options(void) {
  printf("The following options are avaible:\n\n");
  printf("command:\t\t\t\tmode:\t\t\t\tusage example:\n");
  printf("encode\t\t\t\t\tf/n\t\t\t\t./cipher encode f './test.txt'\n");
  printf("decode\t\t\t\t\tf/n\t\t\t\t./cipher decode n 'Hello World!'\n");
}




