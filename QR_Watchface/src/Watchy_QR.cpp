#include "Watchy_QR.h"

RTC_DATA_ATTR bool modeEZ = false;

void QR_Watchface::drawWatchFace(){

    //drawbg
    display.fillScreen(GxEPD_WHITE);

    //drawtime
    char time[20];
    sprintf(time, "%02d:%02d %d-%02d-%02d", currentTime.Hour, currentTime.Minute, tmYearToCalendar(currentTime.Year), currentTime.Month, currentTime.Day);
    QRCode qrcode;
    uint8_t qrcodeBytes[qrcode_getBufferSize(1)];
    qrcode_initText(&qrcode, qrcodeBytes, 1, ECC_MEDIUM, time);
    for (uint8_t y = 0; y < qrcode.size; y++) {
        for (uint8_t x = 0; x < qrcode.size; x++) {
            if(qrcode_getModule(&qrcode, x, y)){
                for (uint8_t i = 8*x; i< 8*x+8; i++){
                    for (uint8_t j = 8*y; j< 8*y+8; j++){
                        display.drawPixel(16+i, 16+j, GxEPD_BLACK);
                    }
                }
            } else {
                for (uint8_t i = 8*x; i< 8*x+8; i++){
                    for (uint8_t j = 8*y; j< 8*y+8; j++){
                        display.drawPixel(16+i, 16+j, GxEPD_WHITE);
                    }
                }
            }
        }
    }
    
    display.setCursor(5, 5);
    display.setTextColor(GxEPD_BLACK);
    if(modeEZ){
        display.print(time);
    }
}

void QR_Watchface::handleButtonPress() {
    if (guiState == WATCHFACE_STATE) {
        uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();

        if (wakeupBit & DOWN_BTN_MASK) {
            modeEZ = !modeEZ;
            RTC.read(currentTime);
            showWatchFace(true);
        }
        if (wakeupBit & MENU_BTN_MASK) {
            Watchy::handleButtonPress();
            return;
        }
    } else {
        Watchy::handleButtonPress();
    }
    return;
}
