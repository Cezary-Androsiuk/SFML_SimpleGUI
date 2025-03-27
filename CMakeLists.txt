cmake_minimum_required(VERSION 3.16)

project(SimpleGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# resources
set(RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)
set(RES_DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/res)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    src/Program.hpp src/Program.cpp
    src/SimpleGUI.hpp src/SimpleGUI.cpp
    src/SimpleGUI/common.hpp
    src/SimpleGUI/SguiObject.hpp src/SimpleGUI/SguiObject.cpp
    src/SimpleGUI/Button.hpp src/SimpleGUI/Button.cpp
    src/SimpleGUI/CheckBox.hpp src/SimpleGUI/CheckBox.cpp
    src/SimpleGUI/GroupBox.hpp src/SimpleGUI/GroupBox.cpp
    src/SimpleGUI/ImageBox.hpp src/SimpleGUI/ImageBox.cpp
    src/SimpleGUI/Label.hpp src/SimpleGUI/Label.cpp
    src/SimpleGUI/RadioButton.hpp src/SimpleGUI/RadioButton.cpp
    src/SimpleGUI/Switch.hpp src/SimpleGUI/Switch.cpp
    src/SimpleGUI/TabControl.hpp src/SimpleGUI/TabControl.cpp
)

# Copy resources on build
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RES_DIR}
        ${RES_DEST_DIR}
    COMMENT "Copying resources to build directory..."
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# resources instalation
install(DIRECTORY ${RES_DIR} DESTINATION ${CMAKE_INSTALL_BINDIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)
