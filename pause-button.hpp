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

#ifndef FREEDOM_DAW_PAUSE_BUTTON_HPP
#define FREEDOM_DAW_PAUSE_BUTTON_HPP

#include "audio-button.hpp"

namespace freedom_daw {

class Command;

class PauseButton final : public AudioButton {
	Q_OBJECT
public:
	/// Default deconstructor.
	/// @param parent A pointer to the parent
	/// widget. In this case, the parent widget
	/// is an instance of the @ref AudioPanel class.
	PauseButton(QWidget *parent = nullptr);
	/// Default deconstructor.
	~PauseButton();
signals:
	/// Emitted when the pause button is hit.
	/// @param command The pause command.
	void Paused(const Command &command);
protected slots:
	/// Called when the button changes states.
	/// @param state The new state of the button.
	void OnToggled(bool state);
protected:
	/// Overrides the paint event handler
	/// for the audio putton, in order to
	/// draw the pause symbol.
	/// @param paintEvent The paint event
	/// information structure.
	void paintEvent(QPaintEvent *paintEvent);
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_PAUSE_BUTTON_HPP
