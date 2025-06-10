# Imgui Menu Synthetic

This project provides a customizable menu framework built with C++ and ImGui.

## Building
1. Install **Visual Studio 2022** with C++ Desktop workloads.
2. Open `framework.sln` and build the `Release` configuration.
3. All required third-party libraries are included in the `thirdparty/` directory.

## Configuration
Appearance options are controlled through the `style.ini` file located in the project root.
Update this file to change window size, spacing, colors and other style settings without recompiling.

```
[window]
size = 800 600
padding = 12 12

[colors]
accent = 255 85 160 255
```

After editing `style.ini`, restart the menu to apply changes.

## Usage
Run the compiled executable and press the assigned hotkey to display the menu.

![screenshot](https://github.com/user-attachments/assets/8bd71fa3-1258-48a8-b0cf-d3930fa14576)
