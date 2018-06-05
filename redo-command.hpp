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

#ifndef FREEDOM_DAW_REDO_COMMAND_HPP
#define FREEDOM_DAW_REDO_COMMAND_HPP

#include "command.hpp"

namespace freedom_daw {

/// Used to redo the last command
/// that was undone.
class RedoCommand final : public Command {
public:
	/// Default constructor.
	RedoCommand() noexcept;
	/// Default deconstructor.
	~RedoCommand();
	/// Gets the command type.
	/// @returns This function always returns @ref CommandType::Redo.
	CommandType GetType() const noexcept override;
	/// Writes the redo command to a JSON object.
	/// @param jsonObject The JSON object to write to.
	void Write(QJsonObject &jsonObject) const override;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_REDO_COMMAND_HPP
