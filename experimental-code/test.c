#include <stdio.h>

void print_bits(char byte)
{
	for(int i=0;i<=7;++i)
	{   //Doubtful how this works
		printf("%c",(byte &(1<<i)) ? '1':'0');
	}
}

int main()
{
	unsigned char c='C',d='C';
	unsigned int n;
	printf("\nC=");
	print_bits(c);
	//printf("\nD=");
	//print_bits(d);
	do
	{
	  
	  printf("\nEnter n (-1 to exit)");
	  scanf("%d",&n);
	  c=~(1<<n);
	  printf("\n 1<<n=");
	  print_bits(c);
	  d=1<<n;
	  printf("\n 1>>n=");
	  print_bits(d);

    }while(n!=-1);

	return 0;
}