#include <avr/io.h>
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (9600 * 16UL))) - 1)
void USART0Init(void)
{
UBRR0H=(uint8_t)(UBRR_VALUE>>8);
UBRR0L=(uint8_t)UBRR_VALUE;
UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);//8 bit veri için
UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
}
void USART0SendByte(uint8_t u8Data)
{
while(!(UCSR0A&(1<<UDRE0))){}
UDR0 = u8Data;
}
uint8_t USART0ReceiveByte()
{
while(!(UCSR0A&(1<<RXC0))){}
return UDR0;
}
int main (void)
{
uint8_t gelen_data;
USART0Init();

USART0SendByte(gelen_data);
while(1)
{
gelen_data = USART0ReceiveByte();

USART0SendByte(gelen_data);

}
}
