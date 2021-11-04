#include <MD_MAX72xx.h>
#include <SPI.h>

//#define  DEBUG  1

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW//FC16_HW
#define MAX_DEVICES  4

#define CLK_PIN   13
#define DATA_PIN  11
//kon device active korbo er output dibe
#define CS_PIN    10  // or SS///

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
#define  DELAYTIME  100  // in milliseconds
void scrollleft(char p[]) ///welcome to MBSTU
{
  int charWidth;
  uint8_t buffer_arr[COL_SIZE];
  mx.clear();
  int j = 0;
  while (p[j] != '\0')
  {

    charWidth = mx.getChar(p[j], sizeof(buffer_arr) / sizeof(buffer_arr[0]) , buffer_arr);
    ///To set every column of a character
    for (int i = 0; i < charWidth; i++)
    {
      mx.transform(MD_MAX72XX::TSL);
      mx.setColumn(0, buffer_arr[i]);
      delay(150);
    }
    ///To create space berween characters
    mx.transform(MD_MAX72XX::TSL);
    delay(DELAYTIME);
    j++;
  }

}
void scroll_bangla_text(uint8_t char_arr[], int char_column, bool flag)
{
  int width = char_column, i;
  for (i = 0; i < width; i++)
  {
    mx.transform(MD_MAX72XX::TSL);
    mx.setColumn(0, char_arr[i]);
    delay(DELAYTIME);
  }
  ///If space needed
  if (flag == 1) mx.transform(MD_MAX72XX::TSL);
  delay(DELAYTIME);
}

/*
 *  0b00000010,
    0b00010010,
    0b00101010,
    0b01000110,
    0b11111110,
    0b00000110,
    0b00101010,
    0b00010010
 */

void myName(uint8_t char_arr[],int charWidth){

   mx.wraparound(MD_MAX72XX::ON);

  int width =charWidth;

  for(int i=0;i<width;i++){
    
    mx.transform(MD_MAX72XX::TSR);
    mx.setColumn(31,char_arr[i]);
    delay(DELAYTIME);
    
  }

  mx.transform(MD_MAX72XX::TSR);
  delay(DELAYTIME);
}



void nameDesign(){


  uint8_t s[COL_SIZE]={

    0b01001111,
    0b01001001,
    0b01001001,
    0b01001001,
    0b1001001,
    0b01001001,
    0b01001001,
    0b01111001
    
  };

  uint8_t h[COL_SIZE]={
    0b11111111,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b11111111
  };

  uint8_t a[COL_SIZE]={
    0b00000000,
    0b01111111,
    0b00001001,
    0b00001001,
    0b00001001,
    0b00001001,
    0b01111111,
    0b00000000
  };
  
   mx.clear();
   myName(s,COL_SIZE);
   myName(h,COL_SIZE);
   myName(a,COL_SIZE);
  
}

 
  











void ScrollText()
// Display text and animate scrolling using auto wraparound of the buffer
{
  mx.clear();
  mx.wraparound(MD_MAX72XX::ON);
  mx.setChar(30, 'H');
  mx.setChar(24, 'E');
  mx.setChar(18, 'L');
  mx.setChar(12, 'L');
  mx.setChar(6, 'O');

  for (uint16_t i = 0; i < 41; i++)
  {
    mx.transform(MD_MAX72XX::TSL);
    delay(DELAYTIME );
  }
  for (uint16_t i = 0; i < 41; i++)
  {
    mx.transform(MD_MAX72XX::TSR);
    delay(DELAYTIME );
  }
  for (uint8_t i = 0; i < 20; i++)
  {
    mx.transform(MD_MAX72XX::TSU);
    delay(DELAYTIME );
  }
  for (uint8_t i = 0; i < 20; i++)
  {
    mx.transform(MD_MAX72XX::TSD);
    delay(DELAYTIME );
  }

  mx.wraparound(MD_MAX72XX::OFF);
}

void printtext()
{
  mx.clear();
  ///FOR PRINT IN THE DISPLAY
  mx.setChar(31, 'T');
  mx.setChar(25, 'h');
  mx.setChar(20, 'a');
  mx.setChar(15, 'n');
  mx.setChar(10, 'k');
  delay(1000);
  mx.clear();
  mx.setChar(25, 'Y');
  mx.setChar(20, 'o');
  mx.setChar(15, 'u');
  delay(1000);///30 ms
}
void Bangla_text()
{
  uint8_t ka[COL_SIZE] =
  {
    0b00000010,
    0b00010010,
    0b00101010,
    0b01000110,
    0b11111110,
    0b00000110,
    0b00101010,
    0b00010010

  };
  uint8_t kha[COL_SIZE] =
  {
    0b10001100,
    0b01010010,
    0b01101000,
    0b01011100,
    0b01000000,
    0b01000000,
    0b11111110,
    0b00000010
  };
  uint8_t ga[COL_SIZE] =
  {
    0b00000000,
    0b00001100,
    0b01001010,
    0b00110010,
    0b00000010,
    0b00000100,
    0b11111110,
    0b00000010

  };
  uint8_t gha[COL_SIZE] =
  {
    0b00000000,
    0b10001010,
    0b11010110,
    0b10110010,
    0b10000010,
    0b10000010,
    0b11111110,
    0b00000010

  };
  uint8_t uma[COL_SIZE] =
  {
    0b00000000,
    0b00111100,
    0b01000001,
    0b10000010,
    0b10011110,
    0b10100110,
    0b01100000,
    0b00000000
  };
  uint8_t cha[COL_SIZE] =
  {
    0b00000010,
    0b00000010,
    0b00000010,
    0b01111110,
    0b10010010,
    0b10010010,
    0b01100010,
    0b00000010
  };
  uint8_t csha[COL_SIZE - 2] =
  {
    0b00000010,
    0b01111110,
    0b01001010,
    0b10111010,
    0b11110010,
    0b10000010
  };
  uint8_t ja[COL_SIZE] =
  {
    0b00111010,
    0b01000010,
    0b01011110,
    0b01011010,
    0b00111010,
    0b00001010,
    0b00111010,
    0b01000000
  };
  uint8_t jha[COL_SIZE] =
  {
    0b00000010,
    0b00010010,
    0b00101010,
    0b01000110,
    0b11111110,
    0b00100000,
    0b01111110,
    0b00000010
  };
  uint8_t nio1[COL_SIZE] =
  {
    0b01000000,
    0b10000000,
    0b10000000,
    0b01001100,
    0b00100010,
    0b00100010,
    0b01000010,
    0b11111100
  };
  uint8_t nio2[COL_SIZE - 5] =
  {
    0b00100010,
    0b00101010,
    0b00010100
  };
  uint8_t da[COL_SIZE] =
  {
    0b00111010,
    0b01000010,
    0b10000010,
    0b10011110,
    0b10010010,
    0b01001010,
    0b00110010,
    0b00000010
  };

  uint8_t murdhonno[COL_SIZE] =
  {
    0b00000000,
    0b00001100,
    0b00010010,
    0b00011010,
    0b00000010,
    0b00000100,
    0b11111110,
    0b00000010

  };
  uint8_t ta[COL_SIZE] =
  {
    0b00000000,
    0b00111010,
    0b01000010,
    0b10000010,
    0b10011010,
    0b10000110,
    0b01000110,
    0b00111010



  };
  uint8_t tha[COL_SIZE] =
  {
    0b00000000,
    0b11001100,
    0b10100010,
    0b10011110,
    0b10000000,
    0b10000000,
    0b11111110,
    0b00000010

  };
  uint8_t do_[COL_SIZE] =
  {
    0b00000000,
    0b00000010,
    0b00000010,
    0b00111110,
    0b00010010,
    0b00001010,
    0b11111010,
    0b00000010

  };
  uint8_t dho[COL_SIZE - 3] =
  {
    0b00010110,
    0b00101001,
    0b01000100,
    0b11111110,
    0b00000010
  };

  uint8_t dontonno[COL_SIZE] =
  {
    0b00000000,
    0b01100010,
    0b01010010,
    0b00010010,
    0b00100010,
    0b01000010,
    0b11111110,
    0b00000010

  };
  uint8_t pa[COL_SIZE] =
  {
    0b00001000,
    0b00101100,
    0b00110010,
    0b00100010,
    0b00010010,
    0b00001100,
    0b11111110,
    0b00000010
  };
  uint8_t pha1[COL_SIZE] =
  {
    0b00000010,
    0b10000110,
    0b11001010,
    0b10110010,
    0b10000010,
    0b10000010,
    0b11111010,
    0b00000110
  };
  uint8_t pha2[COL_SIZE - 5] =
  {
    0b00010110,
    0b00001010
  };
  uint8_t ba[COL_SIZE] =
  {
    0b00000000,
    0b00000010,
    0b00010010,
    0b00101010,
    0b01000110,
    0b11111110,
    0b00000010,
    0b00000010

  };
  uint8_t bha[COL_SIZE] =
  {
    0b00111010,
    0b01000010,
    0b10000010,
    0b10011010,
    0b10100110,
    0b10101110,
    0b10100010,
    0b01110010
  };
  uint8_t mo[COL_SIZE] =
  {
    0b00000000,
    0b01011010,
    0b10100110,
    0b11100010,
    0b00100010,
    0b01000010,
    0b11111110,
    0b00000010
  };
  uint8_t ontojo[COL_SIZE] =
  {
    0b10000010,
    0b11000110,
    0b10101010,
    0b10010010,
    0b10000010,
    0b10000010,
    0b11111110,
    0b00000010

  };
  uint8_t ra[COL_SIZE] =
  {
    0b00000000,
    0b00000010,
    0b00010010,
    0b10101010,
    0b01000110,
    0b11111110,
    0b00000010,
    0b00000010

  };
  uint8_t lo[COL_SIZE] =
  {
    0b01100010,
    0b10010010,
    0b00010010,
    0b01100010,
    0b00010010,
    0b00010010,
    0b00100010,
    0b11111110

  };
  uint8_t talobosso[COL_SIZE] =
  {
    0b00010010,
    0b00010010,
    0b00001100,
    0b00010010,
    0b00010010,
    0b00000100,
    0b11111110,
    0b00000010

  };
  uint8_t murdhonnosso[COL_SIZE] =
  {
    0b10000010,
    0b11000110,
    0b10101010,
    0b10010010,
    0b10010010,
    0b10010010,
    0b11111110,
    0b00000010

  };
  uint8_t dontosso[COL_SIZE] =
  {
    0b00000000,
    0b10000010,
    0b01000110,
    0b00111010,
    0b00100010,
    0b01000010,
    0b11111110,
    0b00000010

  };
  uint8_t ho[COL_SIZE] =
  {
    0b00000000,
    0b00000010,
    0b10011010,
    0b11000110,
    0b10100110,
    0b10011010,
    0b10000010,
    0b00000010

  };
  uint8_t do_ro[COL_SIZE] =
  {
    0b00000010,
    0b00111010,
    0b01000010,
    0b11011110,
    0b01010010,
    0b01001010,
    0b00110010,
    0b00000010

  };
  uint8_t dho_ro[COL_SIZE] =
  {
    0b00000010,
    0b00000010,
    0b00000010,
    0b00111110,
    0b11000010,
    0b01010010,
    0b00110010,
    0b00000010

  };
  uint8_t ontoyo[COL_SIZE] =
  {
    0b00000010,
    0b01000110,
    0b01101010,
    0b01010010,
    0b11000010,
    0b01000010,
    0b01111110,
    0b00000010

  };
  uint8_t khonrotto[COL_SIZE - 1] =
  {
    0b00001100,
    0b00010110,
    0b00101010,
    0b00101010,
    0b00100100,
    0b01000000,
    0b10000000
  };
  uint8_t onuskar[COL_SIZE - 4] =
  {
    0b00010100,
    0b00101010,
    0b01001010,
    0b10000100

  };
  uint8_t bisorgo[COL_SIZE - 5] =
  {
    0b11101110,
    0b10101010,
    0b11101110
  };
  uint8_t chondrobindu[COL_SIZE - 2] =
  {
    0b00111000,
    0b01000000,
    0b01001100,
    0b01001100,
    0b01000000,
    0b00111000
  };
  mx.clear();

  ///To send every character to print in the
  ///8X32 Matrix block
  scroll_bangla_text(ka, COL_SIZE, 1);
  scroll_bangla_text(kha, COL_SIZE, 1);
  scroll_bangla_text(ga, COL_SIZE, 1);
  scroll_bangla_text(gha, COL_SIZE, 1);
  scroll_bangla_text(uma, COL_SIZE, 1);
  scroll_bangla_text(cha, COL_SIZE, 1);
  scroll_bangla_text(csha, COL_SIZE - 2, 1);
  scroll_bangla_text(ja, COL_SIZE, 1);
  scroll_bangla_text(jha, COL_SIZE, 1);
  scroll_bangla_text(nio1, COL_SIZE, 0);
  scroll_bangla_text(nio2, COL_SIZE - 5, 1);
  scroll_bangla_text(da, COL_SIZE, 1);
  scroll_bangla_text(murdhonno, COL_SIZE , 1);
  scroll_bangla_text(ta, COL_SIZE, 1);
  scroll_bangla_text(tha, COL_SIZE , 1);
  scroll_bangla_text(do_, COL_SIZE , 1);
  scroll_bangla_text(dho, COL_SIZE - 3, 0);
  scroll_bangla_text(dontonno, COL_SIZE , 1);
  scroll_bangla_text(pa, COL_SIZE , 1);
  scroll_bangla_text(pha1, COL_SIZE, 0);
  scroll_bangla_text(pha2, COL_SIZE - 6, 1);
  scroll_bangla_text(ba, COL_SIZE, 1);
  scroll_bangla_text(bha, COL_SIZE, 1);
  scroll_bangla_text(mo, COL_SIZE, 1);
  scroll_bangla_text(ontojo, COL_SIZE, 1);
  scroll_bangla_text(ra, COL_SIZE, 1);
  scroll_bangla_text(lo, COL_SIZE, 1);
  scroll_bangla_text(talobosso, COL_SIZE, 1);
  scroll_bangla_text(murdhonnosso, COL_SIZE, 1);
  scroll_bangla_text(dontosso, COL_SIZE, 1);
  scroll_bangla_text(ho, COL_SIZE, 1);
  scroll_bangla_text(do_ro, COL_SIZE, 1);
  scroll_bangla_text(dho_ro, COL_SIZE, 1);
  scroll_bangla_text(ontoyo, COL_SIZE, 1);
  scroll_bangla_text(khonrotto, COL_SIZE - 1, 1);
  scroll_bangla_text(onuskar, COL_SIZE - 4, 1);
  scroll_bangla_text(bisorgo, COL_SIZE - 5, 1);
  scroll_bangla_text(chondrobindu, COL_SIZE - 2, 1);


}
void setup()
{
  ///Initialize the object data. This needs to be called during setup() to initialize new data for the class that cannot be done during the object creation.
  mx.begin();
}
void loop()
{

  char a[50] = {"Welcome TO MBSTU"};
  //scrollleft(a);
  //  ScrollText();
  //Bangla_text();
  //printtext(); 
 // nameDesign();

}
