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

#include "stdio-driver.hpp"

#include "command.hpp"
#include "response.hpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

#include <iostream>

namespace freedom_daw {

StdioDriver::StdioDriver() noexcept {

}

StdioDriver::~StdioDriver() {

}

void StdioDriver::Close() {

}

bool StdioDriver::Read(Response &response) {

	std::string source;

	while (!std::cin.eof()) {
		std::string line;
		std::getline(std::cin, line);
		if (line.size() == 0) {
			break;
		} else {
			source += line;
		}
	}

	auto jsonDoc = QJsonDocument::fromRawData(source.data(), source.size());

	auto jsonObject = jsonDoc.object();

	return response.Read(jsonObject);
}

void StdioDriver::Write(const Command &command) {

	QJsonObject jsonCommand;
	command.Write(jsonCommand);

	QJsonDocument jsonDoc(jsonCommand);

	QString commandString(jsonDoc.toJson(QJsonDocument::Indented));

	std::cout << commandString.toStdString() << std::endl;
}

} // namespace freedom_daw
