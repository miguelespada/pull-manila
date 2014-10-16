pull-manila
===========

  
  #include <SPI.h>         
  #include <Ethernet.h>
  #include <EthernetUdp.h>         
  #include <OSCMessage.h>
  
  OSCMessage msg("/key_down");
  
  OSCMessage testMsg("/ping");
  
  const int buttonPin = 2;     // the number of the pushbutton pin
  
  int buttonState = 0;         // variable for reading the pushbutton status
  
  // Enter a MAC address and IP address for your controller below.
  // The IP address will be dependent on your local network:
  byte mac[] = {  
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  
  IPAddress ip(192, 168, 1, 177);
  
  unsigned int localPort = 8888;      // local port to listen on
  
  // buffers for receiving and sending data
  char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
  
  // An EthernetUDP instance to let us send and receive packets over UDP
  EthernetUDP Udp;
  
  void setup() {
    
     // initialize the LED pin as an output:
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);   
    
    // start the Ethernet and UDP:
    Ethernet.begin(mac,ip);
    Udp.begin(localPort);
  
    Serial.begin(9600);
  }
  
  void loop() {
    
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
  
    if (buttonState == HIGH) {     
      Udp.beginPacket(Udp.remoteIP(), 8080);
      msg.send(Udp); // send the bytes to the SLIP stream
      Udp.endPacket(); // mark the end of the OSC Packet
      msg.empty(); // free space occupied by message
    
      Serial.println(Udp.remoteIP());  
      delay(500);
    } 
    
    // if there's data available, read a packet
    int packetSize = Udp.parsePacket();
    if(packetSize)
    {
      Serial.print("Received packet of size ");
      Serial.println(packetSize);
      Serial.print("From ");
      IPAddress remote = Udp.remoteIP();
      for (int i =0; i < 4; i++)
      {
        Serial.print(remote[i], DEC);
        if (i < 3)
        {
          Serial.print(".");
        }
      }
      Serial.print(", port ");
      Serial.println(Udp.remotePort());
      
      Udp.beginPacket(Udp.remoteIP(), 8080);
      testMsg.send(Udp); // send the bytes to the SLIP stream
      Udp.endPacket(); // mark the end of the OSC Packet
      testMsg.empty(); // free space occupied by message
      
    }
    delay(10);
  }
