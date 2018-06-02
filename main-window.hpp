// Copyright (C) 2018 Taylor Holberton
//
//  This file is part of Freedom DAW.
//
//  Freedom DAW is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Freedom DAW is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Freedom DAW. If not, see <http://www.gnu.org/licenses/>.

#ifndef FREEDOM_DAW_MAIN_WINDOW_HPP
#define FREEDOM_DAW_MAIN_WINDOW_HPP

#include <QMainWindow>

namespace freedom_daw {

class CentralWidget;
class Command;
class MenuBar;

/// The top level window for the
/// applications graphical interface.
class MainWindow final : public QMainWindow {
	Q_OBJECT
public:
	/// Default constructor
	MainWindow();
	/// Default deconstructor
	~MainWindow();
	/// Add a new track to the track manager.
	/// @param trackID The track ID to assign
	/// the new track.
	void AddTrack(unsigned int trackID);
public slots:
	/// Called when a new command is dispatched
	/// from a button or menu item.
	/// @param command The command to pass to
	/// the audio driver.
	void OnCommand(const Command &command);
signals:
	/// This signal is emitted when the main
	/// window receives a command from a sub widget.
	/// It is passed to the controller, which passes
	/// the command to the audio driver.
	/// @param command The command to pass to the
	/// audio driver.
	void NewCommand(const Command &command);
private:
	/// The menu bar, used for various other non-audio functions.
	MenuBar *menuBar;
	/// The central widget, contained within the main window.
	CentralWidget *centralWidget;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_MAIN_WINDOW_HPP
