# PHD2 Log Viewer

PHD2 Log Viewer is a desktop tool for visualizing PHD2 guide logs and spotting guiding problems quickly.

This standalone branch adds built-in Simplified Chinese localization while keeping English and French available from the Language menu. The localized UI, log-field labels, event labels, quick help, settings, and analysis windows are compiled into the application. The `languages/` folder is also packaged on Windows, macOS, and Linux as release metadata.

## Downloads

Release binaries will be published separately for each operating system:

- Windows: https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-windows-x86_64.zip
- macOS: https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-macos-arm64-local.zip
- Linux: https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-linux-x86_64.tar.gz

## Build

The project uses CMake and wxWidgets.

```sh
cmake -S . -B build -DHAVE_WXFB=0
cmake --build build --config Release
```

Platform notes:

- Windows builds use the bundled `3rdparty` runtime files and the `phdlogview-x86.iss.in` / `phdlogview-x64.iss.in` Inno Setup templates.
- macOS builds create a `phdlogview.app` bundle and copy language metadata into `Contents/Resources/languages`. The default build uses the host CPU architecture; pass `-DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"` only when all dependencies are universal.
- Linux builds install the executable, desktop entry, icon, and language metadata under the install prefix.

## 中文说明

PHD2 Log Viewer 是用于查看和分析 PHD2 导星日志的桌面工具，可以帮助用户快速观察导星曲线、统计信息、漂移、频率分析和日志事件。

这个独立分支加入了内置简体中文汉化，同时保留英文和法文，可在“语言”菜单中切换。主界面、菜单、设置窗口、分析窗口、快速帮助、日志字段和事件标签都已加入本地化。`languages/` 目录也会随 Windows、macOS、Linux 版本一起打包，用于标识发行包包含的语言。

## 下载

正式构建文件会按系统分别发布：

- Windows：https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-windows-x86_64.zip
- macOS：https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-macos-arm64-local.zip
- Linux：https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-linux-x86_64.tar.gz

## 构建

项目使用 CMake 和 wxWidgets。

```sh
cmake -S . -B build -DHAVE_WXFB=0
cmake --build build --config Release
```

平台说明：

- Windows：使用仓库内 `3rdparty` 运行库文件，并通过 `phdlogview-x86.iss.in` / `phdlogview-x64.iss.in` 生成安装包。
- macOS：生成 `phdlogview.app`，语言元数据会复制到 `Contents/Resources/languages`。默认使用本机 CPU 架构；只有在依赖库都是 universal 时才传入 `-DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"`。
- Linux：安装可执行文件、桌面入口、图标和语言元数据。

## License

GPL-3.0-or-later.
