//
// Created by remy on 3/14/22.
//

#include "MessageBroker.h"
#include <iostream>

MessageBroker::MessageBroker() {

}

void MessageBroker::add(const Message &message) {
    this->m_messages.push_back(message);
}

int MessageBroker::count(long target_id) const {
    int elements = 0;
    for (auto message : this->m_messages) {
        if (message.get_target_id() == target_id) {
            elements++;
        }
    }
    return elements;
}

int MessageBroker::count() const {
    return this->m_messages.size();
}

Message &MessageBroker::peek_message_for(long target_id) {
    for (size_t i = 0; i < this->m_messages.size(); i++) {
        auto& message = this->m_messages[i];
        if (message.get_target_id() == target_id) {
            return message;
        }
    }
    // Assuming that the message exists
    exit(-1);
}

Message MessageBroker::pop_message_for(long target_id) {
    size_t index = std::numeric_limits<size_t>::max();
    for (size_t i = 0; i < this->m_messages.size(); i++) {
        auto& message = this->m_messages[i];
        if (message.get_target_id() == target_id) {
            index = i;
            break;
        }
    }
    if (index != std::numeric_limits<size_t>::max()) {
        auto copy = this->m_messages[index];
        auto to_remove = this->m_messages.begin();
        std::advance(to_remove, index);
        this->m_messages.erase(to_remove);
        return copy;
    }
    // Assuming that the message exists
    exit(-1);
}

void MessageBroker::print(long target_id) const {
    if (target_id == 0) {
        this->print();
        return;
    }
    for (auto message : this->m_messages) {
        if (message.get_target_id() == target_id) {
            std::cout << message.as_string() << std::endl;
        }
    }
}

void MessageBroker::print() const {
    for (auto message : this->m_messages) {
        std::cout << message.as_string() << std::endl;
    }
}