#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *padding(char *message);
void print_byte_as_bits(char val);

char* padding(char *message)
{
  int message_length=(strlen(message));
  int number_of_bits_to_pad=(64-(message_length*8));
  printf("\nMessage Length=%d\t",message_length);
  printf("\nNumber of padded bits=%d\t",number_of_bits_to_pad);
  memset(&message[message_length], 0, number_of_bits_to_pad);
  return message;
}

void print_byte_as_bits(char val) {
  for (int i = 0; i <= 7; i++) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

int main()
{   
	char *message=malloc(sizeof(message)*8);
	printf("\nEnter a message");
    fgets(message,8,stdin);

    /*printf("\n Message Before Padding=");
    for(int i=0;i<8;++i)
    {
    	print_byte_as_bits(message[i]);
    }

    message=padding(message);
    
    printf("\n Message After Padding=");
    for(int i=0;i<8;++i)
    {
    	print_byte_as_bits(message[i]);
    }*/

	return 0;
}