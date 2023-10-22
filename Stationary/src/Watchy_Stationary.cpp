#include "Watchy_Stationary.h"

void WatchyStationary::drawWatchFace(){
    uint16_t lines = 0;
    const char *lows [10] = {"", "une", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
    const char *lows2 [10] = {"", "et un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
    const char *teensone [10] = {"dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
    const char *tens [6] = {"", "", "vingt", "trente", "quarante", "cinquante"};

    //drawbg
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setTextWrap(false);

    //drawtime
    lines += 1;
    display.setCursor(0, lines*38-5);
    display.setFont(&NunitoSans_Bold28pt7b);
    switch(currentTime.Hour) {
        case 0:
            display.print("minuit");
            lines += 1;
            break;
        case 1:
            display.print("une");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 2:
            display.print("deux");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 3:
            display.print("trois");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 4:
            display.print("quatre");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 5:
            display.print("cinq");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 6:
            display.print("six");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 7:
            display.print("sept");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 8:
            display.print("huit");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 9:
            display.print("neuf");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 10:
            display.print("dix");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 11:
            display.print("onze");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 12:
            display.print("midi");
            lines += 1;
            break;
        case 13:
            display.print("treize");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 14:
            display.print("quator");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("ze");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 15:
            display.print("quinze");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 16:
            display.print("seize");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 17:
            display.print("dix-");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("sept");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 18:
            display.print("dix-");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("huit");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 19:
            display.print("dix-");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("neuf");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 20:
            display.print("vingt");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 21:
            display.print("vingt");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("et une");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 22:
            display.print("vingt");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("deux");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
        case 23:
            display.print("vingt");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("trois");
            lines += 1;
            display.setCursor(0, lines*38-5);
            display.print("heure");
            lines += 1;
            break;
    }

    
    display.setCursor(0, lines*38-5);
    display.setFont(&FreeSans24pt7b);
    if (currentTime.Minute != 0) {
        
        if (currentTime.Minute < 10) {
            display.print(lows[currentTime.Minute]);
        } else if (currentTime.Minute < 20) {
            display.print(teensone[currentTime.Minute-10]);
        } else {
            display.print(tens[currentTime.Minute/10]);
            if (currentTime.Minute%10 > 0) {
                lines += 1;
                display.setCursor(0, lines*38-5);
                display.print(lows2[currentTime.Minute%10]);
            }
        }
    }
}
