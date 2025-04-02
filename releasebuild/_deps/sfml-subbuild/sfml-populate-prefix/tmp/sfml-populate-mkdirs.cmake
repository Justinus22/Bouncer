# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-src"
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-build"
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/i589228/data/hwr/s4/c++/Bouncer/Release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
