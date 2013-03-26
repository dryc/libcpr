#/bin/sh
#export CC='gcc'
#export CXX='g++'
export CC='clang'
export CXX='clang++ --stdlib=libc++'
export CPPFLAGS=''
export CFLAGS='-g -Os'
export CXXFLAGS='-g -Os'
export LDFLAGS=''
./configure $*
