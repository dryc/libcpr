#!/usr/bin/env ruby
# This is free and unencumbered software released into the public domain.

require 'ffi' # @see https://rubygems.org/gems/ffi

##
# Ruby FFI for the `libcpr` native library.
#
# @see http://libcpr.org/
module Libcpr extend FFI::Library
  ffi_lib ['cpr', 'libcpr.so.0']

  attach_variable :cpr_version_string, :string
  attach_function :cpr_feature_exists, [:string], :bool
  attach_function :cpr_module_exists, [:string], :bool
  attach_variable :cpr_list_sizeof, :size_t
  attach_variable :cpr_map_sizeof, :size_t
  attach_variable :cpr_set_sizeof, :size_t
  attach_variable :cpr_string_sizeof, :size_t
  attach_variable :cpr_vector_sizeof, :size_t

  ##
  # Returns the library version string.
  #
  # @return [String] a version string in "x.y.z" form
  def self.version_string
    cpr_version_string
  end

  ##
  # Determines whether the library supports a given feature.
  #
  # @param  [#to_s] feature_name the name of the feature, e.g. `:ascii`
  # @return [Boolean] `true` if the feature is supported, `false` otherwise
  def self.has_feature?(feature_name)
    cpr_feature_exists(feature_name.to_s)
  end

  ##
  # Determines whether the library includes a given module.
  #
  # @param  [#to_s] module_name the name of the module, e.g. `:vector`
  # @return [Boolean] `true` if the module is supported, `false` otherwise
  def self.has_module?(module_name)
    cpr_module_exists(module_name.to_s)
  end

  ##
  # Returns the byte size of the given library data structure.
  #
  # @param  [#to_sym] struct_type the structure type name, e.g. `:list`
  # @return [Integer]
  # @raise  [ArgumentError] if `struct_type` is not known
  def self.sizeof(struct_type)
    case (struct_type.to_sym rescue nil)
      when :list   then cpr_list_sizeof
      when :map    then cpr_map_sizeof
      when :set    then cpr_set_sizeof
      when :string then cpr_string_sizeof
      when :vector then cpr_vector_sizeof
      else raise ArgumentError, "unknown libcpr structure type: #{struct_type.inspect}"
    end
  end
end

if __FILE__ == $0
  puts "Libcpr.version_string: %s" % Libcpr.version_string
  puts
  %w(ascii debug unicode).each do |feature_name|
    puts "Libcpr.has_feature?(:#{feature_name}): %s" % Libcpr.has_feature?(feature_name)
  end
  puts
  %w(list map set string vector).each do |module_name|
    puts "Libcpr.has_module?(:#{module_name}) %s" % Libcpr.has_module?(module_name)
    puts "Libcpr.sizeof(:#{module_name}): %d" % Libcpr.sizeof(module_name)
    puts
  end
end
