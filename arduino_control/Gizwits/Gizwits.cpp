/**
************************************************************
* @file         Gizwits + ArduinoUnoR3 Library 
* @brief        Gizwits Process , Protcol Transformation
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
#include "Gizwits.h"
#include <Arduino.h>

dataPoint_t currentDataPoint;
wifiStatueFlags_t wifiStatueFlags;


Gizwits::Gizwits()
{
	memset((uint8_t*)&currentDataPoint, 0, sizeof(dataPoint_t));
}

Gizwits::~Gizwits()
{
	return;
}

void Gizwits::begin(void)
{ 
	Serial.begin(9600);
	gizwitsInit();
}

/**
* @brief Serial write , Send to wifi module
*
* @param buf      : Input data
* @param len       : data length
*
* @return : Success,payload length
*			-1，Error
*/
int32_t uartWrite(uint8_t *buf, uint32_t len)
{
    uint32_t i = 0;
    
    if(NULL == buf)
    {
        return -1;
    }
    
    for(i=0; i<len; i++)
    {
        Serial.write(buf[i]);
        if(i >=2 && buf[i] == 0xFF)
        {
            Serial.write(0x55);
        }
    }
    return len;
}

/*void serialEvent(void)
{
	uint8_t value = 0;
	value = (unsigned char)Serial.read();
	gizPutData(&value, 1);
}*/


/**
* @brief Get package , Handle Protocol Data
*
*
* @return : Null
*/
void Gizwits::process(void)
{
	uint8_t readChar = 0;
    uint16_t i=0,num = 0;
    num = Serial.available();
    if(0 < num)
    {
        for(i=0; i<num; i++)
        {
            readChar = Serial.read();
            gizPutData(&readChar, 1);
        }
        
    }
	gizwitsHandle((dataPoint_t *)&currentDataPoint);
}

bool Gizwits::wifiHasBeenSet(EVENT_TYPE_T eventType)
{
	bool flag;
	switch(eventType)
	{
			case WIFI_SOFTAP:
				flag = 	wifiStatueFlags.flagWifi_softap;
				wifiStatueFlags.flagWifi_softap = 0;
			break;
			case WIFI_AIRLINK:
				flag = 	wifiStatueFlags.flagWifi_airlink;
				wifiStatueFlags.flagWifi_airlink = 0;
			break;
			case WIFI_STATION:
				flag = 	wifiStatueFlags.flagWifi_station;
				wifiStatueFlags.flagWifi_station = 0;
			break;
			case WIFI_CON_ROUTER:
				flag = 	wifiStatueFlags.flagWifi_con_router;
				wifiStatueFlags.flagWifi_con_router = 0;
			break;
			case WIFI_DISCON_ROUTER:
				flag = 	wifiStatueFlags.flagWifi_discon_router;
				wifiStatueFlags.flagWifi_discon_router = 0;
			break;
			case WIFI_CON_M2M:
				flag = 	wifiStatueFlags.flagWifi_con_m2m;
				wifiStatueFlags.flagWifi_con_m2m = 0;
			break;
			case WIFI_DISCON_M2M:
				flag = 	wifiStatueFlags.flagWifi_discon_m2m;
				wifiStatueFlags.flagWifi_discon_m2m = 0;
			break;
			default:
			break;
	}
	
	return flag;
}

void Gizwits::setBindMode(uint8_t mode)
{
	gizwitsSetMode(mode);
}


/** The Structure of the current device status **/
attrFlags_t attrFlags;

/**
* @brief Get Datapoint Value

* Description:

* Get Value From currentDataPoint
* @param [in] eventType: event queue
* @param [in] value: Dest , Type In bool/uint32_t/int32_t/float/uint8_t(for binary)
* @return NULL
* @ref Gizwits.h
*/
void Gizwits::read(EVENT_TYPE_T eventType, bool* value)
{
	switch(eventType)
	{
	      case EVENT_LED_OnOff:
	        *value = currentDataPoint.valueLED_OnOff;
	        break;
	      case EVENT_chuang:
	        *value = currentDataPoint.valuechuang;
	        break;
	      case EVENT_reshiuqi:
	        *value = currentDataPoint.valuereshiuqi;
	        break;
	      case EVENT_jinhuaqi:
	        *value = currentDataPoint.valuejinhuaqi;
	        break;
	      case EVENT_song:
	        *value = currentDataPoint.valuesong;
	        break;
		default:
			break;
	}
	
	return;
}

void Gizwits::read(EVENT_TYPE_T eventType, uint32_t* value)
{
	switch(eventType)
	{
	      case EVENT_tiaoguang:
	        *value = currentDataPoint.valuetiaoguang;
	        break;
		default:
			break;
	}
	
	return;
}
void Gizwits::read(EVENT_TYPE_T eventType, int32_t* value)
{
	switch(eventType)
	{
	      case EVENT_tiaoguang:
	        *value = currentDataPoint.valuetiaoguang;
	        break;
		default:
			break;
	}
	
	return;
}
void Gizwits::read(EVENT_TYPE_T eventType, float* value)
{
	switch(eventType)
	{
	      case EVENT_tiaoguang:
	        *value = currentDataPoint.valuetiaoguang;
	        break;
		default:
			break;
	}
	
	return;
}

void Gizwits::readBinary(EVENT_TYPE_T eventType, uint8_t* data)
{
	switch(eventType)
	{
		default:
			break;
	}
	
	return;
}

/**
* @brief Check datapoint event is or not happen

* Description:

* @param [in] eventType: event queue
* @return 1,This datapoint event happen
*		  0,This datapoint event is not happen
* @ref Gizwits.h
*/
bool Gizwits::hasBeenSet(EVENT_TYPE_T eventType)
{
	bool flag;
	switch(eventType)
	{
			case EVENT_LED_OnOff:
				flag = 	attrFlags.flagLED_OnOff;
				attrFlags.flagLED_OnOff = 0;
				break;
			case EVENT_chuang:
				flag = 	attrFlags.flagchuang;
				attrFlags.flagchuang = 0;
				break;
			case EVENT_reshiuqi:
				flag = 	attrFlags.flagreshiuqi;
				attrFlags.flagreshiuqi = 0;
				break;
			case EVENT_jinhuaqi:
				flag = 	attrFlags.flagjinhuaqi;
				attrFlags.flagjinhuaqi = 0;
				break;
			case EVENT_song:
				flag = 	attrFlags.flagsong;
				attrFlags.flagsong = 0;
				break;
			case EVENT_tiaoguang:
				flag = 	attrFlags.flagtiaoguang;
				attrFlags.flagtiaoguang = 0;
				break;
		default:
			break;
	}
	
	return flag;
}

/**
* @brief Write Datapoint Value

* Description:

* Write value to currentDataPoint
* @param [in] eventType: event queue
* @param [in] value: Source value , Type In bool/uint32_t/int32_t/float/uint8_t(for binary)
* @return NULL
* @ref Gizwits.h
*/
void Gizwits::write(VALUE_TYPE_T valueType, bool value)
{
	switch(valueType)
	{
		default:
			break;
	}
	return;
}

void Gizwits::write(VALUE_TYPE_T valueType, uint32_t value)
{
	switch(valueType)
	{
		case VALUE_wendu:
			currentDataPoint.valuewendu = value;
		break;
		case VALUE_shidu:
			currentDataPoint.valueshidu = value;
		break;
		default:
			break;
	}

	return;
}
void Gizwits::write(VALUE_TYPE_T valueType, int32_t value)
{
	switch(valueType)
	{
		case VALUE_wendu:
			currentDataPoint.valuewendu = value;
		break;
		case VALUE_shidu:
			currentDataPoint.valueshidu = value;
		break;
		default:
			break;
	}

	return;
}
void Gizwits::write(VALUE_TYPE_T valueType, float value)
{
	switch(valueType)
	{
		case VALUE_wendu:
			currentDataPoint.valuewendu = value;
		break;
		case VALUE_shidu:
			currentDataPoint.valueshidu = value;
		break;
		default:
			break;
	}

	return;
}
void Gizwits::writeBinary(VALUE_TYPE_T valueType, uint8_t* data,uint32_t dataLen)
{
	switch(valueType)
	{
		default:
			break;
	}
	
	return;
}


/**
* @brief Read ms timer

* @param none
* @return System Millisecond
*/
uint32_t gizGetTimerCount(void)
{
  return millis();
}