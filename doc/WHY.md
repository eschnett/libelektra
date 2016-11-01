# Why should I use Elektra? #

The three main points relevant for most people are:

1. Even though Elektra provides a global keydatabase,
   configuration files stay human read- and writable
   which allows us to integrate unmodified software.
2. Flexible adoption on how the configuration is accessed
   via plugins: you can run arbitrary code, e.g. do a
   `git commit` or log/notify when configuration files
   are changed.
3. Elektra allows you to specify configuration values:
   - use the value of other configuration values (symbolic links)
   - calculate the values based on other configuration values
   - validation configuration files
   - [generate code based on it](/src/tools/gen)
   - [and much more](/src/plugins/README.md)

## Who should use Elektra? ##

Elektra directly targets three different kinds of users:

1. Developers to develop a better integrated free software ecosystem and
   plugins for better validation/notification.
2. System administrators to have a higher-level view of their configuration
   and enable them to better consider context.
3. Researchers to develop plugins that can be used with a large pool of
   applications.

## Unique Features ##

Features that rarely can be found elsewhere (at least in this combination):

- Bootstrap code and proper abstraction is included:
  - You do not need to worry about the file names of configuration files
    in the application.
  - Cascading between `/etc`, `$HOME`, `cwd` and so on.
  - You can change which Elektra path is connected to which configuration
    file with [mounting](/doc/help/elektra-mounting.md).
  - Portable across OS (Linux, BSD, w64, mac os x,.. ) and desktop systems (GNOME, KDE,...).
- No daemon, so no single point of failure but still having guarantees of consistent,
  validated files with good performance.
- Provides 3-way merging for configuration upgrades.

## Further Reasons ##

- Links and automatic calculation of values:
   unlike with other solutions you do not need to duplicate
   configuration values for different applications but
   you can comfortably link between them which makes
   many inconsistencies impossible.
- Allows us to easily create GUIs and web-UIs for the whole configuration
  on the system.
- Allows you to import/export all parts of the configuration.
- Syntax independence: you can consistently use your favourite syntax.
- Configuration Management (such as Puppet) can be used on top of it
  without having to fiddle with specifics of every configuration file.
- CLI-tool available
- `kdb editor` allows you to edit any path of Elektra with your favourite
  syntax (independent of the actual syntax of the configuration files
  that store values of this path).
- Allows us to also (integrate commandline arguments and environment)[/src/libs/getenv]
  into a consistent place for configuration.
- Reduces huge amount of code: Nearly every application has very similar code:
  - finding the correct configuration file (for different OS)
  - parsing configuration files
  - validating configuration files
  - replace configuration files on changes
- All advantages libraries have:
  - Performance: Improvements in the library benefits all applications.
  - The library only needs to be loaded once in the memory.
  - On fixes not all binaries of all applications need to be replaced.
- All advantages maintained code with a community has:
  - If something does not work, open an issue.
  - If you have a question, open an issue.
  - Regular releases.
