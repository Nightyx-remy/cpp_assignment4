//
// Created by remy on 3/14/22.
//

#ifndef ASSIGNMENT_OLT2NEW_MESSAGEREADER_H
#define ASSIGNMENT_OLT2NEW_MESSAGEREADER_H

#include <string>
#include <queue>
#include "Message.h"

class MessageReader{
private:
    std::queue<Message> m_messages;

    void parse_file(const std::string file_name);
public:
    MessageReader(const std::string file_name);

    Message read_next();
    bool has_next();
};


#endif //ASSIGNMENT_OLT2NEW_MESSAGEREADER_H
