

#define LATCH_PIN 4
#define CLK_PIN   7
#define DATA_PIN  8


 void SendDataToSegment(byte Segment_no, byte hexValue);
 
const byte C_HEX  = 0xC6;
const byte TWO_HEX  = 0xA4;
const byte P_HEX  = 0x8C;
const byte A_HEX = 0x88;
const byte H_HEX = 0x89;
const byte O_HEX = 0xC0;
const byte J_HEX = 0xE1;
const byte K_HEX = 0x8F;
const byte S_HEX = 0x92;
const byte I_HEX = 0xCF;

byte select_seg1 = 0xF1 ;
byte select_seg2 = 0xF2 ;
byte select_seg3 = 0xF4 ;
byte select_seg4 = 0xF8 ;





const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};


void setup ()
{
/* All the pins like latch, clock and data pins are used as output */
  pinMode(LATCH_PIN,OUTPUT);
  pinMode(CLK_PIN,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
 


}

/* Main program */
void loop()
{
/* Update the display with the current counter value */
  for(int i = 1; i <= 15;i++)
  {
    
 
    
    if(i == 2)
    {
      for(int j = 1;j < 1000; j++)
      {
        SendDataToSegment(select_seg1 , A_HEX);
        
        SendDataToSegment(select_seg2 , H_HEX);
          
        SendDataToSegment(select_seg3 , O_HEX);
          
        SendDataToSegment(select_seg4 , J_HEX);
      }  
    }
    if(i == 3)
    {
        for(int j = 1;j < 1000; j++)
      {
        SendDataToSegment(select_seg1 , H_HEX);
        SendDataToSegment(select_seg2 , O_HEX);
        SendDataToSegment(select_seg3 , J_HEX);
      }  
        
      
    }
     if(i == 4)
    {
        for(int j = 1;j < 1000; j++)
      {
        
        SendDataToSegment(select_seg1 , O_HEX);
        SendDataToSegment(select_seg2 , J_HEX);
        SendDataToSegment(select_seg4,  J_HEX);
      }  
        
      
    }   

         if(i == 5)
    {
        for(int j = 1;j < 1000; j++)
      {
        
        
        SendDataToSegment(select_seg1 , J_HEX);
        SendDataToSegment(select_seg3,  J_HEX);
        SendDataToSegment(select_seg4,  S_HEX);
      }  
        
      
    }
         if(i == 6)
    {
        for(int j = 1;j < 1000; j++)
      {
        
        SendDataToSegment(select_seg2,  J_HEX);
        SendDataToSegment(select_seg3,  S_HEX);
        SendDataToSegment(select_seg4, I_HEX);
      }  
        
      
    }    
           if(i == 6)
    {
        for(int j = 1;j < 1000; j++)
      {
        
        SendDataToSegment(select_seg1,  J_HEX);
        SendDataToSegment(select_seg2,  S_HEX);
        SendDataToSegment(select_seg3, I_HEX);
      }  
        
      
    } 
    
  }
   
}

 
void SendDataToSegment(byte Segment_no, byte hexValue)
{
  /* Make Latch pin Low */
  digitalWrite(LATCH_PIN,LOW);
  /* Transfer Segmenent data */
  shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, hexValue);
    /* Transfer Segmenent Number  */
  shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, Segment_no );
    /* Make Latch pin High so the data appear on Latch parallel pins */
  digitalWrite(LATCH_PIN,HIGH);
}
