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

#include "stop-button.hpp"

#include "pause-command.hpp"
#include "seek-command.hpp"

#include <QPainter>

#include <algorithm>

namespace freedom_daw {

StopButton::StopButton(QWidget *parent) : AudioButton(parent) {
	connect(this, &QAbstractButton::toggled, this, &StopButton::OnToggled);
	squareColor = QColor(0, 0, 0, 63);
	setCheckable(true);
}

StopButton::~StopButton() {

}

void StopButton::OnToggled(bool state) {
	if (state) {

		PauseCommand pauseCommand;
		emit Stopped(pauseCommand);

		SeekCommand seekCommand;
		seekCommand.SetFrame(0);
		emit Stopped(seekCommand);

		// TODO Change button appearance
	} else {

		// TODO Change button appearance
	}
}

void StopButton::paintEvent(QPaintEvent *event) {

	AudioButton::paintEvent(event);

	auto legSize = std::min(width(), height());
	legSize = (legSize * 3) / 4;
	auto xStart = (width() / 2) - (legSize / 2);
	auto yStart = (height() / 2) - (legSize / 2);

	QPainter painter;
	painter.begin(this);
	painter.setPen(Qt::NoPen);
	painter.fillRect(xStart, yStart, legSize, legSize, squareColor);
	painter.end();
}

} // namespace freedom_daw
