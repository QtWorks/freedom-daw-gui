cmake_minimum_required(VERSION 2.6)

cmake_policy (SET CMP0048 NEW)

project("Freedom DAW GUI" VERSION 0.1.0 LANGUAGES CXX)

find_package(Qt5Widgets)

set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

add_executable("freedom-daw"
	"audio-panel.hpp"
	"audio-panel.cpp"
	"command.hpp"
	"command.cpp"
	"controller.cpp"
	"controller.hpp"
	"central-widget.hpp"
	"central-widget.cpp"
	"driver.hpp"
	"driver.cpp"
	"exception.hpp"
	"exception.cpp"
	"file-menu.hpp"
	"file-menu.cpp"
	"help-menu.hpp"
	"help-menu.cpp"
	"invalid-response-code.hpp"
	"invalid-response-code.cpp"
	"knob.hpp"
	"knob.cpp"
	"main.cpp"
	"main-window.cpp"
	"main-window.hpp"
	"menu-bar.cpp"
	"menu-bar.hpp"
	"new-track-command.hpp"
	"new-track-command.cpp"
	"new-track-response.hpp"
	"new-track-response.cpp"
	"process-driver.hpp"
	"process-driver.cpp"
	"record-button.hpp"
	"record-button.cpp"
	"response.hpp"
	"response.cpp"
	"stdio-driver.hpp"
	"stdio-driver.cpp"
	"stylesheets.qrc"
	"track.hpp"
	"track.cpp"
	"track-body.hpp"
	"track-body.cpp"
	"track-header.hpp"
	"track-header.cpp"
	"track-menu.hpp"
	"track-menu.cpp"
	"track-manager.hpp"
	"track-manager.cpp")

target_link_libraries("freedom-daw" PRIVATE Qt5::Widgets)

target_compile_features("freedom-daw" PRIVATE cxx_std_17)

if (CMAKE_COMPILER_IS_GNUCXX)
	target_compile_options("freedom-daw" PRIVATE -Wall -Wextra -Werror -Wfatal-errors)
endif (CMAKE_COMPILER_IS_GNUCXX)
