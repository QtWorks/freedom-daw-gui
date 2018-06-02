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

#ifndef FREEDOM_DAW_CENTRAL_WIDGET_HPP
#define FREEDOM_DAW_CENTRAL_WIDGET_HPP

#include <QWidget>

class QGridLayout;

namespace freedom_daw {

class AudioPanel;
class Command;
class TrackManager;

/// Contains all the child widgets in
/// the central widget, which is contained
/// by the main window.
class CentralWidget final : public QWidget {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the main window widget.
	CentralWidget(QWidget *parent = nullptr);
	/// Default deconstructor.
	~CentralWidget();
	/// Adds a track to the track manager.
	/// @param trackID The ID of the newly
	/// created track.
	void AddTrack(unsigned int trackID);
signals:
	/// Emitted when either the track manager
	/// or audio panel triggers a new command.
	/// @param command The command that was trigged.
	void NewCommand(const Command &command);
protected:
	/// Called when either the track manager or
	/// the audio panel triggers a new command.
	/// @param command The command that was trigged.
	void OnCommand(const Command &command);
private:
	/// A pointer to the audio controls panel.
	AudioPanel *audioPanel;
	/// A pointer to the track manager widget.
	TrackManager *trackManager;
	/// A pointer to the layout of the central widget.
	QGridLayout *layout;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_CENTRAL_WIDGET_HPP
