#!/usr/bin/env bash
# Builds every assignment into build/. The two programs that use windows.h are only built on Windows.
set -euo pipefail

cd "$(dirname "$0")"
mkdir -p build

case "$(uname -s)" in
  MINGW* | MSYS* | CYGWIN*) on_windows=1 ;;
  *) on_windows=0 ;;
esac
windows_only=" 04-shapes-oop 05-mouse-island-game "

failed=0
for dir in [0-9][0-9]-*/; do
  name="${dir%/}"
  if [ "$on_windows" -eq 0 ] && [[ "$windows_only" == *" $name "* ]]; then
    echo "skip   $name (needs Windows)"
    continue
  fi

  sources=("$name/main.cpp")
  flags=()
  if [ -d "$name/src" ]; then
    sources+=("$name"/src/*.cpp)
    flags+=("-I$name/include")
  fi

  if g++ -std=c++17 -Wall -O2 "${flags[@]}" "${sources[@]}" -o "build/$name"; then
    echo "built  $name"
  else
    echo "FAILED $name"
    failed=1
  fi
done

exit "$failed"
