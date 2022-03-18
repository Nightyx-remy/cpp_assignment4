#include <iostream>
#include "Message.h"
#include "MessageBroker.h"
#include "MessageReader.h"

int main() {
    std::cout << "Hello, new C++ implementation!" << std::endl;

    Message msg0 = Message {123, TargetType::DEV_AIR_PURIFIER, "SET ON"};
    Message msg1 = Message {234, TargetType::DEV_TEMPERATURE_SENSOR, "SET ON"};
    Message msg2 = Message {123, TargetType::DEV_AIR_PURIFIER, "SET OFF"};
    Message msg3 = Message {123, TargetType::DEV_AIR_PURIFIER, "SET ON"};
    Message msg4 = Message {234, TargetType::DEV_TEMPERATURE_SENSOR, "MEASURE"};
    Message msg5 = Message {123, TargetType::DEV_AIR_PURIFIER, "SET MODE PURIFY"};
    Message msg6 = Message {321, TargetType::DEV_HEATER, "SET ON"};

    MessageBroker broker = MessageBroker {};
    broker.add(msg0);
    broker.add(msg1);
    broker.add(msg2);
    broker.add(msg3);
    broker.add(msg4);
    broker.add(msg5);
    broker.add(msg6);

    broker.print(321);

    long target_id = 123;
    std::cout << "Extracting messages for target_id = " << target_id << std::endl;
    for (int i = 0; i < broker.count(target_id); i++) {
        auto msg = broker.pop_message_for(target_id);
        std::cout << msg.as_string() << std::endl;
    }
    std::cout << "There are " << broker.count(target_id) << " messages left for target_id = " << target_id << std::endl;
    std::cout << "There are " << broker.count() << " messages left in the broker" << std::endl;

    MessageReader reader {"messages.in"};
    size_t count = 0;
    while (reader.has_next()) {
        Message msg = reader.read_next();
        broker.add(msg);
        count++;
    }
    std::cout << "Finished reading the file with " << count << " messages" << std::endl;
    std::cout << "There are " << broker.count() << " messages in the broker" << std::endl;

    broker.print();

    return 0;
}
