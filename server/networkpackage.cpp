#include "networkpackage.h"
///___________________________Base_message_______________________///
BaseMessage::BaseMessage(bool def) :
    defined(def) {}

bool BaseMessage::isDefined() const {
    return defined;
}
///____________________________Text_Message______________________///
TextMessage::TextMessage() :
    BaseMessage(false) {}

TextMessage::TextMessage(size_t dest, const QString& str) :
    BaseMessage(true),
    text_(str),
    dest_(dest) {}

QDataStream& operator << (QDataStream &out, const TextMessage& message) {
    out << message.defined << message.text_ << message.dest_;
    return out;
}

QDataStream& operator >> (QDataStream &in, TextMessage& message) {
    in >> message.defined >> message.text_ >> message.dest_;
    return in;
}

QString TextMessage::getText() const {
    return text_;
}

qulonglong TextMessage::getDest() const {
    return dest_;
}
///__________________________GameData_Message_____________________///
GameDataMessage::GameDataMessage() :
    BaseMessage(false) {}

GameDataMessage::GameDataMessage(QVector<Action> act) :
    BaseMessage(true),
    actions_(act) {};

QDataStream& operator << (QDataStream &out, const GameDataMessage& message) {
    out << message.defined << message.actions_;
    return out;
}

QDataStream& operator >> (QDataStream &in, GameDataMessage& message) {
    in >> message.defined >> message.actions_;
    return in;
}

///__________________________Error_Message_______________________///
ErrorMessage::ErrorMessage() :
    BaseMessage(false) {}

//ErrorMessage(somthing)

QDataStream& operator << (QDataStream &out, const ErrorMessage& message) {
    out << message.defined;
    return out;
}

QDataStream& operator >> (QDataStream &in, ErrorMessage& message) {
    in >> message.defined;
    return in;
}

///___________________________Network_Package_____________________///
NetworkPackage::NetworkPackage(qulonglong senderId,
                               TextMessage textMess,
                               GameDataMessage gameDataMess,
                               ErrorMessage errorMessage) :
    senderId_(senderId),
    text_(textMess),
    gameData_(gameDataMess),
    error_(errorMessage)
    {}

void NetworkPackage::update(TextMessage textMess,
                            GameDataMessage gameDataMess,
                            ErrorMessage errorMessage) {
    if (textMess.isDefined())
        text_ = textMess;

    if (gameDataMess.isDefined())
        gameData_ = gameDataMess;

    if (errorMessage.isDefined())
        error_ = errorMessage;
}

Package NetworkPackage::getData() const {
    return {senderId_, text_, gameData_, error_};
}

QDataStream& operator << (QDataStream &out, const NetworkPackage& pack) {
    out << pack.senderId_ << pack.text_ << pack.gameData_ << pack.error_;
    return out;
}

QDataStream& operator >> (QDataStream &in, NetworkPackage& pack) {
    in >> pack.senderId_ >> pack.text_ >> pack.gameData_ >> pack.error_;
    return in;
}
