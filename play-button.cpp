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

#include "play-button.hpp"

#include "play-command.hpp"

#include <QPainter>

#include <algorithm>
#include <cmath>

namespace freedom_daw {

PlayButton::PlayButton(QWidget *parent) : AudioButton(parent) {
	activeColor = QColor(0, 255, 0, 63);
	inactiveColor = QColor(0, 0, 0, 63);
	setCheckable(true);
	connect(this, &QAbstractButton::toggled, this, &PlayButton::OnToggled);
}

PlayButton::~PlayButton() {

}

void PlayButton::SetActiveColor(const QColor &color) {
	activeColor = color;
}

void PlayButton::SetInactiveColor(const QColor &color) {
	inactiveColor = color;
}

void PlayButton::OnToggled(bool state) {
	// TODO grey out the play button
	// so that it can't be pressed again.
	if (state) {
		PlayCommand playCommand;
		emit NewCommand(playCommand);
	} else {
	}
}

void PlayButton::paintEvent(QPaintEvent *event) {

	AudioButton::paintEvent(event);

	auto legSize = std::min(width(), height());

	double triangleHeight = static_cast<double>(legSize) * (std::sqrt(3.0) / 2.0);

	auto xStart = (width() / 2) - (static_cast<int>(triangleHeight) / 2);
	auto yStart = (height() / 2) - (legSize / 2);

	QPainterPath trianglePath;
	trianglePath.lineTo(xStart, yStart);
	trianglePath.lineTo(xStart, yStart + legSize);
	trianglePath.lineTo(xStart + static_cast<int>(triangleHeight), yStart + (legSize / 2));
	trianglePath.lineTo(xStart, yStart);

	auto currentColor = inactiveColor;
	if (isChecked())
		currentColor = activeColor;

	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.setPen(Qt::NoPen);
	painter.fillPath(trianglePath, QBrush(currentColor));
	painter.end();
}

} // namespace freedom_daw
