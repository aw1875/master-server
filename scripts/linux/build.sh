#!/usr/bin/env bash

SCRIPT_DIR=$(cd $(dirname $0); pwd)

ARCH=${1:-x64}
VALID_ARCHS=("x64" "x86" "arm64")
[[ ! " ${VALID_ARCHS[@]} " =~ " ${ARCH} " ]] && echo "Invalid arch: ${ARCH}. Valid archs: ${VALID_ARCHS[@]}" && exit 1

CONFIG=${2:-release}
VALID_CONFIGS=("debug" "release")
[[ ! " ${VALID_CONFIGS[@]} " =~ " ${CONFIG} " ]] && echo "Invalid config: ${CONFIG}. Valid configs: ${VALID_CONFIGS[@]}" && exit 1

[[ ! -d $SCRIPT_DIR/../../build ]] && echo "Please run the ./scripts/linux/setup.sh first" && exit 1

echo "Building ${CONFIG}_${ARCH} for Linux"
cd $SCRIPT_DIR/../../build
make config="${CONFIG}_${ARCH}" -j$(nproc)
cd -
