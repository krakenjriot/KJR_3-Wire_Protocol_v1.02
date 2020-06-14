 /***
 *      _  ______      _    _  _______ _   _       _ ____      ___ ___ _____ 
 *     | |/ /  _ \    / \  | |/ / ____| \ | |     | |  _ \    |_ _/ _ \_   _|
 *     | ' /| |_) |  / _ \ | ' /|  _| |  \| |  _  | | |_) |    | | | | || |  
 *     | . \|  _ <  / ___ \| . \| |___| |\  | | |_| |  _ < _   | | |_| || |  
 *     |_|\_\_| \_\/_/   \_\_|\_\_____|_| \_|  \___/|_| \_(_) |___\___/ |_|  
 *     
 *                          KJR 3 WIRE PROTOCOL 
 *                       https://krakenjriot.tech/
 *                  https://internetofthingsbuilder.com/
 *                          funsideofwine@gmail.com   
 *                                        
 * MIT License
 *
 * Copyright (c) 2020 Rolly Falco Villacacan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "kjr3wire.h" 
#include <avr/boot.h>
unsigned int lapse_l;
char ch_l;

unsigned int ctous(char ch_l)
{  
  if( ch_l == '.' )      lapse_l = 50; 
  else if( ch_l == '{' ) lapse_l = 100;   
  else if( ch_l == '0' ) lapse_l = 150;   
  else if( ch_l == '1' ) lapse_l = 200;   
  else if( ch_l == '2' ) lapse_l = 250;   
  else if( ch_l == '3' ) lapse_l = 300;   
  else if( ch_l == '4' ) lapse_l = 350;   
  else if( ch_l == '5' ) lapse_l = 400;   
  else if( ch_l == '6' ) lapse_l = 450;   
  else if( ch_l == '7' ) lapse_l = 500;   
  else if( ch_l == '8' ) lapse_l = 550;   
  else if( ch_l == '9' ) lapse_l = 600;   
  else if( ch_l == '}' ) lapse_l = 650;   
  else if( ch_l == '+' ) lapse_l = 700; 
  else if( ch_l == '-' ) lapse_l = 750; 
  else if( ch_l == ',' ) lapse_l = 800; 
  else if( ch_l == '*' ) lapse_l = 850; 
  else lapse_l = 0;    
  return lapse_l;
}


void lit(uint8_t DATA_LINE, unsigned int duration)
{
  digitalWrite(DATA_LINE,HIGH);
  delayMicroseconds(duration);
  digitalWrite(DATA_LINE,LOW);  
  delay(3);
}

void encode_lapse(char concatenated_chars[240], uint8_t DATA_LINE)
{
  char arr[240];
  sprintf(arr,"%c%s%c%c",'{',concatenated_chars,'}','\0');
  unsigned int x = 0;   
  while (arr[x] != '\0')
  {      
    lit(DATA_LINE, ctous(arr[x])); 
    x++;
  }  
}


char decode_lapse(unsigned int lapse_l)
{
  if( lapse_l >=       40  && lapse_l < 89 ) ch_l = '.'; 
  else if( lapse_l >=  90  && lapse_l < 139 ) ch_l = '{';   
  else if( lapse_l >= 140  && lapse_l < 189 ) ch_l = '0'; 
  else if( lapse_l >= 190  && lapse_l < 239 ) ch_l = '1'; 
  else if( lapse_l >= 240  && lapse_l < 289 ) ch_l = '2'; 
  else if( lapse_l >= 290  && lapse_l < 339 ) ch_l = '3'; 
  else if( lapse_l >= 340  && lapse_l < 389 ) ch_l = '4';   
  else if( lapse_l >= 390  && lapse_l < 439 ) ch_l = '5'; 
  else if( lapse_l >= 440  && lapse_l < 489 ) ch_l = '6'; 
  else if( lapse_l >= 490  && lapse_l < 539 ) ch_l = '7'; 
  else if( lapse_l >= 540  && lapse_l < 589 ) ch_l = '8'; 
  else if( lapse_l >= 590  && lapse_l < 639 ) ch_l = '9'; 
  else if( lapse_l >= 640  && lapse_l < 689 ) ch_l = '}'; 
  else if( lapse_l >= 690  && lapse_l < 739 ) ch_l = '+'; 
  else if( lapse_l >= 740  && lapse_l < 789 ) ch_l = '-'; 
  else if( lapse_l >= 790  && lapse_l < 839 ) ch_l = ','; 
  else if( lapse_l >= 840  && lapse_l < 889 ) ch_l = '*'; 
  else ch_l = 'E';    
  return ch_l;
}

uint8_t char2Int(char ch){
  uint8_t bayte = (int) ch;
  uint8_t  x;  
  if(bayte == 48) x = 0;
  if(bayte == 49) x = 1;
  if(bayte == 50) x = 2;
  if(bayte == 51) x = 3;
  if(bayte == 52) x = 4;  
  return x;
}