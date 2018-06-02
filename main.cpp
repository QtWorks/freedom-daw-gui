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

#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QString>

#include "controller.hpp"
#include "invalid-response-code.hpp"

#include <iostream>

#include <cstdlib>

namespace {

int LoadStyleSheet(QApplication &app, const QString &path) {

	QFile file(path);

	file.open(QIODevice::ReadOnly);

	QString styleSheet(file.readAll());

	app.setStyleSheet(styleSheet);

	return 0;
}

int SetupWindowView(QApplication &app,
                    freedom_daw::Controller &controller) {

	auto screenRect = app.desktop()->screenGeometry();

	controller.ResizeMainWindow(screenRect.width() / 2,
	                            screenRect.height() / 2);

	return 0;
}

int Main(int argc, char **argv) {

	QApplication app(argc, argv);

	LoadStyleSheet(app, "://stylesheets/default.qss");

	freedom_daw::Controller controller;

	controller.UseStdioDriver();
	controller.ShowMainWindow();

	SetupWindowView(app, controller);

	return app.exec();
}

} // namespace

int main(int argc, char **argv) {

	int exitCode = EXIT_SUCCESS;

	try {
		exitCode = Main(argc, argv);
	} catch (const freedom_daw::InvalidResponseCode &invalidResponseCode) {
		std::cerr << "Received invalid response code, \"";
		std::cerr << invalidResponseCode.GetResponseCode().toStdString();
		std::cerr << "\", from audio driver." << std::endl;
		return EXIT_FAILURE;
	} catch (const freedom_daw::Exception &exception) {
		std::cerr << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	return exitCode;
}
