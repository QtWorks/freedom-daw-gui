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

#ifndef FREEDOM_DAW_TRACK_HPP
#define FREEDOM_DAW_TRACK_HPP

#include <QFrame>

class QString;
class QHBoxLayout;

namespace freedom_daw {

class TrackBody;
class TrackHeader;
class TrackManager;

/// Represents an audio track
/// contained within the track manager.
class Track final : public QFrame {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent The parent widget.
	Track(QWidget *parent = nullptr);
	/// Default deconstructor.
	~Track();
	/// Gets the ID of the track.
	/// @returns The ID of the track.
	unsigned int GetID() const noexcept;
	/// Gets the instance of the track header.
	/// @returns A pointer to the track header.
	TrackHeader *GetHeader() noexcept;
	/// Gets the instance of the track body.
	/// @returns A pointer to the track body.
	TrackBody *GetBody() noexcept;
protected:
	/// The track manager is responsible for
	/// creating the track and managing its lifetime.
	friend TrackManager;
	/// Sets the name of the track, contained
	/// within the track header.
	/// @param name The new name of the track.
	void SetName(const QString &name);
	/// Sets the track ID. The track ID
	/// is used to identify tracks to the
	/// audio driver.
	/// @param id The new track ID.
	void SetID(unsigned int id);
private:
	/// The track ID.
	unsigned int id;
	/// The header of the track, which
	/// contains controls and the track name.
	TrackHeader *header;
	/// The body of the track, which contains
	/// the audio visualization within the timeline.
	TrackBody *body;
	/// A horizontal box layout for the track header
	/// and the track body.
	QHBoxLayout *layout;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_TRACK_HPP
