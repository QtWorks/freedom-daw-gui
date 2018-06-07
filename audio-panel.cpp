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
#include <QHBoxLayout>

namespace freedom_daw {

AudioPanel::AudioPanel(QWidget *parent) : QFrame(parent) {

	pauseButton = new PauseButton(this);
	pauseButton->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);

	playButton = new PlayButton(this);
	playButton->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);

	recordButton = new RecordButton(this);
	recordButton->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);

	stopButton = new StopButton(this);
	stopButton->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);

	connect(playButton, &PlayButton::NewCommand, this, &AudioPanel::OnCommand);
	connect(recordButton, &RecordButton::NewCommand, this, &AudioPanel::OnCommand);
	connect(pauseButton, &PauseButton::Paused, this, &AudioPanel::OnCommand);
	connect(stopButton, &StopButton::Stopped, this, &AudioPanel::OnCommand);

	layout = new QGridLayout(this);
	setLayout(layout);

	QHBoxLayout *buttonLayout = new QHBoxLayout();
	buttonLayout->setSpacing(0);
	buttonLayout->addWidget(playButton);
	buttonLayout->addWidget(recordButton);
	buttonLayout->addWidget(pauseButton);
	buttonLayout->addWidget(stopButton);

	layout->addLayout(buttonLayout, 0, 0, 1, 1);
}

AudioPanel::~AudioPanel() {

}

void AudioPanel::OnCommand(const Command &command) {
	emit NewCommand(command);
}

} // namespace freedom_daw
