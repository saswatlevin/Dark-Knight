#include <stdio.h>
#include <stdlib.h>

unsigned char get_nth_bit(unsigned char byte,unsigned char n);
void print_bits (unsigned char byte);
unsigned char toggle_nth_bit(unsigned char byte,unsigned char n,unsigned char bitval);


void print_bits(unsigned char byte)
{
    for(unsigned char i=0;i<=7;++i)
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
    unsigned char a;
    if(bitval)
    {  
        unsigned char t=byte;
        
        //printf("\n n= %d\n",n);
        unsigned char y=1<<n;
        //printf("y=");
        //print_bits(y);
        //printf("^");
        
        //print_bits(t);
        //printf("=");
        a=y^t;
        //print_bits(a);
        unsigned char g=get_nth_bit(a,n);
        //printf("\n g= %d ",g);
        //printf("\n");

       
        if(g!=0)
        {    
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
       //else
       //{
          //;//printf("\n a=%d\t",a);
       //}

     return byte;   
    }
    
    //clearing a bit
    else
    {   
       //printf("\n a in else");
       //print_bits(a);
       //printf("\n bitval in else");
       //print_bits(bitval);
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
   
    unsigned char c='C';    
    printf("\n In main before setting or clearing c=");
    print_bits(c);
    unsigned char arr[8]={5,7,1,3,4,2,0,6};

    unsigned char temp=c;
    for(unsigned char i=0;i<8;++i){
    unsigned char arr_val=arr[i];    
    unsigned char x=get_nth_bit(temp,arr_val); 
    //printf("\n arr_val= %d\t x = %d\t i = %d\t",arr_val,x,i);
   
    c=toggle_nth_bit(c,i,x);
    }
    printf("\n");
    print_bits(c);
    return 0;
}