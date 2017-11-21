// Message.cpp

#include "Message.h"

namespace Lego {

int Message::FLAG_IN_USE = 1 << 0;
int Message::FLAG_ASYNCHRONOUS = 1 << 1;
int Message::FLAGS_TO_CLEAR_ON_COPY_FROM = FLAG_IN_USE;

Message::Message() {
	pthread_mutexattr_init(&mMutexAttr);
	pthread_mutex_init(&mMutex, &mMutexAttr);
}

Message::~Message() {
	pthread_mutexattr_destroy(&mMutexAttr);
	pthread_mutex_destroy(&mMutex);
}

void Message::sendToTarget() {

}
bool Message::isAsynchronous() {

}
void Message::setAsynchronous(bool async) {

}

Message& Message::obtain() {

}

};
