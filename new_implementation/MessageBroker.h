#ifndef ASSIGNMENT_OLT2NEW_MESSAGEBROKER_H
#define ASSIGNMENT_OLT2NEW_MESSAGEBROKER_H

#include <vector>
#include <string>
#include "Message.h"

class MessageBroker{
private:
    std::vector<Message> m_messages;
public:
    explicit MessageBroker();

    void add(const Message& message);
    int count() const;
    int count(long target_id) const;

    Message& peek_message_for(long target_id);
    Message pop_message_for(long target_id);

    void print(long target_id) const;
    void print() const;
};


#endif //ASSIGNMENT_OLT2NEW_MESSAGEBROKER_H
