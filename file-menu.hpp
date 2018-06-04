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

#ifndef FREEDOM_DAW_FILE_MENU_HPP
#define FREEDOM_DAW_FILE_MENU_HPP

#include <QMenu>

namespace freedom_daw {

class Command;

/// Used for managing files, including
/// projects and single audio files.
class FileMenu final : public QMenu {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the
	/// parent widget, which should be
	/// an instance of the @ref MenuBar
	/// class.
	FileMenu(QWidget *parent = nullptr);
	/// Default deconstructor.
	~FileMenu();
signals:
	/// Emitted when closing, creating,
	/// or opening a project.
	/// @param A reference to the command instance.
	void NewCommand(const Command &command);
protected slots:
	/// Called when the user hits the button
	/// requesting to create a new project.
	void OnNewTriggered();
private:
	/// Used for closing a project.
	QAction *closeProject;
	/// Used for creating a new project.
	QAction *newProject;
	/// Used for opening an existing project.
	QAction *openProject;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_FILE_MENU_HPP
