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
    src/SimpleGUI/SimpleGUI.hpp src/SimpleGUI/SimpleGUI.cpp
    src/SimpleGUI/components/common.hpp
    src/SimpleGUI/components/SguiObject.hpp src/SimpleGUI/components/SguiObject.cpp
    src/SimpleGUI/components/Button.hpp src/SimpleGUI/components/Button.cpp
    src/SimpleGUI/components/CheckBox.hpp src/SimpleGUI/components/CheckBox.cpp
    src/SimpleGUI/components/GroupBox.hpp src/SimpleGUI/components/GroupBox.cpp
    src/SimpleGUI/components/ImageBox.hpp src/SimpleGUI/components/ImageBox.cpp
    src/SimpleGUI/components/Label.hpp src/SimpleGUI/components/Label.cpp
    src/SimpleGUI/components/RadioButton.hpp src/SimpleGUI/components/RadioButton.cpp
    src/SimpleGUI/components/Switch.hpp src/SimpleGUI/components/Switch.cpp
    src/SimpleGUI/components/TabControl.hpp src/SimpleGUI/components/TabControl.cpp
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
