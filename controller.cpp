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

#include "controller.hpp"

#include "command.hpp"
#include "exception.hpp"
#include "invalid-response-code.hpp"
#include "main-window.hpp"
#include "new-track-response.hpp"
#include "process-driver.hpp"
#include "stdio-driver.hpp"
#include "quit-command.hpp"

#include <QErrorMessage>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

namespace freedom_daw {

Controller::Controller(QObject *parent) : QObject(parent) {

	mainWindow = new MainWindow();

	connect(mainWindow, &MainWindow::NewCommand, this, &Controller::OnCommand);

	driver = nullptr;
}

Controller::~Controller() {

	if (mainWindow != nullptr)
		delete mainWindow;

	if (driver != nullptr)
		delete driver;
}

void Controller::CloseDriver() {

	QuitCommand quitCommand;

	OnCommand(quitCommand);
}

void Controller::LoadScheme(const QString &path) {

	QFile file(path);
	file.open(QIODevice::ReadOnly |  QIODevice::Text);

	QString fileSource = file.readAll();

	file.close();

	QJsonDocument jsonDocument = QJsonDocument::fromJson(fileSource.toUtf8());

	auto scheme = jsonDocument.object();

	mainWindow->ImportScheme(scheme);
}

void Controller::ResizeMainWindow(int width, int height) {
	mainWindow->resize(width, height);
}

void Controller::ShowMainWindow() {
	mainWindow->show();
}

void Controller::UseProcessDriver(const QString &path) {

	if (driver != nullptr)
		delete driver;

	auto processDriver = new ProcessDriver();

	processDriver->Start(path);

	driver = processDriver;
}

void Controller::UseStdioDriver() {

	if (driver != nullptr)
		delete driver;

	driver = new StdioDriver();
}

void Controller::OnCommand(const Command &command) {

	if (driver == nullptr)
		return;

	driver->Write(command);

	switch (command.GetType()) {
	case CommandType::CloseProject:
		break;
	case CommandType::DeleteTrack:
		break;
	case CommandType::NewProject:
		break;
	case CommandType::NewTrack:
		ReadNewTrackResponse();
		break;
	case CommandType::OpenProject:
		break;
	case CommandType::Pause:
		break;
	case CommandType::Play:
		break;
	case CommandType::Redo:
		break;
	case CommandType::Record:
		break;
	case CommandType::Seek:
		break;
	case CommandType::Undo:
		break;
	case CommandType::Quit:
		driver->Close();
		break;
	}
}

void Controller::ReadNewTrackResponse() {

	NewTrackResponse response;

	try {
		driver->Read(response);
	} catch (const InvalidResponseCode &) {
		QErrorMessage errorMessage;
		errorMessage.showMessage("Invalid response code received from driver.");
		errorMessage.exec();
		return;
	}

	mainWindow->AddTrack(response.GetTrackID());
}

} // namespace freedom_daw
