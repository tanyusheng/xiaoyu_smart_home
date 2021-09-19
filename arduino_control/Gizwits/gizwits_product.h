/**
************************************************************
* @file         gizwits_product.h
* @brief        Header file corresponding to gizwits_product.c (product hardware , software version definitions)
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
#ifndef _GIZWITS_PRODUCT_H
#define _GIZWITS_PRODUCT_H

#include <stdint.h>
#include "gizwits_protocol.h"


/**@} */
/**
* MCU Soft Version
*/
#define SOFTWARE_VERSION "03030000"
/**
* MCU Hardware Version
*/
#define HARDWARE_VERSION "03010000"

/**@name Device status data reporting interval time macro definition
* @{
*/
#define REPORT_TIME_MAX 6000 //6S
/**@} */

#pragma pack(1)
typedef struct {
  uint8_t flagWifi_softap:1;
  uint8_t flagWifi_airlink:1;
  uint8_t flagWifi_station:1;
  uint8_t flagWifi_con_router:1;
  uint8_t flagWifi_discon_router:1;
  uint8_t flagWifi_con_m2m:1;
  uint8_t flagWifi_discon_m2m:1;
} wifiStatueFlags_t;

typedef enum
{
  VALUE_LED_OnOff,
  VALUE_chuang,
  VALUE_reshiuqi,
  VALUE_jinhuaqi,
  VALUE_song,
  VALUE_tiaoguang,
  VALUE_wendu,
  VALUE_shidu,
  VALUE_TYPE_MAX
} VALUE_TYPE_T;
#pragma pack()

void mcuRestart(void);
int32_t uartWrite(uint8_t *buf, uint32_t len);

#endif