 **KJR 3-Wire-Protocol**
 
 **The techinical aspect behind the inner working of the kjr-3-wire-protocol and why it works well!**
 - It uses electrical energy pulses (pulse of certain duration)
 - Electrical energy travels at a constant speed no matter the medium (wire) resistance is
 - This protocol is similar to morse code, it depends on the duration of the beeps
 - This works on Master / Slaves topoloy (The master will initiate the call to specific slaves and the slaves that was called will respond to the master in return)
 
 **Advantages**
 - Eliminated the distance limitations of common wire communication protocols (i.e. I2C, RS-232 (Serial), Parallel, & etc.)
 - Very easy to setup and implement
 - You can add as many slaves as you want as long as you can accept the added delays for each slaves as this protocol works on queue concept as well
 
 **Disadvantages**
 - Slow transfer as this method of detection depends on the duration of the pulses
 - Voltage drop along the wires is directly proportional to the distance, if your project will require only few hundred meters that would not be an issue, if you wanted to implement this at a larger distances, you can still make this work, just keep and maintain the voltage at the recieving end at a allowable detection threshold, you can use an external power booster
 - Electromagnetic interference from nearby location can cause crosstalks and could cause inaccurate data, to avoid this you can use the twisted wires or ideally use network cable cat 5e or cat6 or higher version.

*The flow of communication is pretty basic*
1. the MASTER initiates the request by putting the SIGNAL LINE to HIGH
2. when SIGNAL LINE went high all SLAVES listen
3. the MASTER send a string of this format "1-xxxxx" or "2-xxxx" to the MASTER LINE (the number denotes the SLAVE ID the MASTER wants to communicate with)
4. All SLAVES receives the data
5. the MASTER now will put the SIGNAL LINE to LOW, this signals all SLAVEs that they can send data now to MASTER to the SLAVE LINE.
6. Only one SLAVE will respond, That one that matches the SLAVE ID the MASTER sent  "x-" 


**Note**
- The current version has a 16 character sets only ( Dot { } 0 1 2 3 4 5 6 7 8 9 + - Comma ) feel free to add/modify the source code
- Use COMMON GROUND LINE if you will be using a separate power source for each or one of your microcontroller

 **See below sample layout connections** 
 
 <img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol/blob/master/sample_layout_connections.png" width=800 />  
 
  **Sample Transmission for two nodes configurations** 
  
 <img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/SAMPLE_TRANSMISSION.PNG" width=800 />  
 
**To get the latest updates and news, see below links**
- Facebook Group: https://www.facebook.com/groups/krakenjr
- Github: https://github.com/krakenjriot/
- Website: https://internetofthingsbuilder.com
- Website: https://krakenjriot.tech
