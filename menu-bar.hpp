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

#ifndef FREEDOM_DAW_MENU_BAR_HPP
#define FREEDOM_DAW_MENU_BAR_HPP

#include <QMenuBar>

class QMenu;

namespace freedom_daw {

class Command;
class FileMenu;
class HelpMenu;
class TrackMenu;

class MenuBar : public QMenuBar {
	Q_OBJECT
public:
	MenuBar(QWidget *parent = nullptr);
	~MenuBar();
signals:
	void NewCommand(const Command &command);
public slots:
	void OnCommand(const Command &command);
private:
	QMenu *editMenu;
	QMenu *viewMenu;
	FileMenu *fileMenu;
	HelpMenu *helpMenu;
	TrackMenu *trackMenu;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_MENU_BAR_HPP
