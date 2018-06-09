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

#include "track-manager.hpp"

#include "timeline.hpp"
#include "track.hpp"
#include "track-body.hpp"
#include "track-header.hpp"

#include <QGridLayout>

namespace freedom_daw {

TrackManager::TrackManager(QWidget *parent) : QWidget(parent) {

	timeline = new Timeline(this);

	layout = new QGridLayout(this);
	layout->setAlignment(Qt::AlignTop);
	layout->addWidget(timeline, 0, 1, 1, 1);

	setLayout(layout);
}

TrackManager::~TrackManager() {

}

void TrackManager::AddTrack(unsigned int trackID) {

	auto track = new Track(this);
	track->SetID(trackID);

	auto header = track->GetHeader();
	auto body = track->GetBody();
	auto index = trackList.size();

	// widget, row index, column index, row count, column count
	// the +1 is to go below the timeline
	layout->addWidget(header, index + 1, 0, 1, 1);
	layout->addWidget(body,   index + 1, 1, 1, 1);

	trackList.push_back(track);
}

void TrackManager::RenameTrack(unsigned int trackID,
                               const QString &name) {
	for (auto track : trackList) {
		if (track->GetID() == trackID) {
			track->SetName(name);
			break;
		}
	}
}

} // namespace freedom_daw
