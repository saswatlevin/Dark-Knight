#include <stdio.h>
#include <stdlib.h>

unsigned char toggle_nth_bit(unsigned char byte,unsigned int n);
void print_bits (char byte);
void set_nth_bit(unsigned char byte,unsigned int n,unsigned int bitval);

 unsigned char c='C';

void print_bits(char byte)
{
	for(int i=0;i<=7;++i)
	{   //Doubtful how this works
		printf("%c",(byte &(1<<i)) ? '1':'0');
	}
}

unsigned char get_nth_bit(unsigned char byte,unsigned int n)
{
    unsigned char bitStatus=(byte>>n)&1;
    return bitStatus;
}


void toggle_nth_bit(unsigned char byte,unsigned int n,unsigned int bitval)
{   
    //setting a bit
    if(bitval)
    {
        byte=byte^(1<<n);
        printf("\nSet bit %d\t",n);
        print_bits(byte);
    }
    
    //clearing a bit
    else
    {
        byte=byte & (~(1 << n));
        printf("\nCleared bit %d\t",n);
        print_bits(byte); 
    }
} 

int main()
{
    /*unsigned char c=5,d=9;
    
    c=c<<1;
    printf("\n c<<1 =%d\t",c);
    //print_bits(c);
    d=d<<1;
    printf("\n d<<1 =%d\t",d);
    //print_bits(d);
    c=5;
    c=c>>1;
    printf("\n c>>1 =%d\t",c);
    //print_bits(c);
    d=9;
    d=d>>1;
    printf("\n d>>1 =%d\t",d);
    //print_bits(d);*/
   
    unsigned int n=7;
    //print_bits(c);
    //unsigned char bit=get_nth_bit(c,n);
    //printf("\n bit %d\t of %c is=",n,c);
    printf("\n In main before setting or clearing c=");
    print_bits(c);
    set_nth_bit(c,1,0);

    return 0;
}