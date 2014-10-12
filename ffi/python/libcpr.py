#!/usr/bin/env python
# This is free and unencumbered software released into the public domain.

from ctypes import CDLL, c_bool, c_char_p, c_short, c_size_t
from ctypes.util import find_library

try:
  libcpr = CDLL('libcpr.so.0')
except OSError:
  libcpr_path = find_library('cpr')
  if libcpr_path:
    libcpr = CDLL(libcpr_path)
  else:
    raise OSError('libcpr shared library not found')

VERSION_STRING = c_char_p.in_dll(libcpr, 'cpr_version_string').value
VERSION_MAJOR  = c_short.in_dll(libcpr, 'cpr_version_major').value
VERSION_MINOR  = c_short.in_dll(libcpr, 'cpr_version_minor').value
VERSION_PATCH  = c_short.in_dll(libcpr, 'cpr_version_patch').value

def version_string(): return VERSION_STRING

has_feature = libcpr.cpr_feature_exists
has_feature.argtypes = [c_char_p]
has_feature.restype = c_bool

has_module = libcpr.cpr_module_exists
has_module.argtypes = [c_char_p]
has_module.restype = c_bool

def sizeof(struct_type):
  try:
    return c_size_t.in_dll(libcpr, 'cpr_' + struct_type + '_sizeof').value
  except ValueError:
    raise ValueError, "unknown libcpr structure type: {}".format(struct_type)

if __name__ == '__main__':
  print "libcpr.version_string(): {}".format(version_string())
  print
  for feature_name in ('ascii', 'debug', 'unicode'):
    print "libcpr.has_feature('{}'): {}".format(feature_name, has_feature(feature_name))
  print
  for module_name in ('list', 'map', 'set', 'string', 'vector'):
    print "libcpr.has_module('{}'): {}".format(module_name, has_module(module_name))
    print "libcpr.sizeof('{}'): {}".format(module_name, sizeof(module_name))
    print
