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

#ifndef FREEDOM_DAW_AUDIO_PANEL_HPP
#define FREEDOM_DAW_AUDIO_PANEL_HPP

#include <QFrame>

class QGridLayout;

namespace freedom_daw {

class RecordButton;

/// Responsible for containing the audio control buttons.
class AudioPanel final : public QFrame {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the parent widget.
	AudioPanel(QWidget *parent);
	/// Default deconstructor
	~AudioPanel();
private:
	/// Signals to the application to start recording audio.
	RecordButton *recordButton;
	/// The layout for the buttons on the audio panel.
	QGridLayout *layout;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_AUDIO_PANEL_HPP
