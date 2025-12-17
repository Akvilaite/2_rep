# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-src")
  file(MAKE_DIRECTORY "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-build"
  "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/akvil/OneDrive/Desktop/koduxai/objektinis/1 uzduotis/vo2/git/2_rep/3 strategija/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
