- infos = Information about the python plugin is in keys below
- infos/author = Manuel Mausz <manuel-elektra@mausz.at>
- infos/licence = BSD
- infos/provides =
- infos/needs =
- infos/placements =
- infos/status = maintained unittest memleak nodoc
- infos/description = magic things require magic plugins

## Introduction ##

The plugin uses Python to do magic things.

## Usage ##

    kdb mount file.ini /python python script=/path/to/python/python_configparser.py,print=

## Plugin Configuration ##

Optional configuration values/flags:

- `print` (flag): Make the plugin print engine errors, triggered by the calls of
  this plugin, to stderr. Mainly intended for diagnostic. Please note that the
  Python engine itself will print script errors to stderr regardless of this flag.
- `shutdown` (value, 0 or 1): If enabled, the last call to `kdbClose()` will also
  shutdown Pythons engine. Default is 0.
