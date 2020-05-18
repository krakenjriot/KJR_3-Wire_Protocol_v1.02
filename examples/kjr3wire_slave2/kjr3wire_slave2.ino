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
  //#include <avr/wdt.h>
  #include <kjr3wire.h>
  #define SIGNAL_LINE 6 //3  
  #define MASTER_LINE 7 //4
  #define SLAVE_LINE  8 //5
  #define LINE_ID '2'

	const char * analog_input_data;
	const char * digital_input_data;
	const char * health_data;

	uint8_t call_counter = 1; //slave number caller
	
	char concatenated_chars[240];  
	char cached_str[240];    
    char chx;	

	bool init_t = true; // first statement get executed only once
	bool startRecording = false; 
	bool itsforme = false;
	bool goto_next = false;
	bool SIGNAL_LINE_STAT = false;	
	
	unsigned long lapse;
	unsigned long ii = 0; 	
	
  //***************************** setup ********************************     
  //***************************** setup ********************************     
  //***************************** setup ********************************     
  //***************************** setup ********************************  
  //   
  void setup() 
  {
  //********************************************************************
    //wdt_enable(WDTO_8S);  
  //********************************************************************   

  //********************************************************************
    Serial.begin(9600);      
    //Serial.begin(115200);  
    while (!Serial) 
    {
      ; // wait for serial port to initialize
    }
  //********************************************************************       
    pinMode(SIGNAL_LINE, INPUT);
    pinMode(MASTER_LINE, INPUT);
    pinMode(SLAVE_LINE, OUTPUT);   
    pinMode(9, OUTPUT); 
  //********************************************************************   

  //********************************************************************     
  }//end setup
  //***************************** setup ********************************     
  //***************************** setup ********************************     
  //***************************** setup ********************************   


  
  //***************************** loop ********************************     
  //***************************** loop ********************************     
  //***************************** loop ********************************     
  void loop() 
  {
    //wdt_reset();     
    //********************************************************************        
    
    //********************************************************************        
    //ONE TIME RUN ONLY
    if(init_t)
    {
      //initialized your code here
      //initialized your code here
      //initialized your code here
      //initialized your code here
      //initialized your code here
      
      init_t = false;        
      Serial.println(F("initialization(success!)"));                          
    }  


    //TIMER TRIGGER
    //******************************************************************** 
    SIGNAL_LINE_STAT = digitalRead(SIGNAL_LINE);
    //******************************************************************** 
    
    //********************************************************************  
    if(!SIGNAL_LINE_STAT)
    {   
      if(itsforme)
      {
        analog_input_data = "123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45*123.45"; //16 sensors serial data (input analog)
        digital_input_data = "123456111111111111111111111111111111111111111111111111"; //54 pins (input digital)
        health_data = "200.50,212.89"; // temperature and humidity
        
        sprintf(concatenated_chars,"0%c,%s,%s,%s", LINE_ID, health_data, digital_input_data, analog_input_data);
        encode_lapse(concatenated_chars , SLAVE_LINE);
        //wdt_reset();
        itsforme = false;   
      }
    }
    //******************************************************************** 
    
    //******************************************************************** 
    //THEN HERE!
    if(SIGNAL_LINE_STAT)
    { 
      lapse = pulseIn(MASTER_LINE, HIGH);    
      chx = decode_lapse(lapse);
      //Serial.println(chx);  
      if(chx == '{')
      {
         startRecording = true;
      } 
         
      if(startRecording) 
      {
        cached_str[ii] = chx; 
        ii++; 
      } 
         
      uint8_t c = 0, d = 0;
      unsigned long i = 0;  
                
      if(chx == '}')
      {          
        cached_str[ii] = '\0'; //terminated the string char array   
        
        c = 0;
        for(i=0;cached_str[i];i++)  
        {
          if(cached_str[i]=='{')
          { 
            c++; 
          }
        }
        
        d = 0;
        for(i=0;cached_str[i];i++)  
        {
          if(cached_str[i]=='E')
          { 
            d++; 
          }
        }          
        
        if(c == 1 && d == 0)
        { 
          if(cached_str[1] == LINE_ID){
            itsforme = true; 
            goto_next = true;   
           
            pinMode(SLAVE_LINE, OUTPUT);         
          }else{
            itsforme = false; 
            pinMode(SLAVE_LINE, INPUT);
            //goto_next = true;              
          }
           
        }
        //cached_str[0] = '\0';
        startRecording = false;
        ii = 0;          
      }//chx == '}' 
      //wdt_reset();    
    }//if  
    //******************************************************************** 
    
    //********************************************************************
    //THEN HERE AGAIN!
    if(goto_next)
    {      
      //you code here...
      //you code here...
      //you code here...
      //you code here...
      //you code here...
      //you code here...
      //you code here...
        
      //sample code
      digitalWrite(9, cached_str[2]=='0'?false:true);  

      
      Serial.print(F("serial_data_rcvd_from_master: "));  
      Serial.println(cached_str); 
      
      //count cycles
      //count_cycle++;
      //Serial.print(F("Cycle Counter: "));  
      //Serial.println(count_cycle); 
       
      //do not remove!
      cached_str[0] = '\0'; // erase content      
      goto_next = false;
      //wdt_reset();  
    }
  }//loop
  //***************************** loop ********************************     
  //***************************** loop ********************************     
  //***************************** loop ********************************       
