// Message.h

#ifndef LEGO_LOOPER_MESSAGE_H
#define LEGO_LOOPER_MESSAGE_H

#include <pthread.h>
#include "Handler.h"

namespace Lego {
class Handler;
class Looper;

/**
 * Defines a message containing a description and arbitrary data object that can be 
 * send to a Handler. This object contains two extra int fields and an extra object field
 * that allow you to do allocations in many cases.
 */
class Message {
public:
    Message();
    virtual ~Message();

    int what;
    int arg1;
    int arg2;

    // Object
    void* obj;

    /**
     * Optional field indicating the uid that sent the message.
     * This is only valid for messages posted by a Messager; otherwise
     * it will be -1.
     */
    int sendingUid = -1;

    static int FLAG_IN_USE;
    static int FLAG_ASYNCHRONOUS;
    static int FLAGS_TO_CLEAR_ON_COPY_FROM;

    int flags;
    size_t when;
    //Bundle data;

    Handler target;
    // Runnable callback;
    Message& next;

    static Message& obtain();
    static Message& obtain(Message& message);
    
    void sendToTarget();
    bool isAsynchronous();
    void setAsynchronous(bool async);

protected:
private:
	pthread_mutex_t mMutex;
    pthread_mutexattr_t mMutexAttr;
};

}
#endif
