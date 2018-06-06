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

#include "timeline.hpp"

#include <QLabel>
#include <QPainter>

namespace freedom_daw {

Timeline::Timeline(QWidget *parent) : QFrame(parent) {
	setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
}

Timeline::~Timeline() {

}

QSize Timeline::minimumSizeHint() const {
	return QSize(50, 50);
}

void Timeline::paintEvent(QPaintEvent *) {

	QPainter painter;
	painter.begin(this);

	for (auto i = 0; i < width(); i += 200) {
		painter.drawLine(i, height(), i, height() / 2);
		painter.drawLine(i + 50, height(), i + 50, (height() * 3)/ 4);
		painter.drawLine(i + 100, height(), i + 100, (height() * 3)/ 4);
		painter.drawLine(i + 150, height(), i + 150, (height() * 3) / 4);
	}

	painter.end();
}

} // namespace freedom_daw
