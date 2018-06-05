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

#ifndef FREEDOM_DAW_EDIT_MENU_HPP
#define FREEDOM_DAW_EDIT_MENU_HPP

#include <QMenu>

namespace freedom_daw {

class Command;

/// Used for modifying the project
/// in some way that is not handled
/// by the track manager.
class EditMenu final : public QMenu {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param parent A pointer to the
	/// parent widget. In this case, that
	/// is a pointer to an instance of the
	/// @ref MenuBar class.
	EditMenu(QWidget *parent = nullptr);
	/// Default deconstructor.
	~EditMenu();
signals:
	/// Emitted when an option from the drop down
	/// menu is clicked.
	/// @param command The command that corresponds
	/// to the option from the drow down menu.
	void NewCommand(const Command &command);
protected slots:
	/// Called when "Redo" is clicked.
	void OnRedoTriggered();
	/// Called when "Undo" is clicked.
	void OnUndoTriggered();
private:
	/// The "Redo" button.
	QAction *redo;
	/// The "Undo" button.
	QAction *undo;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_EDIT_MENU_HPP
