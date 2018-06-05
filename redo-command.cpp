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

#include "redo-command.hpp"

#include <QJsonObject>

namespace freedom_daw {

RedoCommand::RedoCommand() noexcept {

}

RedoCommand::~RedoCommand() {

}

CommandType RedoCommand::GetType() const noexcept {
	return CommandType::Redo;
}

void RedoCommand::Write(QJsonObject &jsonObject) const {
	jsonObject["command"] = "redo";
}

} // namespace freedom_daw
