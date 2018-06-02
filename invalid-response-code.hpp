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

#ifndef FREEDOM_DAW_INVALID_RESPONSE_CODE_HPP
#define FREEDOM_DAW_INVALID_RESPONSE_CODE_HPP

#include "exception.hpp"

#include <QString>

namespace freedom_daw {

/// Represents an invalid response code received
/// from the audio driver. Note that this is
/// different from a failed response. An invalid
/// response code means the response code from the
/// audio driver was not understood.
class InvalidResponseCode final : public Exception {
	/// The invalid response code
	QString responseCode;
public:
	/// Default constructor
	InvalidResponseCode(QString &&responseCode_) noexcept;
	/// Default deconstructor
	~InvalidResponseCode();
	/// Gets the invalid response code
	/// that was received from the audio driver.
	/// @returns The invalid response code.
	const QString &GetResponseCode() const noexcept;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_INVALID_RESPONSE_CODE_HPP
