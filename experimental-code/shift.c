#include <stdio.h>
#include <stdlib.h>

unsigned char get_nth_bit(unsigned char byte,unsigned char n);
void print_bits (unsigned char byte);
unsigned char toggle_nth_bit(unsigned char byte,unsigned char n,unsigned char bitval);
unsigned char c='C';

void print_bits(unsigned char byte)
{
	for(int i=0;i<=7;++i)
	{   
		printf("%c",(byte &(1<<i)) ? '1':'0');
	}
}

unsigned char get_nth_bit(unsigned char byte,unsigned char n)
{
    unsigned char bitStatus=(byte>>n)&1;
    return bitStatus;
}


unsigned char toggle_nth_bit(unsigned char byte,unsigned char n,unsigned char bitval)
{   
    //setting a bit
    if(bitval)
    {   
        unsigned char a=get_nth_bit(byte,n);
        if(!a){
        unsigned char y=1<<n;
        printf("\nSet bit %d ",n);
        print_bits(byte);
        printf(" ^ ");
        print_bits(y);
        byte=byte ^ y;
        printf(" = ");
        print_bits(byte);
        printf("\n");
        return byte;
       }

     return byte;   
    }
    
    //clearing a bit
    else
    {   
        
        unsigned char x=~(1<<n);
        printf("\nCleared bit %d ",n);
        print_bits(byte);
        printf(" & ");
        print_bits(x);
        byte=byte & x; 
        
        printf(" = ");
        print_bits(byte);
        printf("\n");
       
        return byte;   
         
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
   
    //unsigned int n=7;
    


    //print_bits(c);
    //unsigned char bit=get_nth_bit(c,n);
    //swapping bits
    
    printf("\n In main before setting or clearing c=");
    print_bits(c);

    
    
    
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

    /*c=toggle_nth_bit(c,0,0);
    c=toggle_nth_bit(c,1,0);
    c=toggle_nth_bit(c,2,1);
    c=toggle_nth_bit(c,3,0);
    c=toggle_nth_bit(c,4,0);
    c=toggle_nth_bit(c,5,0);
    c=toggle_nth_bit(c,6,1);
    c=toggle_nth_bit(c,7,1);*/
    
    unsigned char arr[8]={7,6,5,4,3,2,1,0};
    unsigned char temp=c;
    for(int i=0;i<8;++i){
    unsigned char arr_val=arr[i];    
    unsigned char a=get_nth_bit(temp,arr_val); 
    //printf("\n arr_val= %d\t a = %d\t i = %d\t",arr_val,a,i);
   
    c=toggle_nth_bit(c,i,a);
    }
    printf("\n");
    //print_bits(c);
    return 0;
}