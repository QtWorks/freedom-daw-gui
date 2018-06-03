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

#include "record-button.hpp"

#include "record-start-command.hpp"
#include "record-stop-command.hpp"

#include <QGraphicsBlurEffect>
#include <QPainter>

#include <algorithm>

namespace freedom_daw {

RecordButton::RecordButton(QWidget *parent) : AudioButton(parent) {

	circleColor = Qt::red;

	blurEffect = new QGraphicsBlurEffect(this);
	blurEffect->setEnabled(false);
	blurEffect->setBlurRadius(50);

	connect(this, &QAbstractButton::toggled, this, &RecordButton::OnToggled);

	setCheckable(true);
}

RecordButton::~RecordButton() {

}

void RecordButton::SetCircleColor(const QColor &color) {
	circleColor = color;
}

void RecordButton::OnToggled(bool state) {
	if (state) {
		RecordStartCommand recordStartCommand;
		emit NewCommand(recordStartCommand);
	} else {
		RecordStopCommand recordStopCommand;
		emit NewCommand(recordStopCommand);
	}
}

void RecordButton::paintEvent(QPaintEvent *paintEvent) {

	AudioButton::paintEvent(paintEvent);

	QColor currentCircleColor(circleColor);

	if (!isChecked()) {
		currentCircleColor.setAlphaF(0.25);
		blurEffect->setEnabled(false);
	} else {
		blurEffect->setEnabled(true);
	}

	QPainter painter;
	painter.begin(this);
	painter.setPen(Qt::NoPen);

	// Draw the background

	// Draw the inner circle.
	auto radius = std::min(height(), width()) / 2;
	auto xSize = radius * 2;
	auto ySize = radius * 2;
	auto xOffset = (width() / 2) - (xSize / 2);
	auto yOffset = (height() / 2) - (ySize / 2);
	painter.setBrush(currentCircleColor);
	painter.drawEllipse(xOffset, yOffset, xSize, ySize);

	painter.end();
}

} // namespace freedom_daw
