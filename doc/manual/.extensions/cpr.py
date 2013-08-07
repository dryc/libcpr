# -*- coding: utf-8 -*-
#
# Sphinx extension for generating the libcpr documentation.
#
# Written by Arto Bendiken <http://ar.to/>.
#
# This is free and unencumbered software released into the public domain.

import os
import fnmatch
import doxygen

from docutils import nodes
from sphinx import addnodes
from sphinx.directives import ObjectDescription
from sphinx.domains import Domain, ObjType
from sphinx.locale import l_, _
from sphinx.roles import XRefRole
from sphinx.util.compat import Directive
from sphinx.util.docfields import Field, GroupedField, TypedField

class CPRObject(ObjectDescription):
  def handle_signature(self, sig, signode):
    self.name = sig
    self.node = doxygen.index().get(self.name)
    print self.node
    self.describe_signature(signode)
    return self.name

  def describe_signature(self, node):
    raise NotImplementedError()

  def add_target_and_index(self, name, sig, signode):
    if name not in self.state.document.ids:
      signode['names'].append(name)
      signode['ids'].append(name)
      signode['first'] = (not self.names)
      self.state.document.note_explicit_target(signode)
      inv = self.env.domaindata['cpr']['objects']
      if name in inv:
        self.state_machine.reporter.warning(
          'duplicate symbol definition of %s, ' % name +
          'other instance in ' + self.env.doc2path(inv[name][0]),
          line=self.lineno)
      inv[name] = (self.env.docname, self.objtype)
    index_text = self.get_index_text(name)
    if index_text:
      self.indexnode['entries'].append(('single', index_text, name, ''))

class CPRModuleObject(CPRObject):
  def get_index_text(self, name):
    return _('%s (module)') % name

class CPRFunctionObject(CPRObject):
  def get_index_text(self, name):
    return _('%s (function)') % name

  def describe_signature(self, node):
    node += addnodes.desc_type(self.node.type, self.node.type)
    node += nodes.Text(' ')
    node += addnodes.desc_name(self.name, self.name)
    args = self.node.argsstring[1:-1]
    node += addnodes.desc_parameterlist(args, args)

  def before_content(self):
    self.env.temp_data['cpr:symbol'] = self.name

class CPRVarObject(CPRObject):
  def get_index_text(self, name):
    return _('%s (variable)') % name

  def describe_signature(self, node):
    node += addnodes.desc_type(self.node.type, self.node.type)
    node += nodes.Text(' ')
    node += addnodes.desc_name(self.name, self.name)

  def before_content(self):
    self.env.temp_data['cpr:symbol'] = self.name

class CPRTypedefObject(CPRObject):
  def get_index_text(self, name):
    return _('%s (typedef)') % name

  def describe_signature(self, node):
    node += addnodes.desc_type(self.node.type, self.node.type)
    node += nodes.Text(' ')
    node += addnodes.desc_name(self.name, self.name)

  def before_content(self):
    self.env.temp_data['cpr:symbol'] = self.name

class CPRDirective(Directive):
  has_content = False
  required_arguments = 0
  optional_arguments = 0
  final_argument_whitespace = False
  option_spec = {}

  def run(self):
    result = []
    for node in self.render():
      result.append(node)
    return result

  def render(self):
    pass

  def symbol(self):
    symbol_name = self.env().temp_data['cpr:symbol']
    return doxygen.index().get(symbol_name)

  def env(self):
    return self.state.document.settings.env

class CPRSummaryDirective(CPRDirective):
  def render(self):
    symbol = self.symbol()
    if symbol.briefdescription:
      yield nodes.paragraph(text=symbol.briefdescription)
    else:
      yield nodes.paragraph(text='TODO')

class CPRWarningDirective(CPRDirective):
  def render(self):
    symbol = self.symbol()
    if symbol.warning:
      yield nodes.warning('', nodes.paragraph(text=symbol.warning))

class CPRParamsDirective(CPRDirective):
  def render(self):
    symbol = self.symbol()
    if not symbol.params:
      yield nodes.paragraph(text=_('None.'))
    else:
      definition_list = nodes.definition_list()
      for param in symbol.params:
        param_name = param.get('declname')
        if param_name is not None:
          param_desc = param.get('briefdescription', '')
          definition_list_item = nodes.definition_list_item('',
            nodes.term('', '', nodes.literal('', param_name)),
            nodes.definition('', nodes.paragraph(text=param_desc)))
          definition_list.append(definition_list_item)
      yield definition_list

class CPRReturnDirective(CPRDirective):
  def render(self):
    symbol = self.symbol()
    if symbol.type == 'void':
      yield nodes.paragraph(text=_('None.'))
    elif symbol.returns:
      yield nodes.paragraph(text=symbol.returns)
    else:
      # TODO: synthesize a description from symbol.type:
      yield nodes.paragraph(text='TODO')

class CPRErrorsDirective(CPRDirective):
  def render(self):
    symbol = self.symbol()
    if not symbol.exceptions:
      yield nodes.paragraph(text=_('None.'))
    else:
      definition_list = nodes.definition_list()
      for k, v in symbol.exceptions.iteritems():
        definition_list_item = nodes.definition_list_item('',
          nodes.term('', '', nodes.literal('', k)),
          nodes.definition('', nodes.paragraph(text=v)))
        definition_list.append(definition_list_item)
      yield definition_list

class CPRDomain(Domain):
  """libcpr domain."""

  name = 'cpr'
  label = 'libcpr'
  object_types = {
    'module':   ObjType(l_('module'),   'module'),
    'function': ObjType(l_('function'), 'function'),
    'var':      ObjType(l_('var'),      'var'),
    'type':     ObjType(l_('type'),     'type'),
  }
  directives = {
    'module':   CPRModuleObject,
    'function': CPRFunctionObject,
    'var':      CPRVarObject,
    'type':     CPRTypedefObject,
    'summary':  CPRSummaryDirective,
    'warning':  CPRWarningDirective,
    'params':   CPRParamsDirective,
    'return':   CPRReturnDirective,
    'errors':   CPRErrorsDirective,
  }
  roles = {}
  initial_data = {
    'objects': {},  # fullname -> docname, objtype
  }
  data_version = 0

  def clear_doc(self, docname):
    pass

  def resolve_xref(self, env, fromdocname, builder, typ, target, node, contnode):
    return None # TODO

  def get_objects(self):
    for refname, (docname, type) in self.data['objects'].iteritems():
      yield (refname, refname, type, docname, refname, 1)

def setup(app):
  app.require_sphinx('1.0')
  app.setup_extension('doxygen')
  app.add_domain(CPRDomain)
