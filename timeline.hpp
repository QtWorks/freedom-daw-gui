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

#ifndef FREEDOM_DAW_TIMELINE_HPP
#define FREEDOM_DAW_TIMELINE_HPP

#include <QWidget>

namespace freedom_daw {

/// Presents to the user the timeline of the
/// mix as well as various markers and a cursor
/// indicator.
class Timeline : public QWidget {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the central
	/// widget, which contains the timeline.
	Timeline(QWidget *parent = nullptr);
	/// Default deconstructor.
	~Timeline();
protected:
	/// Override the paint event for the
	/// widget, so that the notches can be
	/// drawn on the timeline.
	void paintEvent(QPaintEvent *paintEvent) override;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_TIMELINE_HPP
