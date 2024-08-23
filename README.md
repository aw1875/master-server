[![build](https://github.com/alterware/master-server/workflows/Build/badge.svg)](https://github.com/alterware/master-server/actions)


# AlterWare: Master Server
This is the master server our clients use. It is based on the DP Master Server (ID Tech) protocol

## Usage
Run using [Docker][docker-link]

```bash
docker run -p 20810:20810/udp alterware/master-server:latest
```

## Build
- Clone this repository using [Git][git-link]
- Run the appropriate setup script based on your operating system:
    - Windows: `.\scripts\windows\setup.bat`
    - Linux: `./scripts/linux/setup.sh`

**IMPORTANT**
Requirements for Unix systems:
- Compilation: Please use Clang as the preferred compiler
- Dependencies: Ensure the LLVM C++ Standard library is installed
- Alternative compilers: If you opt for a different compiler such as GCC, use the [Mold][mold-link] linker
- Customization: Modifications to the Premake5.lua script may be required
- Platform support: Details regarding supported platforms are available in [build.yml][build-link]

[docker-link]:            https://www.docker.com
[premake5-link]:          https://premake.github.io
[git-link]:               https://git-scm.com
[mold-link]:              https://github.com/rui314/mold
[build-link]:             https://github.com/alterware/master-server/blob/master/.github/workflows/build.yml
