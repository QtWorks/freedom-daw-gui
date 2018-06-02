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

#ifndef FREEDOM_DAW_RESPONSE_HPP
#define FREEDOM_DAW_RESPONSE_HPP

class QJsonObject;

namespace freedom_daw {

/// Indicates whether or not a driver
/// responded to a command with failure.
enum class ResponseCode {
	/// Driver responded without failure.
	Success,
	/// Driver responded with failure.
	Failure
};

/// Encapsulates a response sent from
/// the driver.
class Response {
public:
	/// Default constructor
	Response() noexcept;
	/// Default deconstructor
	virtual ~Response();
	/// Gets the response type.
	/// @returns The response type.
	ResponseCode GetCode() const noexcept;
	/// Reads a response from a JSON object.
	/// @param jsonObject The JSON object to
	/// read the response from.
	/// @returns This function always returns
	/// true for this class. In derived classes,
	/// this function will return true only if
	/// the JSON object corresponds to the derived
	/// response class.
	virtual bool Read(QJsonObject &jsonObject);
	/// Returns true if the code matches
	/// the one specified.
	/// @param code_ The code to check for.
	bool operator == (ResponseCode code_) const noexcept;
	/// Returns false if the code matches
	/// the one specified.
	/// @param code_ The code to check for.
	bool operator != (ResponseCode code_) const noexcept;
private:
	/// The response code sent from the driver.
	ResponseCode code;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_RESPONSE_HPP
