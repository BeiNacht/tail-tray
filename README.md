# tail-tray
Tailscale tray menu and UI for Plasma Desktop

**Disclaimer** Please note that I have _no_ association what so ever with Tailscale Inc. This is a personal project and is not endorsed by Tailscale Inc. in any way or form.

### Early development
This project is in early development and is not yet ready for daily use. 
Please use at your own risk. It will have bugs and can crash. File bugs in the issues tab for any issues you find.

The Settings UI is not yet functional and is a placeholder for now. So don't expect anything to work there currently.


### Features
- Control your Tailscale connection from the tray
- Show IPs
- Show current connection status of your devices
- Set and change your Tailscale exit node

### License
GNU General Public License v3.0 - see [LICENSE](LICENSE) for more details

### Installation
Currently, you will need to build it from source yourself.
To do that, plese see the Getting started section below.

### Getting started
1. Install the following dependencies
   * Git, QT 6, cmake and a c++ compiler, for example:
      * On Ubuntu and Ubuntu based distros
         ```bash
         sudo apt install git qt6-tools-dev qt6-tools-dev-tools g++ clang cmake
         ```
     * On Fedora
        ```bash
        sudo dnf -y git g++ clang cmake install qt6-qtbase-devel qt6-qttools-devel qt6-qtbase-private-devel
        ```
      * On Arch Linux
         ```bash
         sudo pacman -S git clang cmake qt6-base qt6-tools
         ```
2. Clone the repo
3. cd into the repo `cd tail-tray`
4. Make a build directory `mkdir build`
5. cd into the build directory `cd build`
6. Run `cmake ../`
7. Run `make`
8. Run `sudo make install`
9. It will now be installed to `/usr/local/bin/tail-tray` and can be started by running `tail-tray` in a terminal or by clicking the Tail Tray icon in the launcher.

### Participating & Filing bugs
* If you would like to participate in the development of this project, please feel free to fork the repo and submit a pull request.
* If you find any bugs, please file an issue in the issues tab.

### Screenshots
![Screenshot](screenshots/launcher.png)

![Screenshot](screenshots/connected-tray.png)

![Screenshot](screenshots/disconnected-tray.png)

![Screenshot](screenshots/settings-ui.png)
