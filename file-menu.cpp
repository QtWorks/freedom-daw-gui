// Copyright (C) 2018 Taylor Holberton
//
// This file is part of Freedom DAW.
//
// Freedom DAW is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Freedom DAW is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Freedom DAW. If not, see <http://www.gnu.org/licenses/>.

#include "file-menu.hpp"

#include "close-project-command.hpp"
#include "new-project-command.hpp"
#include "open-project-command.hpp"

namespace freedom_daw {

FileMenu::FileMenu(QWidget *parent) : QMenu(parent) {

	newProject = addAction(tr("New"));
	newProject->setShortcut(Qt::Key_N | Qt::CTRL);

	closeProject = addAction(tr("Close"));

	openProject = addAction(tr("Open"));
	openProject->setShortcut(Qt::Key_O | Qt::CTRL);

	properties = addAction(tr("Properties"));

	exportAs = addAction(tr("Export As"));

	connect(closeProject, &QAction::triggered, this, &FileMenu::OnCloseTriggered);
	connect(newProject, &QAction::triggered, this, &FileMenu::OnNewTriggered);
	connect(openProject, &QAction::triggered, this, &FileMenu::OnOpenTriggered);

	setTitle(tr("File"));
}

FileMenu::~FileMenu() {

}

void FileMenu::OnCloseTriggered() {

	CloseProjectCommand closeProjectCommand;

	emit NewCommand(closeProjectCommand);
}

void FileMenu::OnNewTriggered() {

	NewProjectCommand newProjectCommand;

	emit NewCommand(newProjectCommand);
}

void FileMenu::OnOpenTriggered() {

	OpenProjectCommand openProjectCommand;

	// TODO : Use OpenProjectDialog class
	// to get the project ID of the project to open.

	emit NewCommand(openProjectCommand);
}

} // namespace freedom_daw
