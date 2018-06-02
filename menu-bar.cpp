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

#include "menu-bar.hpp"

#include "file-menu.hpp"
#include "help-menu.hpp"
#include "track-menu.hpp"

namespace freedom_daw {

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent) {

	fileMenu = new FileMenu(this);
	helpMenu = new HelpMenu(this);
	trackMenu = new TrackMenu(this);

	connect(trackMenu, &TrackMenu::NewCommand, this, &MenuBar::OnCommand);

	addMenu(fileMenu);

	editMenu = addMenu("Edit");
	viewMenu = addMenu("View");

	addMenu(trackMenu);
	addMenu(helpMenu);
}

MenuBar::~MenuBar() {

}

void MenuBar::OnCommand(const Command &command) {
	emit NewCommand(command);
}

} // namespace freedom_daw
