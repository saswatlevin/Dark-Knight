#include <stdio.h>
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

int main()
{   unsigned char a='C',b=1,n=0,x;
    printf("\n a before shifting=");
    print_bits(a);
    printf("\n b before shifting");
    print_bits(b);
    
    do{

    printf("\n Enter n");
    scanf("%hhd",&n);
    
    //a=a<<n;
    b=1<<n;
    printf("\n a=");
    print_bits(a);
    printf("\n b after shifting by %d\t bits",n);
    print_bits(b);
    x=a ^ b;

    unsigned char a=get_nth_bit(x,n);
    printf("\n x=");
    print_bits(x);
    printf("\n a =%d\t",a);
    printf("\n a bits=");
    print_bits(a);
    }while(n!=-1);
	return 0;
}