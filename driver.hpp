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

#ifndef FREEDOM_DAW_DRIVER_HPP
#define FREEDOM_DAW_DRIVER_HPP

namespace freedom_daw {

class Response;
class Command;

/// Used to connect to the entity
/// that plays and records the audio.
class Driver {
public:
	/// Default deconstructor
	virtual ~Driver();
	/// Closes the driver.
	virtual void Close() = 0;
	/// Writes a command to the driver.
	/// @param command The command to write.
	virtual void Write(const Command &command) = 0;
	/// Reads a response from the driver.
	/// @param resonse The response to read.
	/// @returns True if the response is the
	/// correct type, false if it is not.
	virtual bool Read(Response &response) = 0;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_DRIVER_HPP
