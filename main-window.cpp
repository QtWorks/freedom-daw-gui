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

#include "main-window.hpp"

#include "central-widget.hpp"
#include "menu-bar.hpp"

namespace freedom_daw {

MainWindow::MainWindow() {

	menuBar = new MenuBar(this);
	connect(menuBar, &MenuBar::NewCommand, this, &MainWindow::OnCommand);
	setMenuBar(menuBar);

	centralWidget = new CentralWidget(this);
	setCentralWidget(centralWidget);

	setWindowTitle(tr("Music Recorder"));
}

MainWindow::~MainWindow() {

}

void MainWindow::AddTrack(unsigned int trackID) {
	centralWidget->AddTrack(trackID);
}

void MainWindow::OnCommand(const Command &command) {
	emit NewCommand(command);
}

} // namespace freedom_daw
