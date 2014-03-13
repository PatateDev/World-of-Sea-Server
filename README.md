World-of-Sea-Server
===================

Dependencies
------------
In order to compile the server, you need :

* [SFML 2.1+](http://sfml-dev.org/download/sfml/2.1/index.php)
* [MySQL Client Library (bundled with MySQL Client)](https://dev.mysql.com/downloads/mysql/) (available in some linux's repositories : [libmysqlclient-dev](https://packages.debian.org/stable/libmysqlclient-dev) on Debian)

How to run - GNU/Linux
-----------------------
1. Make sure you have the library MySQL Client installed, whether :
     + package `libmysqlclient18` (18 is package's version) is installed
     + libmysqlclient.so available in your LD_LIBRARY_PATH (e.g in the lib folder)
2. Put SFML's libraries in a `lib` folder
3. Create a shell script named `run.sh` with :
     + `#!/bin/bash`
     + `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib`
     + `./world-of-sea-server <username> <password> <address> <database>`
4. Replace the `<>` by MySQL database's settings
5. Launch `run.sh`

How to run - Windows
---------------------
1. Make sure you have the library MySQL Client installed, whether :
    + `libmysql.dll` is present in the same folder that `world-of-sea-server.exe`
    + `libmysql.dll` is available in your PATH
2. Make sure you have the SFML libraries installed, whether :
    + `libsfml-network.dll` and `libsfml-system.dll`are present in the same folder that `world-of-sea-server.exe`
    + both are available in your PATH
3. Create a batch script named `run.sh` with :
    + `start world-of-sea-server.exe <username> <password> <address> <database>`
4. Replace the `<>` by MySQL database's settings
5. Launch `run.bat`
