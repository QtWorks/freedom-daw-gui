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

#ifndef FREEDOM_DAW_VIEW_MENU_HPP
#define FREEDOM_DAW_VIEW_MENU_HPP

#include <QMenu>

namespace freedom_daw {

/// Used for allowing the user
/// to change the user interface.
class ViewMenu final : public QMenu {
	Q_OBJECT
public:
	/// Default constructor.
	/// @param widget A pointer to the parent
	/// widget. Usually, this is the menu bar.
	ViewMenu(QWidget *parent = nullptr);
	/// Default deconstructor.
	~ViewMenu();
private:
	/// Puts the window into full screen mode.
	QAction *fullScreen;
	/// Used for changing the color scheme.
	QAction *colorScheme;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_VIEW_MENU_HPP
