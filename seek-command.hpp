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

#ifndef FREEDOM_DAW_SEEK_COMMAND_HPP
#define FREEDOM_DAW_SEEK_COMMAND_HPP

#include "command.hpp"

namespace freedom_daw {

/// Used to indicate the type
/// of step used for moving the
/// audio head.
enum class SeekUnit {
	/// Use frames to move the audio head.
	/// A frame is a collection of samples,
	/// one from each channel. It represents
	/// the smallest piece of time in an audio
	/// clip.
	Frame,
	/// Use beats to move the audio head. This
	/// can be useful in when the user wants to
	/// recording a new audio clip.
	Beat
};

/// Used to move the audio head to
/// a different location on the timeline.
/// Used either @ref SeekCommand::SetFrame
/// or @ref SeekCommand::SetBeat to modify
/// the new position of the audio head.
class SeekCommand final : public Command {
	/// The unit used to move the audio head.
	SeekUnit unit;
	/// The value of the unit used to move
	/// the audio head.
	unsigned int unitValue;
public:
	/// Default constructor.
	SeekCommand() noexcept;
	/// Default deconstructor.
	~SeekCommand();
	/// Gets the command type.
	/// @returns Always returns @ref CommandType::Seek.
	CommandType GetType() const noexcept override;
	/// Set the frame to move to audio head to.
	/// @param f The frame index to move to.
	void SetFrame(unsigned int f) noexcept;
	/// Set the beat to move the audio head to.
	/// @param beat The beat index to move to.
	void SetBeat(unsigned int beat) noexcept;
	/// Writes the seek command to a JSON object.
	/// @param jsonObject The JSON object to write
	/// the seek command to.
	void Write(QJsonObject &jsonObject) const override;
};

} // namespace freedom_daw

#endif // FREEDOM_DAW_SEEK_COMMAND_HPP
