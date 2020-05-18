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
	#define SIGNAL_LINE 3 //3  
	#define MASTER_LINE 4 //4
	#define SLAVE_LINE  5 //5
	#define LINE_ID '0'

	unsigned int MAX_NODES = 2; //Total Number of Slave Nodes

	#define INTERVAL 1000 // timer for 3-wires 
	unsigned long time_t = 0;

	byte SIGNAL_LINE_STAT = 0;
	bool startRecording = false; 

	char concatenated_chars[130];  
	//const char* data_to_send_to_slave;

	bool init_t = true; // first statement get executed only once

	char cached_str[240];
      unsigned long lapse;
      char chx;

	unsigned long ii = 0; 
	
	uint8_t call_counter = 1; //slave number caller

  unsigned long count_cycle = 0;             
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
		pinMode(SIGNAL_LINE, OUTPUT);
		pinMode(MASTER_LINE, OUTPUT);
		pinMode(SLAVE_LINE, INPUT); 
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
		if((unsigned long)(millis() - time_t) > INTERVAL){
		  time_t = millis();
		  SIGNAL_LINE_STAT = 1; 
		}
		//******************************************************************** 
		
		//******************************************************************** 	
		if(SIGNAL_LINE_STAT == 1)
		{   
			
			const char * digital_output_data = "111111111111111111111111111111111111111111111111111111"; //54 Output pins of slave
			digitalWrite(SIGNAL_LINE,true);
			sprintf(concatenated_chars,"%d0,%s,", call_counter, digital_output_data);
			encode_lapse(concatenated_chars , MASTER_LINE);

   
			if(char2Int(cached_str[2]) == call_counter) 
			{          
			  call_counter++;

			  if(call_counter > MAX_NODES) 
			  {
			    call_counter = 1;     
			  }
			} 

      
      			
			//wdt_reset(); 	  
      SIGNAL_LINE_STAT = 2;
		}
		//******************************************************************** 
		
		//******************************************************************** 
		//THEN HERE!
		if(SIGNAL_LINE_STAT == 2)
		{   
			digitalWrite(SIGNAL_LINE,false);

      uint8_t c = 0, d = 0;
      unsigned long i = 0; 
      
			lapse = pulseIn(SLAVE_LINE, HIGH);    
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
					SIGNAL_LINE_STAT = 3;
					//itsforme = true;	
         					
				} else {
					//itsforme = true; 					
				}


				startRecording = false;
				ii = 0;          
			}//chx == '}' 
			//wdt_reset();    
		}//if  
		//******************************************************************** 
		
		//********************************************************************
		//THEN HERE AGAIN!
		if(SIGNAL_LINE_STAT == 3)
		{ 		 
			//you code here...
			//you code here...
			//you code here...
			//you code here...
			//you code here...
			//you code here...
			//you code here...
				
			//sample code to light the LED at pin 9
			digitalWrite(9, cached_str[2]=='0'?false:true);  

      Serial.print(F("serial_data_rcvd_from_slave["));  
      Serial.print(cached_str[2]);  
      Serial.print(F("]: "));  
      Serial.println(cached_str);  
      
      //count cycles
      //count_cycle++;
      //Serial.print(F("Cycle Counter: "));  
      //Serial.println(count_cycle); 
      
			//do not remove!
			cached_str[0] = '\0'; //erase
			SIGNAL_LINE_STAT = 0;  
			//wdt_reset();  
		}
	}//loop
	//***************************** loop ********************************     
	//***************************** loop ********************************     
	//***************************** loop ********************************     	
