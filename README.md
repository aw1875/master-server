[![build](https://github.com/alterware/master-server/workflows/Build/badge.svg)](https://github.com/alterware/master-server/actions)


# AlterWare: Master Server (H2M)
This is a modified version the master server AlterWare clients use to add H2M support. It is based on the DP Master Server (ID Tech) protocol

## Build
- Clone this repository using [Git][git-link]
- Run the appropriate setup script based on your operating system:
    - Windows: `.\scripts\windows\setup.bat`
    - Linux: `./scripts/linux/setup.sh`
- Run the corresponding build script:
    - Windows: `.\scripts\windows\build.bat` (note: Visual Studio is required)
        - This script may not work. If it doesn't, please use the Visual Studio IDE to build
    - Linux: `./scripts/linux/build.sh`

## Setup
You can optionally configure the title, stats path, and port by adding a config.json file at the same level as your compiled executable. The file should look like this:
```json
{
    "title": "AlterWare Master",
    "stats_path": "/var/www/server.alterware.dev/html/stats.json",
    "port": 20810
}
```

**IMPORTANT**
Requirements for Unix systems:
- Compilation: Please use Clang as the preferred compiler
- Dependencies: Ensure the LLVM C++ Standard library is installed
- Alternative compilers: If you opt for a different compiler such as GCC, use the [Mold][mold-link] linker
- Customization: Modifications to the Premake5.lua script may be required

[git-link]:               https://git-scm.com
[mold-link]:              https://github.com/rui314/mold
