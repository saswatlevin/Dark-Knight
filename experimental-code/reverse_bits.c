#include <stdio.h>
#include <stdlib.h>

char get_nth_bit(char byte,char n);
void print_bits (char byte);
char toggle_nth_bit(char byte,char n,char bitval);


void print_bits(char byte)
{
    for(char i=7;i>=0;--i)
    {   
        printf("%c",(byte &(1<<i)) ? '1':'0');
    }
}

char get_nth_bit(char byte, char n)
{
    char bitStatus=(byte>>n)&1;

    return bitStatus;
}


char toggle_nth_bit(char byte,char n,char bitval)
{   
    //setting a bit
    char a;
    if(bitval)
    {  
        char t=byte;
        
        //printf("\n n= %d\n",n);
        char y=1<<n;
        //printf("y");
        print_bits(y);
        printf("^");
        //printf("t");
        print_bits(t);
        printf("=");
        a=y^t;
        print_bits(a);
        char g=get_nth_bit(a,n);
        printf("\n g= %d ",g);
        //printf("\n g bits =");
        //print_bits(g);
        //printf("\n");
        //printf("\n");

       
        if(g!=0)
        {    
        //printf("\nSet bit %d ",n);
        //print_bits(byte);
        
        //printf(" ^ ");
        //print_bits(y);
        byte=byte ^ y;
        
        //printf(" = ");
        //print_bits(byte);

        //printf("\n");
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
        char x=~(1<<n);
        printf("\nCleared bit %d ",n);
        
        //print_bits(byte);
        //printf(" & ");
        //print_bits(x);
        byte=byte & x; 
        
        //printf(" = ");
        //print_bits(byte);
        //printf("\n");
       
        return byte;   
         
    }
     
} 

int main()
{
   
    char c='a';    
    printf("\n In main before setting or clearing c=");
    print_bits(c);
    printf("\n");
    char arr[8]={7,6,5,4,3,2,1,0};

    char temp=c;
    for(char i=0;i<8;++i){
    char arr_val=arr[i];    
    char x=get_nth_bit(temp,arr_val); 
    //printf("\n arr_val= %d\t x = %d\t i = %d\t",arr_val,x,i);
   
    c=toggle_nth_bit(c,i,x);
    }
    printf("\n");
    print_bits(c);
    return 0;
}