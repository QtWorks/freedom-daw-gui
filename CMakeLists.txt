cmake_minimum_required(VERSION 2.6)

cmake_policy (SET CMP0048 NEW)

project("Freedom DAW GUI" VERSION 0.1.0 LANGUAGES CXX)

find_package(Qt5Widgets)

set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

add_executable("freedom-daw"
	"audio-button.hpp"
	"audio-button.cpp"
	"audio-panel.hpp"
	"audio-panel.cpp"
	"close-project-command.hpp"
	"close-project-command.cpp"
	"command.hpp"
	"command.cpp"
	"controller.cpp"
	"controller.hpp"
	"central-widget.hpp"
	"central-widget.cpp"
	"driver.hpp"
	"driver.cpp"
	"edit-menu.hpp"
	"edit-menu.cpp"
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
	"new-project-command.hpp"
	"new-project-command.cpp"
	"new-track-command.hpp"
	"new-track-command.cpp"
	"new-track-response.hpp"
	"new-track-response.cpp"
	"open-project-command.hpp"
	"open-project-command.cpp"
	"pause-button.hpp"
	"pause-button.cpp"
	"pause-command.hpp"
	"pause-command.cpp"
	"play-button.hpp"
	"play-button.cpp"
	"play-command.hpp"
	"play-command.cpp"
	"process-driver.hpp"
	"process-driver.cpp"
	"redo-command.hpp"
	"redo-command.cpp"
	"record-button.hpp"
	"record-button.cpp"
	"record-command.hpp"
	"record-command.cpp"
	"response.hpp"
	"response.cpp"
	"seek-command.hpp"
	"seek-command.cpp"
	"stdio-driver.hpp"
	"stdio-driver.cpp"
	"stop-button.hpp"
	"stop-button.cpp"
	"stylesheets.qrc"
	"timeline.hpp"
	"timeline.cpp"
	"track.hpp"
	"track.cpp"
	"track-body.hpp"
	"track-body.cpp"
	"track-header.hpp"
	"track-header.cpp"
	"track-label.hpp"
	"track-label.cpp"
	"track-menu.hpp"
	"track-menu.cpp"
	"track-manager.hpp"
	"track-manager.cpp"
	"undo-command.hpp"
	"undo-command.cpp"
	"quit-command.hpp"
	"quit-command.cpp")

target_link_libraries("freedom-daw" PRIVATE Qt5::Widgets)

add_executable("mock-driver"
	"mock-driver/main.cpp")

target_link_libraries("mock-driver" PRIVATE Qt5::Core)

if (CMAKE_COMPILER_IS_GNUCXX)
	target_compile_options("freedom-daw" PRIVATE -Wall -Wextra -Werror -Wfatal-errors -std=c++11)
	target_compile_options("mock-driver" PRIVATE -Wall -Wextra -Werror -Wfatal-errors -std=c++11)
endif (CMAKE_COMPILER_IS_GNUCXX)
