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

#ifndef FREEDOM_DAW_RECORD_BUTTON_HPP
#define FREEDOM_DAW_RECORD_BUTTON_HPP

#include "audio-button.hpp"

#include <QColor>

class QGraphicsBlurEffect;

namespace freedom_daw {

class Command;

/// Created to allow the user a
/// way to begin recording audio.
class RecordButton final : public AudioButton {
	Q_OBJECT
	Q_PROPERTY(QColor circleColor WRITE SetCircleColor)
public:
	/// Default constructor.
	/// @param parent A pointer to
	/// the parent widget.
	RecordButton(QWidget *parent);
	/// Default deconstructor.
	~RecordButton();
	/// Sets the color of the inner circle
	/// of the record button. This is usually
	/// a shade of the color red.
	/// @param color The color to assign the inner
	/// circle in the record button.
	void SetCircleColor(const QColor &color);
signals:
	/// Emitted when the record button either gets
	/// checked or unchecked.
	/// @param command The command emitted from the button.
	void NewCommand(const Command &command);
protected slots:
	/// Used to handle when the button changes state.
	/// This function emits a command based on the new
	/// state of the button.
	void OnToggled(bool state);
protected:
	/// An override of the paint event.
	/// This override is used to draw the
	/// red circle of the record button.
	/// @param paintEvent A pointer to the
	/// paint event information class.
	void paintEvent(QPaintEvent *paintEvent) override;
private:
	/// The color of the inner circle.
	QColor circleColor;
	/// A pointer to the blur effect, which
	/// takes place while the button is checked.
	QGraphicsBlurEffect *blurEffect;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_RECORD_BUTTON_HPP
