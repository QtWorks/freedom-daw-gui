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

#include "pause-button.hpp"

#include "pause-command.hpp"

#include <QPainter>

namespace freedom_daw {

PauseButton::PauseButton(QWidget *parent) : AudioButton(parent) {
	connect(this, &QAbstractButton::toggled, this, &PauseButton::OnToggled);
	setCheckable(true);
}

PauseButton::~PauseButton() {

}

void PauseButton::OnToggled(bool state) {
	if (state) {
		PauseCommand pauseCommand;
		emit Paused(pauseCommand);
	} else {
	}
}

void PauseButton::paintEvent(QPaintEvent *paintEvent) {

	AudioButton::paintEvent(paintEvent);

	QColor lineColor(0, 0, 0, 63);

	auto lineHeight = height();
	auto lineWidth = lineHeight / 4;

	auto xCenter = width() / 2;
	auto yCenter = height() / 2;

	auto yStart = yCenter - (lineHeight / 2);
	auto yStop = yCenter + (lineHeight / 2);

	auto xStart = xCenter - ((3 * lineWidth) / 2);
	auto xStop = xStart + lineWidth;

	QRect lineOne;
	lineOne.setX(xStart);
	lineOne.setY(yStart);
	lineOne.setWidth(xStop - xStart);
	lineOne.setHeight(yStop - yStart);

	xStart += 2 * lineWidth;
	xStop += 2 * lineWidth;

	QRect lineTwo;
	lineTwo.setX(xStart);
	lineTwo.setY(yStart);
	lineTwo.setWidth(xStop - xStart);
	lineTwo.setHeight(yStop - yStart);

	QPainter painter;
	painter.begin(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(lineColor));
	painter.drawRect(lineOne);
	painter.drawRect(lineTwo);
	painter.end();
}

} // namespace freedom_daw
