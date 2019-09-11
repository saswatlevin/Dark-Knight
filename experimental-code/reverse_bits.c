#include <stdio.h>
#include <stdlib.h>

unsigned char get_nth_bit(unsigned char byte,unsigned int n);
void print_bits (char byte);
void toggle_nth_bit(unsigned char byte,unsigned int n,unsigned int bitval);


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
   
    unsigned char c='C';//11000010 in binary
    printf("\n In main before setting or clearing c=");
    print_bits(c);
    
    
    toggle_nth_bit(c,0,0);
    toggle_nth_bit(c,1,1);
    toggle_nth_bit(c,2,0);
    toggle_nth_bit(c,3,0);
    toggle_nth_bit(c,4,0);
    toggle_nth_bit(c,5,0);
    toggle_nth_bit(c,6,1);
    toggle_nth_bit(c,7,1);
    
    //After this I expect the result to be 01000011 in binary, but it isn't
    return 0;
}