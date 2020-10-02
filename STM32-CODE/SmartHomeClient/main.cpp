#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "api_lights.h"
#include "network-helper.h"

int main()
{
    // Variables
    TS_StateTypeDef TS_State;
    uint16_t x, y;
    uint8_t text[30];
    uint8_t idx;
    uint8_t touches = 0;
    bool touched;
    bool touchedled = false;
    uint8_t status;
    
    //Initial conf
    NetworkInterface* network = connect_to_default_network_interface();
    if (!network) {
        printf("Cannot connect to the network, see serial output\n");
    }
    
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    
    status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    
    while(1) {
        // Drawing GUI
        x = TS_State.touchX[idx];
        y = TS_State.touchY[idx];
        sprintf((char*)text, "Touch %d: x=%d y=%d", touches, x, y);
        BSP_LCD_SetFont(&Font24);
        BSP_LCD_DisplayStringAt(0, LINE(0), (uint8_t *)&text, LEFT_MODE);
        BSP_TS_GetState(&TS_State);
        
        
        BSP_LCD_SetFont(&Font24);
        //BSP_LCD_DrawEllipse(40,220,40,30);
        
        BSP_LCD_DisplayStringAt(0, 50, (uint8_t *)"Temp i C = ", CENTER_MODE);
        BSP_LCD_SetFont(&Font16);
        BSP_LCD_DrawRect(0,75,200,25);
        BSP_LCD_DisplayStringAt(0, 80, (uint8_t *)"Taend alt lys", LEFT_MODE);
        BSP_LCD_DrawRect(280,75,200,25);
        BSP_LCD_DisplayStringAt(0, 80, (uint8_t *)"Sluk alt lys", RIGHT_MODE);
        BSP_LCD_DrawRect(0,105,200,25);
        BSP_LCD_DisplayStringAt(0, 110,(uint8_t *)"Taend lys rum 1", LEFT_MODE);
        BSP_LCD_DrawRect(280,105,200,25);
        BSP_LCD_DisplayStringAt(0, 110,(uint8_t *)"Sluk lys rum 1", RIGHT_MODE);
        BSP_LCD_DrawRect(0,135,200,25);
        BSP_LCD_DisplayStringAt(0, 140,(uint8_t *)"Taend lys rum 2", LEFT_MODE);
        BSP_LCD_DrawRect(280,135,200,25);
        BSP_LCD_DisplayStringAt(0, 140,(uint8_t *)"Sluk lys rum 2", RIGHT_MODE);
        BSP_LCD_DrawRect(0,165,200,25);
        BSP_LCD_DisplayStringAt(0, 170,(uint8_t *)"Taend lys rum 3", LEFT_MODE);
        BSP_LCD_DrawRect(280,165,200,25);
        BSP_LCD_DisplayStringAt(0, 170,(uint8_t *)"Sluk lys rum 3", RIGHT_MODE);
        
        // Touch counter and reseting bools:
        if ((TS_State.touchDetected == 0) && (touched == true)){
            //touches++;
            touched = false;
            touchedled = false;
        }
        if (TS_State.touchDetected == 1){
            touched = true;
        }
        
        // Button 1
        // Defining touch area for this button and then enabling the Kitchen Lights
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 200) && (TS_State.touchY[0] > 75 ) && (TS_State.touchY[0] < 100 )){
            turnOnAllLight(network);
        }
        
        // Button 2
        // Defining touch area for this button and then enabling Living Room Lights
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 280) && (TS_State.touchX[0] < 480) && (TS_State.touchY[0] > 75 ) && (TS_State.touchY[0] < 100 )){
            turnOffAllLight(network);
        }
        
        // Button 3
        // Defining touch area for this button and then enabling Bathroom Lights
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 200) && (TS_State.touchY[0] > 105 ) && (TS_State.touchY[0] < 130 ))
        {
            turnOnInRoom(network, 2);
        }
        
        // Button 4
        // Defining touch area for this button and then showing image of Temp + Humidity
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 280) && (TS_State.touchX[0] < 480) && (TS_State.touchY[0] > 105 ) && (TS_State.touchY[0] < 130 ))
        {
            turnOffInRoom(network, 2);
        }
        
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 200) && (TS_State.touchY[0] > 135 ) && (TS_State.touchY[0] < 160 ))
        {
            //BSP_LCD_DrawRect(0,105,200,25);
            turnOnInRoom(network, 3);
        }
        
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 200) && (TS_State.touchY[0] > 135 ) && (TS_State.touchY[0] < 160 ))
        {
            //BSP_LCD_DrawRect(0,105,200,25);
            turnOffInRoom(network, 3);
        }
        
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 200) && (TS_State.touchY[0] > 165 ) && (TS_State.touchY[0] < 190 ))
        {
            //BSP_LCD_DrawRect(0,105,200,25);
            turnOnInRoom(network, 4);
        }
        
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 200) && (TS_State.touchY[0] > 165 ) && (TS_State.touchY[0] < 190 ))
        {
            //BSP_LCD_DrawRect(0,105,200,25);
            turnOffInRoom(network, 4);
        }
    }
}
