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

#include "edit-menu.hpp"

#include "redo-command.hpp"
#include "undo-command.hpp"

namespace freedom_daw {

EditMenu::EditMenu(QWidget *parent) : QMenu(parent) {

	undo = addAction(tr("Undo"));
	undo->setShortcut(Qt::Key_Z | Qt::CTRL);

	redo = addAction(tr("Redo"));
	redo->setShortcut(Qt::Key_Z | Qt::SHIFT | Qt::CTRL);

	preferences = addAction(tr("Preferences"));

	connect(undo, &QAction::triggered, this, &EditMenu::OnUndoTriggered);
	connect(redo, &QAction::triggered, this, &EditMenu::OnRedoTriggered);

	setTitle(tr("Edit"));
}

EditMenu::~EditMenu() {

}

void EditMenu::OnRedoTriggered() {

	RedoCommand redoCommand;

	emit NewCommand(redoCommand);
}

void EditMenu::OnUndoTriggered() {

	UndoCommand undoCommand;

	emit NewCommand(undoCommand);
}

} // namespace freedom_daw
