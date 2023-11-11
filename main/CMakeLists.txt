idf_component_register(
    SRCS "parse.cpp" "driving_test.cpp" "utils.cpp" "timeEx.cpp" "sysmem.cpp" "syscalls.cpp" "main.cpp" "gpioEx.cpp" "driving.cpp" "advSensing.cpp" "data.cpp" "IoExpander.cpp" "ledEx.cpp" "sensing.cpp" "spi.cpp"
    INCLUDE_DIRS "$ENV{IDF_PATH}/components"
    REQUIRES nvs_flash bt esp_timer spiffs
)