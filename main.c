#include"motor.h"
char ch='l';
void uart_init()
{
    UBRRH=0;
    UBRRL=51;
    UCSRC=0B10000110;
    UCSRB=0B00011000;
    UCSRA=0B00000000;
}
char char_recieve()
{
if(UCSRA&128)
    return UDR;
    else
    return 'l';
}
int main()
{
    motor_init();
    uart_init();
    DDRA=0X00;
    PORTA=0XFF;
    DDRB=0X00;
    PORTB=0XFF;
    while(1)
    {
        //line follow mode
        if(ch=='l')
        {
            if((!(PINA&(7<<0)))==0X03)  forward();
            else if((!(PINA&(7<<0)))==0X02)  left();
            else if((!(PINA&(7<<0)))==0X01)  right();
            else
            {
                stop();
  for(int i=0;i<10000;i++)
                {
                    if((!(PINA&(7<<0)))>0X03)
					goto z;
                }
                ch='s';
                goto y;
            }
            z:
            ch=char_recieve();
        }
        else
        {
            //bluetooth manual mode
            y:
            while(1)//once manual, stay manual
            {
                ch=char_recieve();
                if(ch=='w') forward();
                else if(ch=='a') left();
                else if(ch=='d') right();
                else if(ch=='s') backward();
                else stop();
            }
   }
    }
}