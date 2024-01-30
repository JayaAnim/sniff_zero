cmake_minimum_required(VERSION 3.22.1)

project(sniffer C)

include(FindPCAP.cmake)

# Creates compile_commands.json for lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the source files
set(SRC_DIR src)
set(INC_DIR inc)

set(SRC_FILES
    ${SRC_DIR}/main.c
    ${SRC_DIR}/packet_parser.c
    ${SRC_DIR}/interface_opts.c
    ${SRC_DIR}/sniffer_config.c
    ${SRC_DIR}/ieee802_11.c
    ${SRC_DIR}/ipvx.c
    ${SRC_DIR}/ethernet.c
    ${SRC_DIR}/sniffer_api.c
    ${SRC_DIR}/sniffer.c
)

set(INC_FILES
    ${INC_DIR}/packet_parser.h
    ${INC_DIR}/interface_opts.h
    ${INC_DIR}/sniffer_config.h
    ${INC_DIR}/sniffer_api.h
    ${INC_DIR}/ieee802_11.h
    ${INC_DIR}/ipvx.h
    ${INC_DIR}/ethernet.h
    ${INC_DIR}/sniffer.h
)

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES} ${INC_FILES})

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${PCAP_LIBRARY})

# Install targets
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${SRC_FILES} ${INC_FILES} DESTINATION src)

