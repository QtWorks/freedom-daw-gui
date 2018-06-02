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

#ifndef FREEDOM_DAW_COMMAND_HPP
#define FREEDOM_DAW_COMMAND_HPP

class QJsonObject;

namespace freedom_daw {

/// Lists the possible derived
/// classes of the command class.
enum class CommandType {
	/// Used when creating a new track.
	NewTrack,
	/// Used when deleting a track.
	DeleteTrack,
	/// Used to start recording.
	RecordStart,
	/// Used to stop recording.
	RecordStop
};

/// Used to represent a command to be
/// passed to the audio driver.
class Command {
public:
	/// Default deconstructor.
	virtual ~Command();
	/// Gets the type, indicating the derived
	/// class of the command class.
	/// @returns The command type.
	virtual CommandType GetType() const noexcept = 0;
	/// Writes the command data to a JSON object.
	/// @param jsonObject The JSON object to add the command to.
	virtual void Write(QJsonObject &jsonObject) const = 0;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_COMMAND_HPP
