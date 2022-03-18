//
// Created by remy on 3/14/22.
//

#include "Message.h"
#include <iostream>
#include <sstream>

long next_id() {
    static long id = 0x1000;
    return ++id;
}

std::string target_type_to_str(TargetType target_type) {
    switch (target_type) {
        case TargetType::DEV_UNDEFINED:
            return "undefined / generic";
        case TargetType::DEV_TEMPERATURE_SENSOR:
            return "temperature sensor";
        case TargetType::DEV_PRESSURE_SENSOR:
            return "pressure sensor";
        case TargetType::DEV_HUMIDITY_SENSOR:
            return "humidity sensor";
        case TargetType::DEV_HEATER:
            return "heater";
        case TargetType::DEV_AIR_PURIFIER:
            return "air purifier";
        case TargetType::UNKNOWN:
            return "UNKNOWN";
    }
    return "";
}

TargetType target_type_from_str(std::string str) {
    if (str == "temperature_sensor") {
        return TargetType::DEV_TEMPERATURE_SENSOR;
    } else if (str == "pressure_sensor") {
        return TargetType::DEV_PRESSURE_SENSOR;
    } else if (str == "humidity_sensor") {
        return TargetType::DEV_PRESSURE_SENSOR;
    } else if (str == "heater") {
        return TargetType::DEV_HEATER;
    } else if (str == "air_purifier") {
        return TargetType::DEV_AIR_PURIFIER;
    } else {
        return TargetType::UNKNOWN;
    }
}

Message::Message() : m_message_id{next_id()}, m_target_type{TargetType::UNKNOWN}, m_timestamp{get_timestamp()} {

}

Message::Message(long target_id, TargetType target_type, std::string text) : m_message_id{next_id()}, m_target_id{target_id}, m_target_type{target_type}, m_timestamp{get_timestamp()}, m_text{text} {

}

long Message::get_target_id() const {
    return this->m_target_id;
}

TargetType Message::get_target_type() const {
    return this->m_target_type;
}

long Message::get_message_id() const {
    return this->m_message_id;
}

long long Message::get_timestamp() const {
    return this->m_timestamp;
}

std::string Message::get_text() const {
    return this->m_text;
}

void Message::set_text(std::string text) {
    this->m_text = text;
}

bool Message::is_valid() {
    return this->get_target_type() != TargetType::UNKNOWN;
}

std::string Message::as_string() {
    std::ostringstream oss;
    oss << "[id: " << this->m_message_id << ", ts: " << this->m_timestamp << ", target_id: " << this->m_target_id << ", target_type: " << target_type_to_str(this->m_target_type) << "]: \"" << this->m_text << "\"";
    return oss.str();
}
