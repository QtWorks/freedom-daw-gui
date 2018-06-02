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

#include "track.hpp"

#include "track-body.hpp"
#include "track-header.hpp"

#include <QHBoxLayout>

namespace freedom_daw {

Track::Track(QWidget *parent) : QWidget(parent) {

	id = 0;

	header = new TrackHeader(this);
	body = new TrackBody(this);

	layout = new QHBoxLayout(this);
	layout->addWidget(header);
	layout->addWidget(body);

	//setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
}

Track::~Track() {

}

unsigned int Track::GetID() const noexcept {
	return id;
}

void Track::SetID(unsigned int id_) {
	id = id_;
}

void Track::SetName(const QString &name) {
	header->SetName(name);
}

} // namespace freedom_daw
