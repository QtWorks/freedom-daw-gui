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

#include "process-driver.hpp"

#include "command.hpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>

namespace freedom_daw {

ProcessDriver::ProcessDriver() {
	process = new QProcess();
}

ProcessDriver::~ProcessDriver() {
	if (process != nullptr) {
		delete process;
		process = nullptr;
	}
}

void ProcessDriver::Close() {
	if (process != nullptr) {
		process->waitForFinished();
	}
}

void ProcessDriver::Start(const QString &path) {
	process->start(path);
}

bool ProcessDriver::Read(Response &response) {
	(void) response;
	return false;
}

void ProcessDriver::Write(const Command &command) {

	QJsonObject jsonCommand;

	command.Write(jsonCommand);

	QJsonDocument jsonDoc(jsonCommand);

	QString commandString(jsonDoc.toJson(QJsonDocument::Indented));

	process->write(commandString.toUtf8());
	process->write("\n");

	process->waitForBytesWritten();
}

} // namespace freedom_daw
