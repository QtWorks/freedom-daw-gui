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

#ifndef FREEDOM_DAW_STOP_BUTTON_HPP
#define FREEDOM_DAW_STOP_BUTTON_HPP

#include "audio-button.hpp"

namespace freedom_daw {

/// Used for the user to be able to
/// stop audio from playing.
class StopButton final : public AudioButton {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the parent
	/// widget, which is a @ref AudioPanel widget.
	StopButton(QWidget *parent = nullptr);
	/// Default deconstructor.
	~StopButton();
protected:
	/// Paints the stop button.
	/// @param paintEvent A pointer to the
	/// paint event information class.
	void paintEvent(QPaintEvent *paintEvent) override;
private:
	/// The color of the square icon.
	QColor squareColor;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_STOP_BUTTON_HPP
