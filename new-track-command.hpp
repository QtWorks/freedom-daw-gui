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

#ifndef FREEDOM_DAW_NEW_TRACK_COMMAND_HPP
#define FREEDOM_DAW_NEW_TRACK_COMMAND_HPP

#include "command.hpp"

namespace freedom_daw {

class NewTrackCommand final : public Command {
public:
	/// Default constructor
	NewTrackCommand() noexcept;
	/// Default deconstructor
	~NewTrackCommand();
	/// Returns @ref CommandType::NewTrack, indicating
	/// that this is a new track command.
	CommandType GetType() const noexcept override;
	/// Writes the command to a JSON object.
	/// @param jsonObject The JSON object to write the command to.
	void Write(QJsonObject &jsonObject) const override;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_NEW_TRACK_COMMAND_HPP
