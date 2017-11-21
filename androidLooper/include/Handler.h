// Handler.h

#ifndef LEGO_LOOPER_HANDLER_H
#define LEGO_LOOPER_HANDLER_H

#include "Message.h"
#include "Looper.h"

namespace Lego {
class Message;

class Handler {
public:
    Handler();
    virtual ~Handler();

    virtual void handleMessage(shared_ptr<Message> msg);
    
    void sendMessage();
    void sendMessageAtTime();
    void sendMessageDelayed();
protected:

private:
};

}
#endif
