// Handler.h

#ifndef LEGO_LOOPER_HANDLER_H
#define LEGO_LOOPER_HANDLER_H

#include "Message.h"
#include "MessageQueue.h"
#include "Looper.h"

namespace Lego {
class Message;
class Callback;

/**
 * A Handler allows you to send and process Message and Runnable
 * object associated with a thread's MessageQueque, Each Handler
 * instance is associated with a single thread and thread's message
 * queue. when you create a new Hander, it is bound to the thread /
 * message queue of the thread that is creating it. it will deliver
 * messages and runnables to that message queue and execute them as
 * them as they come out of the message queue.
 * 
 * There are to main uses for a Handler:(1) to schedule messages and
 * runnables to be executed as some point in the future; and (2) to enqueue
 * an action to be performed on a different thread than your own
 */
class Handler {

public:
    Handler();
    Handler(Callback& callback);
    Handler(Looper& looper);
    Handler(Looper& looper, Callback& callback);
    Handler(Looper& looper, Callback& callback, bool async);

    virtual ~Handler();

    virtual void handleMessage(Message& msg);
    
    void obtainMessage();
    void dispatchMessage();
    void sendMessage();
    void sendMessageAtTime();
    void sendMessageDelayed();
protected:

private:
    static Handler& MAIN_THREAD_HANDLER;
    static void handleCallback(Message& message);

    Looper mLooper;
    MessageQueue mQueue;
    Callback mCallback;
    bool mAsynchronous;
};

class Callback {
public:
    Callback();
    virtual ~Callback();
    virtual void handleMessage(Message& msg);    
};
}
#endif
