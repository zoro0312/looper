// Looper.h

#ifndef LEGO_LOOPER_LOOPER_H
#define LEGO_LOOPER_LOOPER_H

#include "Handler.h"
#include "Message.h"


namespace Lego {
class Handler;
class Message;

class Looper {
public:
    Looper();
    virtual ~Looper();
    void prepare();
    void loop();
protected:
private:
}
}
#endif
