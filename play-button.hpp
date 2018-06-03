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

#ifndef FREEDOM_DAW_PLAY_BUTTON_HPP
#define FREEDOM_DAW_PLAY_BUTTON_HPP

#include "audio-button.hpp"

#include <QColor>

namespace freedom_daw {

class Command;

/// Used to allow the user to play the project.
class PlayButton final : public AudioButton {
	Q_OBJECT
	Q_PROPERTY(QColor activeColor WRITE SetActiveColor)
	Q_PROPERTY(QColor inactiveColor WRITE SetInactiveColor)
public:
	/// Default constructor.
	/// @param parent A pointer to the parent widget.
	PlayButton(QWidget *parent = nullptr);
	/// Default deconstructor.
	~PlayButton();
	/// Sets the color of the inner triangle
	/// when the play button is active.
	/// @param color The active color
	/// for the inner triangle.
	void SetActiveColor(const QColor &color);
	/// Sets the color of the inner triangle
	/// when the play button is inactive.
	/// @param color The inactive color
	/// for the inner triangle.
	void SetInactiveColor(const QColor &color);
protected slots:
	/// Called when the button state changes.
	/// @param state Indicates whether the button
	/// is in an active state or not.
	void OnToggled(bool state);
signals:
	/// Emitted when the play button changes
	/// state. The command type depends on whether
	/// or not the new button state is active or inactive.
	/// @param A reference to the command base class.
	void NewCommand(const Command &command);
protected:
	/// Handles the paint event for the play button.
	/// This is used to draw the triangle.
	void paintEvent(QPaintEvent *) override;
private:
	/// The color used for the triangle when
	/// the button is active.
	QColor activeColor;
	/// The color used for the triangle when
	/// the button is inactive.
	QColor inactiveColor;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_PLAY_BUTTON_HPP
