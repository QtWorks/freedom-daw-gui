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

#ifndef FREEDOM_DAW_TRACK_LABEL_HPP
#define FREEDOM_DAW_TRACK_LABEL_HPP

#include <QLabel>

namespace freedom_daw {

/// Used to show the name
/// of each track.
class TrackLabel final : public QLabel {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the
	/// parent widget. The parent widget,
	/// in this case, is an instance of
	/// the @ref TrackHeader class.
	TrackLabel(QWidget *parent = nullptr);
	/// Default deconstructor.
	~TrackLabel();
	/// Sets the name displayed by
	/// the track label.
	/// @param name The name to display
	/// on the track label.
	void SetName(const QString &name);
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_TRACK_LABEL_HPP
