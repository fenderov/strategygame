#ifndef NETWORKPACKAGE_H
#define NETWORKPACKAGE_H

#include <QObject>
#include <variant>
#include <string>
#include <cassert>
//#include "Action"

class TextMessage {
public:
    TextMessage(const QString& str) :
        message(str) {};
    const QString message;
};

class GameDataMessage {
public:

private:
};

class ErrorMessage {
public:

private:
};



class NetworkPackage {
public:
    template <typename T>
    NetworkPackage(size_t senderId, size_t dest, T a) :
        senderId_(senderId),
        dest_(dest),
        data_(a) {};

    template <typename T>
    T getData();


private:
    const size_t senderId_;
    const size_t dest_;

    const std::variant<TextMessage, GameDataMessage, ErrorMessage> data_;
};

#endif // NETWORKPACKAGE_H
