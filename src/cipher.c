#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


const char* text_file_to_string( char*);
void verify_and_call_functions(int, char*[]);
void encode(const char *, size_t shift);
void decode (const char*, size_t shift);
void print_options(void);

int main(int argc, char *argv[]) {
  if (argc > 2) {
    verify_and_call_functions(argc, argv);
  }else {
    print_options();
  }
  
}

void verify_and_call_functions(int argc, char *argv[]) {
  if (strcmp(argv[1], "encode") == 0 && strcmp(argv[2], "-f") == 0) {
    const char *string = text_file_to_string(argv[3]);
    if (argv[4]) { 
    	encode(string, atoi(argv[4]));
    }else {
    	encode(string, 3);
    }
  }else if (strcmp(argv[1], "encode") == 0 && strcmp(argv[2], "-q") == 0) {
    if (argv[4]) {
   	encode(argv[3], atoi(argv[4]));
    }else {
	encode(argv[3], 3);
    } 
  }else if (strcmp(argv[1], "decode") == 0 && strcmp(argv[2], "-f") == 0) {
    const char *string = text_file_to_string(argv[3]);
    if (argv[4]) {
    	decode(string, atoi(argv[4]));
    }else {
    	decode(string, 3);
    }
  }else if (strcmp(argv[1], "decode") == 0 && strcmp(argv[2], "-q") == 0) {
    if (argv[4]) {
    	decode(argv[3], atoi(argv[4]));
    }else {
    	decode(argv[3], 3);
    }
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

  return buffer;

}

  
void encode(const char *string, size_t shift) {
  char text_encoded[strlen(string)];
  text_encoded[strlen(string)] = '\0';
  
  for (size_t i = 0; i < strlen(string); i++) {
    size_t ascii_value = string[i] - '\0';
    if ((ascii_value + shift > 'Z' && ascii_value < 'Z' + 1) || (ascii_value + shift > 'z' && ascii_value < 'z' + 1)) {
      text_encoded[i] = ascii_value - (26 - shift);
    }else if (ascii_value > 'A' ||ascii_value > 'a'){
      text_encoded[i] = ascii_value + shift;
    }else {
      text_encoded[i] = ascii_value;
    }
  }
  printf("TEXT encode OUTPUT:\n%s\n", text_encoded);
}

void decode(const char* string, size_t shift) {
  char text_decoded[strlen(string)];
  text_decoded[strlen(string)] = '\0';

  for (size_t i = 0; i < strlen(string); i++) {
    size_t ascii_value = string[i] - '\0';
    if((ascii_value - shift < 'A' && ascii_value > 'A' - 1) || (ascii_value - shift < 'a' && ascii_value > 'a' - 1)) {
      text_decoded[i] = ascii_value + (26 - shift);
    }else if (ascii_value  - shift >= 'A' || ascii_value - shift >= 'a') {
      text_decoded[i] = ascii_value - shift;
    }else {
      text_decoded[i] = ascii_value;
    }
  }

  printf("TEXT decoded OUTPUT:\n%s\n", text_decoded);
}



void print_options(void) {
  printf("\nNAME\n\t\tcipher - encode and decode text in shift/caesar cipher\n\nSYNOPSIS\n\t\t./cipher [MODE] [INPUT MODE] [SHIFT]\n\nDESCRIPTION\n\t\tEncode and decode text from a file or not in caesar/shift cipher");
  printf("\n\nUSAGE\n\t\tMODE: [encode|decode].");
  printf("\n\n\t\tINPUT MODE: [-f|q]\t-f means from the file / -q means from the quotes.");
  printf("\n\n\t\tSHIFT: In the last argument if you want pass the shift value, \n\t\totherwise leave it blank for use the default -> 3.\n\n");
  printf("EXAMPLES\n\t\t./cipher encode -q \"HELLO WORLD\" 4");
  printf("\n\n\t\tThis will set the mode to encode, the input mode for quotes,\n\t\tand the shift value to 4. With this command the output will be: LIPPS ASVPH.\n");
  printf("\n\t\t./cipher decode -f \"textFile.txt\" 4");
  printf("\n\n\t\tIf the content of the \"textFile.txt\" is LIPPS ASVPH\n\t\tthen the output will be: HELLO WORLD.\n");
  printf("\nAUTHOR\n\t\tWritten by Luiz Guilherme C. Silva.");
  printf("\n\nCOPYTIGHT\n\t\tCopyright (C) 1989, 1991 Free Software Foundation, Inc.,\n\t\t51 Franklin Street, Fifth Floor, Boston, MA 02110-1301\n\t\tUSA Everyone is permitted to copy and distribute verbatim copies\n\t\tof this license document, but changing it is not allowed.\n");
}



