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

#ifndef FREEDOM_DAW_STDIO_DRIVER_HPP
#define FREEDOM_DAW_STDIO_DRIVER_HPP

#include "driver.hpp"

namespace freedom_daw {

/// Used to communicate commands and
/// responses by using the standard input
/// and output files of the running process.
class StdioDriver final : public Driver {
public:
	/// Default constructor.
	StdioDriver() noexcept;
	/// Default deconstructor.
	~StdioDriver();
	/// Closes the standard IO driver.
	void Close() override;
	/// Reads a response 
	bool Read(Response &response) override;
	/// Sends a command to the audio driver.
	/// @param command The command to send to the driver.
	void Write(const Command &command) override;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_STDIO_DRIVER_HPP
