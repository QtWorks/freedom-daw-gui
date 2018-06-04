Freedom DAW GUI
===============

This is the graphical front end to the Freedom DAW project.
The graphical front end is one half of the project.
The other half is the driver component, which manages projects and audio streams.
They communicate via IPC mechanisms, using JSON.

### Building

Build on the latest Ubuntu.
As of writing this, the latest version of Ubuntu is 18.04.
While most of the code (if not all of it) is platform independent, it isn't tested on other systems.
If you'd like to help support it for another system, please send pull requests when needed.

### Dependencies

The Qt framework is used to design the interface, so that is required for the build.
CMake is used to build the project, that is needed to.
Try using the following command to install these dependencies.

```
sudo apt install cmake qtbase5-dev
```
