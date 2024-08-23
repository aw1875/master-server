#!/usr/bin/env bash

SCRIPT_DIR=$(cd $(dirname $0); pwd)

git submodule update --init --recursive
$SCRIPT_DIR/../../tools/premake5 gmake2
