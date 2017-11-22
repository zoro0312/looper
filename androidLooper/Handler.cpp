// Handler.cpp

#include "Handler.h"

namespace Lego {

Handler& Handler::MAIN_THREAD_HANDLER = NULL;

void Handler::handleCallback(Message& message) {
    message.callback.run();
}

Handler::Handler() {
    Handler(NULL, false);
}

Handler::Handler(Callback& callback) {
    Handler(callback, false);
}

Handler::Handler(Looper& looper, Callback& callback) {
    Handler(Looper, callback, false);
}

Handler::Handler(Looper& looper, Callback& callback, bool async) {
    Handler(Looper, callback, async);
}

Handler::~Handler() {
}

Message& Handler::obtainMessage() {
    return Message::obtain(this);
}

void Handler::sendMessage(Message& msg) {
    
}

void Handler::dispatchMessage(Message& msg) {
    if (msg.callback != NULL) {
        handleCallback(msg);
    } else {
        if (mCallback != NULL) {
            if (mCallback.handleMessage(msg)) {
                return;
            }
        }
        handleMessage(msg);
    }
}

void Handler::handleMessage(Message& msg) {

}
}
