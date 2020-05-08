#include "action.h"

Action::Action(int sender, QString name, QVector<int> params):
    sender(sender), name(name), params(params) {
}
