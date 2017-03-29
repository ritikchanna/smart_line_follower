#include<avr/io.h>
 void forward()
{
    PORTC&=~(1<<0);
    PORTC|=(1<<1);
    PORTC&=~(1<<2);
    PORTC|=(1<<3);
}
void left()
{
    PORTC&=~(1<<1);
    PORTC|=(1<<0);
    PORTC&=~(1<<2);
    PORTC|=(1<<3);
}
void right()
{
    PORTC&=~(1<<0);
    PORTC|=(1<<1);
    PORTC&=~(1<<3);
PORTC|=(1<<2);
}
void backward()
{
	PORTC|=(1<<0);
	PORTC&=~(1<<1);
	PORTC|=(1<<2);
	PORTC&=~(1<<3);
}
void stop()
{
    PORTC&=~(1<<0);
    PORTC&=~(1<<1);
    PORTC&=~(1<<2);
    PORTC&=~(1<<3);
  
}
void motor_init()
{
    DDRC=0B00001111;
}