require 'formula'

class Libcpr < Formula
  homepage 'http://libcpr.org/'
  head 'https://github.com/dryproject/libcpr.git', :using => :git

  option 'enable-debug', "Build with debugging support"

  depends_on :autoconf => :build
  depends_on :automake => :build
  depends_on :libtool  => :build

  def install
    system './autogen.sh' if build.head?

    args = ["--prefix=#{prefix}", '--disable-dependency-tracking']
    args << '--enable-debug' if build.include?('enable-debug')
    args << '--with-stdlib=libc++' # required for full C++11 support
    system './configure', *args

    system 'make install'
  end
end
