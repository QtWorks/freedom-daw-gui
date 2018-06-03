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

#include <QPainter>

#include <algorithm>

namespace freedom_daw {

StopButton::StopButton(QWidget *parent) : AudioButton(parent) {
	squareColor = QColor(0, 0, 0, 63);
}

StopButton::~StopButton() {

}

void StopButton::paintEvent(QPaintEvent *event) {

	AudioButton::paintEvent(event);

	auto legSize = std::min(width(), height());
	auto xStart = (width() / 2) - (legSize / 2);
	auto yStart = (height() / 2) - (legSize / 2);

	QPainter painter;
	painter.begin(this);
	painter.setPen(Qt::NoPen);
	painter.fillRect(xStart, yStart, legSize, legSize, squareColor);
	painter.end();
}

} // namespace freedom_daw
