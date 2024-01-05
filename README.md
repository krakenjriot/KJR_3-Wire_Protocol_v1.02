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
                   
                   
Certainly! Here's the enhanced Markdown with the additional content:


## KJR 3-Wire-Protocol 🌐

This protocol introduces a unique approach, distinct from existing implementations such as UART and SERIAL, by utilizing durations as data representation.

### Technical Overview

The KJR 3-Wire-Protocol operates on the principle of electrical energy pulses, with the following key attributes:

- Electrical energy pulses of certain durations are employed.
- Electrical energy travels at a constant speed regardless of wire resistance.
- Similar to Morse code, using a single beep to represent a single character.
- Utilizes a Master/Slaves topology, where the master initiates the call to specific slaves.

### Advantages 🚀

- **Reliable at Long Distances:** Tested at 200 meters with a transfer rate of 512 characters/second (can potentially reach up to 1024 beeps/second).
- **Overcomes Distance Limitations:** Eliminates the distance limitations of common wire communication protocols (e.g., I2C, RS-232, Parallel).
- **Easy Setup:** Very easy to set up and implement.
- **Scalable:** Add as many slaves as needed, with the flexibility to accept added delays for each slave.
- **Immune to Electromagnetic Interference:** Low-frequency transmission protocol mitigates cross-talk electromagnetic interference.

### Disadvantages ⚠️

- **Slow Transfer Rate:** The method's detection speed depends on the duration of the pulses.
- **Voltage Drop Along Wires:** Proportional to distance; mitigate by maintaining voltage at the receiving end or using an external power booster.

### Communication Flow 🔄

1. The MASTER initiates the request by setting the SIGNAL LINE to HIGH.
2. All SLAVES listen when the SIGNAL LINE is high.
3. The MASTER sends a string with the format "1,xxxxx" or "2,xxxx" to the MASTER LINE (denoting the SLAVE ID the MASTER wants to communicate with).
4. All SLAVES receive the data.
5. The MASTER sets the SIGNAL LINE to LOW, signaling SLAVES that they can send data to the MASTER via the SLAVE LINE.
6. Only one SLAVE responds, matching the SLAVE ID sent by the MASTER.

### Encoding/Decoding Method 🧾

- **Sending:** The sender places a voltage on the line, sustaining it for a duration equivalent to the required character.
- **Receiving:** The receiver listens to the line, measures the duration of the high signal, and translates it to the equivalent value.

### Note 📝

- The current version supports 17 character sets only ( . { } 0 1 2 3 4 5 6 7 8 9 + - , *). Feel free to add/modify the source code.
- Use a COMMON GROUND LINE if using a separate power source for each or one of your microcontrollers.

**GitHub Repository:** [KJR 3-Wire-Protocol](https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02) 📦

**See below sample layout connections** 

<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol/blob/master/sample_layout_connections.png" width=800 />  

**Sample Transmission for 1 master and two slave nodes @100meters Fig.2** 

<img src="https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/SAMPLE_TRANSMISSION.PNG" width=800 />  
*Fig.2*

[![Demo Transmissions](https://github.com/krakenjriot/KJR_3-Wire_Protocol_v1.02/blob/master/images/yt.PNG)](https://youtu.be/FpUw7k21g34 "Demo Transmissions")

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

**Steps Finished**


**To get the latest updates and news, see below links**
- Facebook Group: https://www.facebook.com/groups/krakenjr
- Github: https://github.com/krakenjriot/

