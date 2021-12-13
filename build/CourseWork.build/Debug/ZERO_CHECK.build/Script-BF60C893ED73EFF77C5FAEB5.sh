#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/pavelelandaev/Documents/GitHub/CourseWork/build
  make -f /Users/pavelelandaev/Documents/GitHub/CourseWork/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/pavelelandaev/Documents/GitHub/CourseWork/build
  make -f /Users/pavelelandaev/Documents/GitHub/CourseWork/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/pavelelandaev/Documents/GitHub/CourseWork/build
  make -f /Users/pavelelandaev/Documents/GitHub/CourseWork/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/pavelelandaev/Documents/GitHub/CourseWork/build
  make -f /Users/pavelelandaev/Documents/GitHub/CourseWork/build/CMakeScripts/ReRunCMake.make
fi

