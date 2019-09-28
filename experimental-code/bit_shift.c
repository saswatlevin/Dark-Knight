#include <stdio.h>
#include <stdlib.h>

void printByte(char byte)
{
	for(char i=7;i>=0;i--)
	{   
		printf("%c",(byte &(1<<i)) ? '1':'0');
	}
	printf("\n");
}
int main()
{
	char shift[8] = {1,0,3,2,5,4,7,6};
	char inbyte[10] = {0};
	char outbyte[10] = {0};
	scanf("%s",inbyte);
	printf("%s",outbyte);
	int cursor = 0;
	while(inbyte[cursor]!='\0')
	{
		for(int i=0, selector=1; i<8; i++, selector<<=1)
		{
			char bitval = selector & inbyte[cursor];
			//printf("Loop %c: Selector = %c | outbyte = %c | bitval = ",i,selector,outbyte);
			//printByte(bitval);
			if(bitval==selector)
				outbyte[cursor] |= 1<<shift[i];
		}
		printByte(inbyte[cursor]);
		printByte(outbyte[cursor]);
		cursor++;
	}
	outbyte[cursor] = '\0';
	//printByte(inbyte);
	//printByte(outbyte);
	//printf("%s\n%s",inbyte,outbyte);
	return 0;
}