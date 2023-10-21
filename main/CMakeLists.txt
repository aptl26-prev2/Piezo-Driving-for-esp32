# idf_component_register(SRCS "parse.cpp" "driving_test.cpp" "utils.cpp" "timeEx.cpp" "sysmem.cpp" "syscalls.cpp" "main.cpp" "gpioEx.cpp" "driving.cpp" "advSensing.cpp" "data.cpp" "IoExpander.cpp" "ledEx.cpp" "sensing.cpp" "spi.cpp"
#                     INCLUDE_DIRS ""
#                     REQUIRES spiffs arduino)
idf_component_register(SRCS "parse.cpp" "driving_test.cpp" "utils.cpp" "timeEx.cpp" "sysmem.cpp" "syscalls.cpp" "main.cpp" "gpioEx.cpp" "driving.cpp" "advSensing.cpp" "data.cpp" "IoExpander.cpp" "ledEx.cpp" "sensing.cpp" "spi.cpp"
                    INCLUDE_DIRS ""
                    REQUIRES esp_timer spiffs)
