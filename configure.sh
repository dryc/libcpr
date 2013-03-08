#/bin/sh
#export CC='gcc -std=c1x'
#export CXX='g++ -std=c++11'
export CC='clang -std=c1x'
export CXX='clang++ -std=c++11'
export CPPFLAGS=''
export CFLAGS='-g -Os'
export CXXFLAGS='-g -Os'
export LDFLAGS=''
./configure $*
