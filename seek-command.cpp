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

#include "seek-command.hpp"

#include <QJsonObject>

namespace freedom_daw {

SeekCommand::SeekCommand() noexcept {
	unit = SeekUnit::Frame;
	unitValue = 0;
}

SeekCommand::~SeekCommand() {

}

CommandType SeekCommand::GetType() const noexcept {
	return CommandType::Seek;
}

void SeekCommand::SetFrame(unsigned int frame) noexcept {
	unit = SeekUnit::Frame;
	unitValue = frame;
}

void SeekCommand::SetBeat(unsigned int beat) noexcept {
	unit = SeekUnit::Beat;
	unitValue = beat;
}

void SeekCommand::Write(QJsonObject &jsonObject) const {
	jsonObject["command"] = "seek";
	switch (unit) {
	case SeekUnit::Frame:
		jsonObject["unit"] = "frame";
		break;
	case SeekUnit::Beat:
		jsonObject["unit"] = "beat";
		break;
	}
	jsonObject["unit-value"] = static_cast<int>(unitValue);
}

} // namespace freedom_daw
