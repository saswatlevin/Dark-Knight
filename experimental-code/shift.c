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
        //return byte;
    }
    
    //clearing a bit
    else
    {
        byte=byte & (~(1 << n));
        printf("\nCleared bit %d\t",n);
        print_bits(byte);
        //return byte; 
    }
     //return byte;
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
   
    //unsigned int n=7;
    


    //print_bits(c);
    //unsigned char bit=get_nth_bit(c,n);
    //swapping bits
    unsigned char c='C';
    printf("\n In main before setting or clearing c=");
    print_bits(c);

    unsigned int arr[8]={7,6,5,4,3,2,1,0};
    
    
    /*for(int i=0;i<8;++i)
    {
        unsigned int arr_val=arr[i];
        //unsigned int byte_no=arr_val/8;
        //unsigned int bit_no=arr_val%8;
        //unsigned int init_byte_no=i/8;
        //unsigned int init_bit_no=i%8;
        
        unsigned int bit_status=get_nth_bit(c,arr_val);
        toggle_nth_bit(c,i,bit_status);
        
    }*/

    //printf("\n bit %d\t of %c is=",n,c);
    //printf("\nAfter permuting bits");
    //print_bits(c);

    toggle_nth_bit(c,0,0);
    toggle_nth_bit(c,1,1);
    toggle_nth_bit(c,2,0);
    toggle_nth_bit(c,3,0);
    toggle_nth_bit(c,4,0);
    toggle_nth_bit(c,5,0);
    toggle_nth_bit(c,6,1);
    toggle_nth_bit(c,7,1);

    return 0;
}