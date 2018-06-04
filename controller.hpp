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

#ifndef FREEDOM_DAW_CONTROLLER_HPP
#define FREEDOM_DAW_CONTROLLER_HPP

#include <QObject>

class QString;

namespace freedom_daw {

class Command;
class Driver;
class MainWindow;

/// Used for controlling the driver and
/// the graphical interface.
class Controller final : public QObject {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the
	/// parent object of the controller.
	Controller(QObject *parent = nullptr);
	/// Default deconstructor.
	~Controller();
	/// Shows the main window.
	void ShowMainWindow();
	/// Resizes the main window, to a specified
	/// width and height.
	/// @param width The new width of the window.
	/// @param height The new height of the window.
	void ResizeMainWindow(int width, int height);
	/// Use the standard input and output driver.
	void UseStdioDriver();
	/// Use the process driver, using the standard
	/// input and output of the process to communicate
	/// with the driver.
	/// @param path The path to the program to start.
	void UseProcessDriver(const QString &path);
	/// Issues a command to the audio driver that
	/// it can exit gracefully.
	void CloseDriver();
public slots:
	/// Called when the graphical interface issues
	/// a command to the audio driver.
	/// @param command The command issued to the
	/// audio driver.
	void OnCommand(const Command &command);
protected:
	/// Reads a response to a new track command
	/// from the audio driver.
	void ReadNewTrackResponse();
private:
	/// The audio driver, used to manage projects
	/// and play or record audio.
	Driver *driver;
	/// The main window, used to provide a way for
	/// the user to control the audio driver.
	MainWindow *mainWindow;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_CONTROLLER_HPP
