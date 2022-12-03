#OS Course Project

# Build 

## RF ID 
#### Build
`make RFID`   

#### Run
`./RFID_AS_SD -q`   

#### Pipe work  

Send data to named pipe.  

`./RFID_AS_SD -q > rfid_data &`   

Receive data from named pipe   
`./Reader.sh < rfid_data`    

## Keypad 
#### Build 
`make KeyPad` . 

#### Run 
`sudo ./keypad_v8_AS_SD -q`   


----  
### Known issues  

Q: ./Bash.sh file no permission / permission denied  
A: `chmod +x Bash.sh`    
 

---

### Raspberry Pi Wireless LAN connection 

Check for available wifi networks `iwlist wlan0 scan`. If you find your network then go on.

`sudo raspi-config`  

> Navigate to <b> System Options </b>.  
> <b>Wireless LAN</b>.  
> Enter <b>SSID</b>. and <b>PSK</b> --> Your HOST Name and password.  
> <b>Reboot</b> Raspberry Pi 

Now let's check if your Raspberry has successfully connected to Wifi.  
`ping google.com`   

If it starts to receive packages then everything is ok.  
If time response is high then check for connection again or do same steps one more time.   
If it still does not work - google it.  

---

### <b>Connect your Raspberry to Visual Studio Code.</b>  

First of all, you need to get your new respberry IP.  
`ifconfig -ip respberry`   

Now search for IP.  

Then go to VS Code. You need to download and install an extension Remote SSH.  

As soon as you downloaded it you will find a new sin on the left side panel. <b>Remote Explorer</b>.  

Add new connection.  
`ssh pi@your-ip`  

Example 
`ssh pi@192.168.1.10`  

Press Enter.  
VS Code will ask for password. Enter it.  

Now wait a little bit. After sucessful connection you will be able to open folder from your Raspberry Pi.  




