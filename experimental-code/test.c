#include <stdio.h>

void print_bits(char byte)
{
	for(char i=7;i>=0;--i)
	{   //Doubtful how this works
		printf("%c",(byte &(1<<i)) ? '1':'0');
	}
}

int main()
{
	char c='C',d='C';
	char n;
	printf("\nC=");
	print_bits(c);
	//printf("\nD=");
	//print_bits(d);
	do
	{
	  
	  printf("\nEnter n (-1 to exit)");
	  scanf("%d",&n);
	  c=~(1<<n);
	  printf("\n ~1<<n=");
	  print_bits(c);
	  d=1<<n;
	  printf("\n 1<<n=");
	  print_bits(d);

    }while(n!=-1);

	return 0;
}