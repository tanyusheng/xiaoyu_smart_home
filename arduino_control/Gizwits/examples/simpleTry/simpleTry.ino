/**
************************************************************
* @file         Gizwits + ArduinoUnoR3 Library 
* @brief        Datapoints handle , Gizwits Process
* @author       Gizwits
* @date         2017-08-01
* @version      V03030000
* @copyright    Gizwits
* 
* @note         机智云.只为智能硬件而生
*               Gizwits Smart Cloud  for Smart Products
*               链接|增值ֵ|开放|中立|安全|自有|自由|生态
*               www.gizwits.com
*
***********************************************************/
#include <Gizwits.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(A2, A3); // A2 -> RX, A3 -> TX

Gizwits myGizwits;

/**
* Serial Init , Gizwits Init  
* @param none
* @return none
*/
void setup() {
  // put your setup code here, to run once:

  mySerial.begin(115200);

  myGizwits.begin();

  mySerial.println("GoKit init  OK \n");

}

/**
* Arduino loop 
* @param none
* @return none
*/
void loop() {  
  
  //Configure network
  //if(XXX) //Trigger Condition
  //myGizwits.setBindMode(0x02);  //0x01:Enter AP Mode;0x02:Enter Airlink Mode
    /*
  unsigned long varW_wendu = 0;//Add Sensor Data Collection
  myGizwits.write(VALUE_wendu, varW_wendu);
  unsigned long varW_shidu = 0;//Add Sensor Data Collection
  myGizwits.write(VALUE_shidu, varW_shidu);


  bool varR_LED_OnOff = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_OnOff))
  {
    myGizwits.read(EVENT_LED_OnOff,&varR_LED_OnOff);//Address for storing data
    mySerial.println(F("EVENT_LED_OnOff"));
    mySerial.println(varR_LED_OnOff,DEC);

  }
  bool varR_chuang = 0;
  if(myGizwits.hasBeenSet(EVENT_chuang))
  {
    myGizwits.read(EVENT_chuang,&varR_chuang);//Address for storing data
    mySerial.println(F("EVENT_chuang"));
    mySerial.println(varR_chuang,DEC);

  }
  bool varR_reshiuqi = 0;
  if(myGizwits.hasBeenSet(EVENT_reshiuqi))
  {
    myGizwits.read(EVENT_reshiuqi,&varR_reshiuqi);//Address for storing data
    mySerial.println(F("EVENT_reshiuqi"));
    mySerial.println(varR_reshiuqi,DEC);

  }
  bool varR_jinhuaqi = 0;
  if(myGizwits.hasBeenSet(EVENT_jinhuaqi))
  {
    myGizwits.read(EVENT_jinhuaqi,&varR_jinhuaqi);//Address for storing data
    mySerial.println(F("EVENT_jinhuaqi"));
    mySerial.println(varR_jinhuaqi,DEC);

  }
  bool varR_song = 0;
  if(myGizwits.hasBeenSet(EVENT_song))
  {
    myGizwits.read(EVENT_song,&varR_song);//Address for storing data
    mySerial.println(F("EVENT_song"));
    mySerial.println(varR_song,DEC);

  }
  unsigned long varR_tiaoguang = 0;
  if(myGizwits.hasBeenSet(EVENT_tiaoguang))
  {
    myGizwits.read(EVENT_tiaoguang,&varR_tiaoguang);//Address for storing data
    mySerial.println(F("EVENT_tiaoguang"));
    mySerial.println(varR_tiaoguang,DEC);

  }


  //binary datapoint handle
  */

  myGizwits.process();
}