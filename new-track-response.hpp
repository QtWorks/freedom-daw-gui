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

#ifndef FREEDOM_DAW_NEW_TRACK_RESPONSE_HPP
#define FREEDOM_DAW_NEW_TRACK_RESPONSE_HPP

#include "response.hpp"

namespace freedom_daw {

/// Represents the response from
/// the audio driver's handling of
/// a new track command.
class NewTrackResponse final : public Response {
	/// The ID of the newly created track.
	unsigned int trackID;
public:
	/// Default constructor
	NewTrackResponse() noexcept;
	/// Default deconstructor
	~NewTrackResponse();
	/// Get the ID of the newly created track.
	unsigned int GetTrackID() const noexcept;
	/// Reads a response from a JSON object.
	/// This response also checks for a track ID.
	/// @param jsonObject The JSON object to read
	/// the response from.
	/// @returns True, if the JSON object is a valid
	/// response for a @ref NewTrackCommand. False if
	/// it is not the correct response type.
	bool Read(QJsonObject &jsonObject) override;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_NEW_TRACK_RESPONSE_HPP
