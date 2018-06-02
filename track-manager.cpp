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

#include "track.hpp"

#include <QVBoxLayout>

namespace freedom_daw {

TrackManager::TrackManager(QWidget *parent) : QWidget(parent) {
	layout = new QVBoxLayout(this);
	setLayout(layout);
	setObjectName("TrackManager");
}

TrackManager::~TrackManager() {

}

void TrackManager::AddTrack(unsigned int trackID) {

	auto track = new Track(this);
	track->SetID(trackID);
	track->SetName("Untitled");
	track->show();

	tracks.push_back(track);

	layout->addWidget(track, 0, Qt::AlignTop);
}

void TrackManager::RenameTrack(unsigned int trackID,
                               const QString &name) {
	for (auto track : tracks) {
		if (track->GetID() == trackID) {
			track->SetName(name);
			break;
		}
	}
}

} // namespace freedom_daw
