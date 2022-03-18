
add_executable(new_implementation main.cpp Message.cpp Message.h MessageBroker.cpp MessageBroker.h MessageReader.cpp MessageReader.h timestamp.cpp timestamp.h)

target_compile_options(new_implementation PRIVATE -Og -Wall -Wextra -Werror -pedantic)

set_target_properties(new_implementation
        PROPERTIES
            LANGUAGE CXX
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
        )