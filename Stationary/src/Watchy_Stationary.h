#include <Watchy.h>
#include "NunitoSans_Bold28pt7b.h"
#include "FreeSans24pt7b.h"

class WatchyStationary : public Watchy{
    public:
        using Watchy::Watchy;
        void drawWatchFace();
};
