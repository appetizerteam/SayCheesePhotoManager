# SayCheese Photo Manager

>SayCheese Photo Manager is a cross-platform C++11 Qt GUI Desktop application for transferring photos from the SayCheese Android and iOS apps.

### Version
1.0

### Platforms Supported
 - Linux
 - Mac OSX
 - Windows

### Technologies Used
 - [QCustomPlot] - For plotting daily photo activity.
 - Qt 5 - For creating cross-platform GUIs.
 - Custom Cross-Platform Automatic Device Pairing - No ZeroConf needed!
 - Custom Qt Widgets - Custom Colored Image Mask Button, Spinner and Screen Transition Manager.
 - C++11 - Because Smart Pointers Rock.

# Building Instructions
```sh
 $ git clone https://github.com/appetizerteam/SayCheesePhotoManager.git
 $ cd SayCheesePhotoManager
 $ qmake
 $ make
```

# Features
#### Simple User Interface
![alt text](https://github.com/jealas/AllProjectsMarkdownResources/blob/master/SayCheesePhotoManager/MainScreen.png "Main Screen")

#### User Settings
![alt text](https://github.com/jealas/AllProjectsMarkdownResources/blob/master/SayCheesePhotoManager/Settings.png "Settings")

#### Android and iOS Support
![alt text](https://github.com/jealas/AllProjectsMarkdownResources/blob/master/SayCheesePhotoManager/DeviceSelection.png "Device Selection")

#### Wired and Wireless Photo Transfers
 - Wired photo transfers are only supported on Android platform.
 - Wireless photo transfers are supported on both Android and iOS.
![alt text](https://github.com/jealas/AllProjectsMarkdownResources/blob/master/SayCheesePhotoManager/ConnectionType.png "Connection Type")

#### Automatic Device Pairing
 - Custom protocol developed for automatic device pairing.
 - No ZeroConf or other dependencies needed.
![alt text](https://github.com/jealas/AllProjectsMarkdownResources/blob/master/SayCheesePhotoManager/Searching.png "Device Selection")

#### About Screen
![alt text](https://github.com/jealas/AllProjectsMarkdownResources/blob/master/SayCheesePhotoManager/AboutScreen.png "Device Selection")



### Todo's

 - Organize Project Structure: add 'src' and 'include' directories.
 - Write GTest tests
 - Add Doxygen documentation
 - Create program launcher and updater.

License
----

[Apache 2.0]

[QCustomPlot]:http://www.qcustomplot.com/
[Apache 2.0]:http://www.apache.org/licenses/LICENSE-2.0
