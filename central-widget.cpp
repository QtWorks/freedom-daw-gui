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

#include "central-widget.hpp"

#include "audio-panel.hpp"
#include "track-manager.hpp"

#include <QGridLayout>

namespace freedom_daw {

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent) {

	audioPanel = new AudioPanel(this);

	connect(audioPanel, &AudioPanel::NewCommand, this, &CentralWidget::OnCommand);

	trackManager = new TrackManager(this);

	layout = new QGridLayout(this);
	// The numbers here are organized like this:
	// starting row, starting column, row count, column count
	layout->addWidget(audioPanel,   0, 0, 1, 1);
	layout->addWidget(trackManager, 1, 0, 4, 1);

	// for testing
	trackManager->AddTrack(4);
	trackManager->RenameTrack(4, "Master");
}

CentralWidget::~CentralWidget() {

}

void CentralWidget::AddTrack(unsigned int trackID) {
	trackManager->AddTrack(trackID);
}

void CentralWidget::OnCommand(const Command &command) {
	emit NewCommand(command);
}

} // namespace freedom_daw
