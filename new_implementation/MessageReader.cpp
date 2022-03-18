#include "MessageReader.h"
#include <fstream>
#include <iostream>

MessageReader::MessageReader(const std::string file_name) {
    parse_file(file_name);
}

void MessageReader::parse_file(const std::string file_name) {
    std::ifstream in { file_name };

    if (!in) {
        std::cout << "Failed to open file '" << file_name << "'!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
     // Structure:
     // TargetID TargetType Message
        long target_id;
        TargetType target_type;

        auto space_index = line.find(' ', 0);
        if (space_index != std::string::npos) {
            auto target_id_str = line.substr(0, space_index);
            target_id = std::stol(target_id_str, 0, 10);
        } else {
            std::cout << "String '" << line << "' not formatted properly in '" << file_name << "'!" << std::endl;
            continue;
        }

        auto start_next = space_index + 1;
        space_index = line.substr(start_next).find(' ');
        if (space_index != std::string::npos) {
            auto device_type_str = line.substr(start_next, space_index);
            target_type = target_type_from_str(device_type_str);
        } else {
            std::cout << "String '" << line << "' not formatted properly in '" << file_name << "'!" << std::endl;
            continue;
        }

        auto message = line.substr(start_next + space_index + 1);

        this->m_messages.push(Message {
            target_id,
            target_type,
            message
        });
    }

    in.close();
}

bool MessageReader::has_next() {
    return !this->m_messages.empty();
}

Message MessageReader::read_next() {
    auto message = this->m_messages.front();
    this->m_messages.pop();
    return message;
}