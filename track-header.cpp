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

#include "track-header.hpp"

#include "knob.hpp"
#include "track-label.hpp"

#include <QGridLayout>

namespace freedom_daw {

TrackHeader::TrackHeader(QWidget *parent) : QFrame(parent) {

	label = new TrackLabel(this);

	panningKnob = new Knob(parent);
	panningKnob->SetName(tr("Balance"));

	volumeKnob = new Knob(parent);
	volumeKnob->SetName(tr("Volume"));

	layout = new QGridLayout(this);
	layout->addWidget(label,       0, 0, 1, 1);
	layout->addWidget(panningKnob, 0, 1, 1, 1);
	layout->addWidget(volumeKnob,  0, 2, 1, 1);

	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

TrackHeader::~TrackHeader() {

}

void TrackHeader::SetName(const QString &name) {
	label->SetName(name);
}

} // namespace freedom_daw
