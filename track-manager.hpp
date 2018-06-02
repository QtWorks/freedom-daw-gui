// Copyright (C) 2018 Taylor Holberton
//
//  This file is part of Freedom DAW.
//
//  Freedom DAW is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Freedom DAW is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Freedom DAW. If not, see <http://www.gnu.org/licenses/>.

#ifndef FREEDOM_DAW_TRACK_MANAGER_HPP
#define FREEDOM_DAW_TRACK_MANAGER_HPP

#include <QWidget>
#include <QList>

class QVBoxLayout;

namespace freedom_daw {

class Track;

class TrackManager : public QWidget {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent The widget creating the
	/// track manager.
	TrackManager(QWidget *parent = nullptr);
	/// Default deconstructor.
	~TrackManager();
	/// Adds a track to the track manager.
	/// @param trackID The ID to assign the
	/// newly created track.
	void AddTrack(unsigned int trackID);
	/// Renames an existing track. If the
	/// track specified by the track ID does
	/// not exist, then this function does nothing.
	/// @param trackID The ID of the track to rename.
	/// @param name The new name to give the track.
	void RenameTrack(unsigned int trackID,
	                 const QString &name);
private:
	/// Contains the list of tracks managed
	/// by the track manager.
	QList<Track*> tracks;
	/// The vertical layouts for the tracks.
	QVBoxLayout *layout;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_TRACK_MANAGER_HPP
