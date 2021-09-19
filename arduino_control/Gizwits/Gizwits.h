/**
************************************************************
* @file         Gizwits + ArduinoUnoR3 Library 
* @brief        Gizwits header file
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
#ifndef _GIZWITS_H
#define _GIZWITS_H

extern "C"
{
  #include "gizwits_product.h"
}

extern dataPoint_t currentDataPoint;
extern wifiStatueFlags_t wifiStatueFlags;

/*  Gizwits class */
class Gizwits
{
public:

	Gizwits();
	~Gizwits();

	void begin(void);
	void process(void);

	void read(EVENT_TYPE_T eventType, bool* value);
	void read(EVENT_TYPE_T eventType, uint32_t* value);
	void read(EVENT_TYPE_T eventType, int32_t* value);
	void read(EVENT_TYPE_T eventType, float* value);
	void readBinary(EVENT_TYPE_T eventType, uint8_t* data);
	
	void write(VALUE_TYPE_T valueType, bool value);
	void write(VALUE_TYPE_T valueType, uint32_t value);
	void write(VALUE_TYPE_T valueType, int32_t value);
	void write(VALUE_TYPE_T valueType, float value);
	void writeBinary(VALUE_TYPE_T valueType, uint8_t* data,uint32_t dataLen);
	
	bool hasBeenSet(EVENT_TYPE_T eventType);
	bool wifiHasBeenSet(EVENT_TYPE_T eventType);
	void setBindMode(uint8_t mode);

};

#endif