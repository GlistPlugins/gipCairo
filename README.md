# gipCairo
GlistEngine plugin to create and draw onto PDF, SVG and PNG files.

The plugin can draw text, image, line, rectangle, circle, arc, ellipse.

See example GlistApp to find out how to use the plugin. In order to compile the example GlistApp;
- Copy the example GlistApp to your myglistapps folder
- Import the copied GlistApp into Eclipse from File->New->C/C++ Project->Empty or Existing Cmake Project
- If you are on Windows, open copied GlistApp->Properties->C/C++ Build->PATH->Value and add this to the end of the list (after a semicolon):
```
${workspace_loc}\..\..\..\..\glistplugins\gipCairo\libs\bin
```
- Add copied GlistApp into Run Configurations and launch it

This plugin uses the Cairo library.
Precompiled Cairo libraries for Windows is already supplied under libs dir.
Linux users should install cairo: sudo apt-get install cairo
Macos users should install cairo: brew install cairo

Tested on GlistEngine-linux and Windows.

Licence Apache-2

