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

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QList>

#include <fstream>
#include <iostream>

#include <cstdlib>

namespace {

/// The driver class, used for
/// handling commands issued by
/// the interface.
class Driver final {
	/// Used for logging events.
	std::ostream &log;
	/// Used to write to the graphical interface.
	std::ostream &output;
	/// Used for reading from the graphical interface.
	std::istream &input;
public:
	/// Default constructor.
	Driver(std::ostream &log_) noexcept;
	/// Default deconstructor.
	~Driver();
	/// Runs the test driver.
	void Run();
protected:
	/// Gets a command from the
	/// standard input.
	/// @param jsonObject The JSON object
	/// to put the command into.
	bool GetCommand(QJsonObject &jsonObject);
};

} // namespace

int main() {

	std::ofstream logFile("log.txt");

	Driver driver(logFile);

	driver.Run();

	return EXIT_SUCCESS;
}

namespace {

Driver::Driver(std::ostream &log_) noexcept : log(log_), output(std::cout), input(std::cin) {

}

Driver::~Driver() {

}

void Driver::Run() {

	for (;;) {

		QJsonObject jsonObject;

		if (!GetCommand(jsonObject)) {
			break;
		}

		if (jsonObject.empty()) {
			log << "Received an empty command." << std::endl;
		} else if (jsonObject["command"] == "quit") {
			log << "Received quit command." << std::endl;
			break;
		} else {
			log << "Received a '" << jsonObject["command"].toString().toStdString() << "' command." << std::endl;
			// TODO
		}
	}
}

bool Driver::GetCommand(QJsonObject &jsonObject) {

	std::string source;

	while (!input.eof()) {
		std::string line;
		std::getline(input, line);
		if (line.size() == 0) {
			break;
		} else {
			source += line;
		}
	}

	if (source.size() == 0)
		return false;

	QByteArray sourceByteArray(source.data(), source.size());

	auto jsonDoc = QJsonDocument::fromJson(sourceByteArray);

	jsonObject = jsonDoc.object();

	return true;
}

} // namespace
