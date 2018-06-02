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

#ifndef FREEDOM_DAW_TRACK_HEADER_HPP
#define FREEDOM_DAW_TRACK_HEADER_HPP

#include <QFrame>

class QLabel;
class QGridLayout;

namespace freedom_daw {

class Knob;

/// The header to the track widget,
/// which contains the name and controls
/// for the track.
class TrackHeader : public QFrame {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the track
	/// widget that is creating the track header.
	TrackHeader(QWidget *parent = nullptr);
	/// Default deconstructor.
	~TrackHeader();
	/// Sets the name to display in the header.
	/// @param name The name of the track.
	void SetName(const QString &name);
private:
	/// The label widget which displays the
	/// track name.
	QLabel *label;
	/// The panning knob, used to modify left
	/// and right channel balance.
	Knob *panningKnob;
	/// The volume knob, used for modifying
	/// the volume of the audio clips.
	Knob *volumeKnob;
	/// The layout to contain the track name
	/// and the track controls.
	QGridLayout *layout;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_TRACK_HEADER_HPP
