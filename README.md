# PHD2 Log Viewer

PHD2 Log Viewer is a desktop tool for visualizing PHD2 guide logs and spotting guiding problems quickly.

This standalone branch adds built-in Simplified Chinese localization while keeping English and French available from the Language menu. The localized UI, log-field labels, event labels, quick help, settings, and analysis windows are compiled into the application. The `languages/` folder is also packaged on Windows, macOS, and Linux as release metadata.

## Downloads

Release binaries will be published separately for each operating system:

- Windows installer: https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-windows-x86_64-setup.exe
- macOS app: https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-macos-arm64.zip
- Linux Debian/Ubuntu package: https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-linux-amd64.deb

macOS note: the app bundle is ad-hoc signed and includes bundled runtime libraries, but it is not Apple Developer ID notarized. If Gatekeeper blocks the first launch after download, open it with Control-click / right-click and Open.

## Build

The project uses CMake and wxWidgets.

```sh
cmake -S . -B build -DHAVE_WXFB=0
cmake --build build --config Release
```

Platform notes:

- Windows release builds produce an Inno Setup installer with the executable, runtime DLLs, license, README, and language metadata.
- macOS builds create a `phdlogview.app` bundle and copy language metadata into `Contents/Resources/languages`. The default build uses the host CPU architecture; pass `-DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"` only when all dependencies are universal. Release builds are uploaded from the local Mac app bundle with bundled Homebrew runtime libraries.
- Linux release builds produce a Debian/Ubuntu `.deb` package with the executable, desktop entry, icon, and language metadata.

## 中文说明

PHD2 Log Viewer 是用于查看和分析 PHD2 导星日志的桌面工具，可以帮助用户快速观察导星曲线、统计信息、漂移、频率分析和日志事件。

这个独立分支加入了内置简体中文汉化，同时保留英文和法文，可在“语言”菜单中切换。主界面、菜单、设置窗口、分析窗口、快速帮助、日志字段和事件标签都已加入本地化。`languages/` 目录也会随 Windows、macOS、Linux 版本一起打包，用于标识发行包包含的语言。

## 下载

正式构建文件会按系统分别发布：

- Windows 安装包：https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-windows-x86_64-setup.exe
- macOS App：https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-macos-arm64.zip
- Linux Debian/Ubuntu 安装包：https://github.com/songshugong/phdlogview/releases/latest/download/phdlogview-linux-amd64.deb

macOS 说明：App 已做 ad-hoc 签名并打包运行库依赖，但没有 Apple Developer ID 公证。如果下载后首次启动被 Gatekeeper 阻止，请用 Control-click / 右键选择“打开”。

## 构建

项目使用 CMake 和 wxWidgets。

```sh
cmake -S . -B build -DHAVE_WXFB=0
cmake --build build --config Release
```

平台说明：

- Windows：生成 Inno Setup 安装器，包含可执行文件、运行库 DLL、许可证、README 和语言元数据。
- macOS：生成 `phdlogview.app`，语言元数据会复制到 `Contents/Resources/languages`。默认使用本机 CPU 架构；只有在依赖库都是 universal 时才传入 `-DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"`。发布包上传本地 Mac app bundle，并包含 Homebrew 运行库依赖。
- Linux：生成 Debian/Ubuntu `.deb` 安装包，包含可执行文件、桌面入口、图标和语言元数据。

## License

GPL-3.0-or-later.
