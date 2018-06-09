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

#include "track-menu.hpp"

#include "new-track-command.hpp"

namespace freedom_daw {

TrackMenu::TrackMenu(QWidget *parent) : QMenu(parent) {

	addTrack = addAction(tr("New Track"));
	addTrack->setShortcut(Qt::Key_N | Qt::SHIFT | Qt::CTRL);

	connect(addTrack, &QAction::triggered, this, &TrackMenu::OnNewTrackClicked);

	removeTrack = addAction(tr("Delete Track"));
	removeTrack->setShortcut(Qt::Key_D | Qt::SHIFT | Qt::CTRL);

	setTitle(tr("Track"));
}

TrackMenu::~TrackMenu() {

}

void TrackMenu::OnNewTrackClicked() {

	NewTrackCommand command;

	emit NewCommand(command);
}

} // namespace freedom_daw
