#ifndef ASSIGNMENT_OLT2NEW_MESSAGE_H
#define ASSIGNMENT_OLT2NEW_MESSAGE_H

#include <string>

enum class TargetType {
    DEV_UNDEFINED = 0x00,
    DEV_TEMPERATURE_SENSOR,
    DEV_PRESSURE_SENSOR,
    DEV_HUMIDITY_SENSOR,
    DEV_HEATER,
    DEV_AIR_PURIFIER,
    UNKNOWN,
};

/**
 * Create a string representing the TargetType
 * @param target_type the type to transform
 * @return the representation of the TargetType as a string
 */
std::string target_type_to_str(TargetType target_type);

/**
 * Convert a string into a TargetType if the string doesn't match then returns UNKNOWN
 * @param str the string being converted
 * @return the TargetType corresponding
 */
TargetType target_type_from_str(std::string str);

class Message{
private:
    long m_message_id;
    long m_target_id;
    TargetType m_target_type;
    long long m_timestamp;
    std::string m_text;

public:
    /**
     * Creates a Message with UNKNOWN as the target_type
     */
    explicit Message();

    /**
     * Creates a Message with the given target_type, target_id and text
     * @param target_type the type of the device
     * @param target_id the id of the device
     * @param text the text of the message
     */
    explicit Message(long target_id, TargetType target_type, std::string text);

    long get_message_id() const;
    long get_target_id() const;
    TargetType get_target_type() const;
    long long get_timestamp() const;
    std::string get_text() const;

    void set_text(std::string text);

    /**
     * Check if the Message is valid (if the target_type is not UNKNOWN)
     * @return true if the Message is valid, false otherwise
     */
    bool is_valid();

    /**
     * Create a string representing the Message
     * @return the representation of the Message as a string
     */
    std::string as_string();
};


#endif //ASSIGNMENT_OLT2NEW_MESSAGE_H
