       _  ______      _    _  _______ _   _       _ ____      ___ ___ _____ 
      | |/ /  _ \    / \  | |/ / ____| \ | |     | |  _ \    |_ _/ _ \_   _|
      | ' /| |_) |  / _ \ | ' /|  _| |  \| |  _  | | |_) |    | | | | || |  
      | . \|  _ <  / ___ \| . \| |___| |\  | | |_| |  _ < _   | | |_| || |  
      |_|\_\_| \_\/_/   \_\_|\_\_____|_| \_|  \___/|_| \_(_) |___\___/ |_|  
      
                           KJR 3 WIRE PROTOCOL 
                        https://krakenjriot.tech/
                   https://internetofthingsbuilder.com/
                           funsideofwine@gmail.com                                            
                                 MIT License
                 Created/Developed By Rolly Falco Villacacan
                   
                   
 **This protocol is unique, unlike any other currently implemented protocols (UARTS,SERIAL etc.) that uses BITs, The 3-Wire-Protocol is the only protocol that uses durations as data representation**
 
 **KJR 3-Wire-Protocol**
 
 **The techinical aspect behind the inner working of the kjr-3-wire-protocol and why it works well!**
 - It uses electrical energy pulses (pulse of certain duration)
 - Electrical energy travels at a constant speed no matter the medium (wire) resistance is
 - This protocol is similar to morse code, but using only a single beep to represent a single character
 - This works on Master / Slaves topoloy (The master will initiate the call to specific slaves and the slaves that was called will respond to the master in response)
 
 **Advantages**
 - Reliable even at long distance (tested at 200meters transfer rate of 512 characters/second (512 beeps/sec) (Est. it can reach even upto 1024 beeps/sec)
 - Eliminated the distance limitations of common wire communication protocols (i.e. I2C, RS-232 (Serial), Parallel, & etc.)
 - Very easy to setup and implement
 - You can add as many slaves as you want as long as you can accept the added delays for each slaves as this protocol works on queue concept as well
 - Immune to cross talk electromagnetic interference since its using low frequency transmission protocol
 
 **Disadvantages**
 - Slow transfer as this method of detection depends on the duration of the pulses
 - Voltage drop along the wires is directly proportional to the distance, if your project will require only few hundred meters that would not be an issue, if you wanted to implement this at a larger distances, you can still make this work, just keep and maintain the voltage at the recieving end at a allowable detection threshold, you can use an external power booster

*The flow of communication is pretty basic*
1. the MASTER initiates the request by putting the SIGNAL LINE to HIGH
2. when SIGNAL LINE went high all SLAVES listen
3. the MASTER send a string of this format "1,xxxxx" or "2,xxxx" to the MASTER LINE (the number denotes the SLAVE ID the MASTER wants to communicate with)
4. All SLAVES receives the data
5. the MASTER now will put the SIGNAL LINE to LOW, this signals all SLAVEs that they can send data now to MASTER to the SLAVE LINE.
6. Only one SLAVE will respond, That one that matches the SLAVE ID the MASTER sent  "x-" 

*Encoding/Decoding Method*
1. (SENDING) The sender will place a voltage on the line, sustaining it for a duration equivalent to the character required, 
- Ex. if SLAVE A need to send a value of "1", the SLAVE will place the LINE to HIGH for a duration of 200 microseconds ( 200us is equivalent to a value of "1" based on the 3wire protocol library)
2. (RECIEVING) The reciever is listening to the line, if the line went HIGH it will measure the duration how long it went HIGH and based on the duration measured it translate it to the equivalent value.
- Ex. MASTER listen to the LINE, and capture a pulse sustained for a duration of 250 microseconds, translating the 250us is equivalent to value of "2" based on the 3wire protocol library.

**Note**
- The current version has a 17 character sets only ( . { } 0 1 2 3 4 5 6 7 8 9 + - , *) feel free to add/modify the source code
- Use COMMON GROUND LINE if you will be using a separate power source for each or one of your microcontroller

 **See below sample layout connections** 
 
 <img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol/blob/master/sample_layout_connections.png" width=800 />  
 
  **Sample Transmission for 1 master and two slave nodes @100meters Fig.2** 
  
 <img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/SAMPLE_TRANSMISSION.PNG" width=800 />  
 Fig.2
</br>
</br>


[![Demo Transmissions](https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/yt.PNG)](https://youtu.be/FpUw7k21g34 "Demo Transmissions")
</br>
</br>

**How to add "kjr3wire" repository as Arduino Library?**
Follow below steps..
- Download zip copy of the repository 
*Clone or Download --> click Download ZIP
<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/image1.PNG" width=800 /> 


- Save the file to your Arduino Library or (any folder will work just don't forget where it is) 
*Click Save button to complete the download process
<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/image2.PNG" width=800 /> 

- Open Arduino IDE
*Click Sketch --> Include Library --> Add ZIP Library --> find the downloaded file
<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/image3.PNG" width=800 /> 

- In the Arduino IDE
*Find the downloaded file, select and finally click Open to complete the import
<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/image4.PNG" width=800 /> 

- In the Arduino IDE (COMPLETED!)
To Test your first kjr3wire sketch, 
*Click File --> Example --> and scroll below --> find the newly import library --> select the sample and compile
<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/image5.PNG" width=800 /> 

**Steps Finished


**To get the latest updates and news, see below links**
- Facebook Group: https://www.facebook.com/groups/krakenjr
- Github: https://github.com/krakenjriot/
- Website: https://internetofthingsbuilder.com
- Website: https://krakenjriot.tech
