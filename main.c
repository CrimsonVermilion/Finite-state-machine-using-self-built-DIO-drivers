#include "tm4c123gh6pm.h"
#include "bits.h"
#include "DIO.h"




enum light{ white = 0 , red ,green,blue} ;



int main()
{
  enum  light current ;  
  DIOInt('F',0x1f,0xe);
  current = white;
  while(1)
  {
    current%=4;
    switch(current)
    {
    case white :
      DIOWritePin('F',1,on);
      DIOWritePin('F',2,on);
      DIOWritePin('F',3,on);
      break;
    case red:
      DIOWritePin('F',1,on);
      DIOWritePin('F',2,off);
      DIOWritePin('F',3,off);
      break;
    case green:
      DIOWritePin('F',1,off);
      DIOWritePin('F',2,off);
      DIOWritePin('F',3,on);
      break;
    case blue:
      DIOWritePin('F',1,off);
      DIOWritePin('F',2,on);
      DIOWritePin('F',3,off);
      break;
    }
    
    if( !get_bit(GPIO_PORTF_DATA_R,4))
    {
      delay(50);
      current ++;
      while(!get_bit(GPIO_PORTF_DATA_R,4));
      delay(50);
    }
    if (!get_bit(GPIO_PORTF_DATA_R,0))
    {
      delay(50);
      current --;
      if (current < 0)
      {
        current = 4;
      }
      while(!get_bit(GPIO_PORTF_DATA_R,0));
      delay(50);
    }
  }
}