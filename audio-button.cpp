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

#include "audio-button.hpp"

#include <QLinearGradient>
#include <QPainter>

namespace freedom_daw {

AudioButton::AudioButton(QWidget *parent) : QAbstractButton(parent) {

}

AudioButton::~AudioButton() {

}

QSize AudioButton::minimumSizeHint() const {
	return QSize(50, 50);
}

void AudioButton::paintEvent(QPaintEvent *paintEvent) {
	if (isChecked()) {
		paintChecked(paintEvent);
	} else {
		paintUnchecked(paintEvent);
	}
}

void AudioButton::paintChecked(QPaintEvent *) {

	QColor color;
	color.setRgbF(0, 0, 0, 0.1);

	QPainter painter;
	painter.begin(this);
	painter.fillRect(0, 0, width(), height(), QBrush(color));
	painter.end();
}

void AudioButton::paintUnchecked(QPaintEvent *) {

	QColor topColor;
	topColor.setRgbF(1, 1, 1, 0.1);

	QColor bottomColor;
	bottomColor.setRgbF(0, 0, 0, 0.1);

	QLinearGradient gradient;
	gradient.setStart(width() / 2, 0);
	gradient.setFinalStop(width() / 2, height());
	gradient.setColorAt(0, topColor);
	gradient.setColorAt(1, bottomColor);

	QPainter painter;
	painter.begin(this);
	painter.fillRect(0, 0, width(), height(), gradient);
	painter.end();
}

} // namespace freedom_daw
