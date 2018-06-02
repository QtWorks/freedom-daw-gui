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

class Command;
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
public slots:
	/// Used for connecting to new command signals
	/// from the buttons in the audio panel. All this
	/// function does is relay the command to the parent
	/// class.
	/// @param command The command received.
	void OnCommand(const Command &command);
signals:
	/// Emitted when a control on the audio
	/// panel triggers a command.
	/// @param command The command to emit.
	void NewCommand(const Command &command);
private:
	/// Signals to the application to start recording audio.
	RecordButton *recordButton;
	/// The layout for the buttons on the audio panel.
	QGridLayout *layout;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_AUDIO_PANEL_HPP
