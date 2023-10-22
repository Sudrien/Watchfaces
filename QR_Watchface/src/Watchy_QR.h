#include <Watchy.h>
#include "qrcode.h"


class QR_Watchface : public Watchy{
    public:
        using Watchy::Watchy;
        void drawWatchFace();
        virtual void handleButtonPress();
};

extern RTC_DATA_ATTR bool modeEZ;
