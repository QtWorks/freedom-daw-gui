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

#include "audio-panel.hpp"

#include "pause-button.hpp"
#include "play-button.hpp"
#include "record-button.hpp"
#include "stop-button.hpp"

#include <QGridLayout>

namespace freedom_daw {

AudioPanel::AudioPanel(QWidget *parent) : QFrame(parent) {

	pauseButton = new PauseButton(this);
	playButton = new PlayButton(this);
	recordButton = new RecordButton(this);
	stopButton = new StopButton(this);

	connect(playButton, &PlayButton::NewCommand, this, &AudioPanel::OnCommand);
	connect(recordButton, &RecordButton::NewCommand, this, &AudioPanel::OnCommand);
	connect(pauseButton, &PauseButton::Paused, this, &AudioPanel::OnCommand);
	connect(stopButton, &StopButton::Stopped, this, &AudioPanel::OnCommand);

	layout = new QGridLayout(this);
	layout->setSpacing(0);
	layout->setMargin(0);
	layout->addWidget(playButton,   0, 0, 1, 1);
	layout->addWidget(recordButton, 0, 1, 1, 1);
	layout->addWidget(pauseButton,  0, 2, 1, 1);
	layout->addWidget(stopButton,   0, 3, 1, 1);
}

AudioPanel::~AudioPanel() {

}

void AudioPanel::OnCommand(const Command &command) {
	emit NewCommand(command);
}

} // namespace freedom_daw
