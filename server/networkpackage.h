#ifndef NETWORKPACKAGE_H
#define NETWORKPACKAGE_H

#include <QObject>
#include <QDataStream>

#include "action.h"

class BaseMessage {
public:
    BaseMessage() = default;
    BaseMessage(const BaseMessage&) = default;
    BaseMessage(bool);

    BaseMessage& operator=(const BaseMessage&) = default;
    ~BaseMessage() = default;

    bool isDefined() const;
protected:
    bool defined;
};

class TextMessage : public BaseMessage {
public:
    TextMessage();
    TextMessage(size_t, const QString&);

    TextMessage(const TextMessage&) = default;
    TextMessage& operator=(const TextMessage&) = default;
    ~TextMessage() = default;

    friend QDataStream& operator << (QDataStream &out, const TextMessage& pack);
    friend QDataStream& operator >> (QDataStream &in, TextMessage& pack);

    QString getText() const;
    qulonglong getDest() const;
private:
    QString text_;
    qulonglong dest_;
};

class GameDataMessage : public BaseMessage {
public:
    GameDataMessage();
    GameDataMessage(QVector<Action>);

    GameDataMessage(const GameDataMessage&) = default;
    GameDataMessage& operator=(const GameDataMessage&) = default;
    ~GameDataMessage() = default;

    friend QDataStream& operator << (QDataStream &out, const GameDataMessage& pack);
    friend QDataStream& operator >> (QDataStream &in, GameDataMessage& pack);
    QVector<Action> actions_;
};

class ErrorMessage : public BaseMessage {
public:
    ErrorMessage();
    //ErrorMessage(somthing)

    ErrorMessage(const ErrorMessage&) = default;
    ErrorMessage& operator=(const ErrorMessage&) = default;
    ~ErrorMessage() = default;

    friend QDataStream& operator << (QDataStream &out, const ErrorMessage& pack);
    friend QDataStream& operator >> (QDataStream &in, ErrorMessage& pack);
private:
};

struct Package {
    qulonglong senderId_;
    TextMessage text_;
    GameDataMessage gameData_;
    ErrorMessage error_;
};

class NetworkPackage {
public:
    NetworkPackage() = default;

    NetworkPackage(qulonglong,
                   TextMessage = TextMessage(),
                   GameDataMessage = GameDataMessage(),
                   ErrorMessage = ErrorMessage());

    NetworkPackage(const NetworkPackage&) = default;
    NetworkPackage& operator=(const NetworkPackage&) = default;
    ~NetworkPackage() = default;

    friend QDataStream& operator << (QDataStream &out, const NetworkPackage& pack);
    friend QDataStream& operator >> (QDataStream &in, NetworkPackage& pack);

    void update(TextMessage = TextMessage(),
                GameDataMessage = GameDataMessage(),
                ErrorMessage = ErrorMessage());

    Package getData() const;
private:
    qulonglong senderId_;

    TextMessage text_;
    GameDataMessage gameData_;
    ErrorMessage error_;

};

#endif // NETWORKPACKAGE_H
