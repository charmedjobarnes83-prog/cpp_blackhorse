# 黑马 C++ 学习仓库

这是个人 C++ 学习仓库。目前主要跟随黑马程序员 C++ 教程练习，后续学习方向为：

```text
C++ → Linux → 数据结构与算法 → CUDA / GPU 并行计算
```

`code/` 下的大部分 `.cpp` 都是可以独立运行的小练习。项目配置支持工位、宿舍两台 Windows 电脑通过 GitHub 同步代码，同时让两台电脑保留各自不同的 MinGW 安装路径。

## 换电脑后的操作步骤

### 1. 拉取仓库

首次使用：

```bash
git clone https://github.com/charmedjobarnes83-prog/cpp_blackhorse.git
cd cpp_blackhorse
```

已有仓库：

```bash
git pull
```

### 2. 安装本机工具

需要安装：

- VS Code
- VS Code 的 C/C++ 扩展
- MinGW-w64（必须包含 `g++`、`gdb`、`mingw32-make`）
- CMake（使用 CMake 构建时需要）
- Git

### 3. 设置本机的 MinGW 路径

仓库内不保存某台电脑的绝对安装路径。每台电脑只需设置自己的用户环境变量：

```text
变量名：MINGW64_ROOT
变量值：本机 mingw64 根目录
```

例如当前电脑可以是：

```text
D:\mingw\x86_64-16.1.0-release-posix-seh-ucrt-rt_v14-rev1\mingw64
```

另一台电脑可以是完全不同的路径，例如：

```text
D:\DevTools\WinLibs\mingw64
```

可以在 PowerShell 中设置：

```powershell
[Environment]::SetEnvironmentVariable(
    "MINGW64_ROOT",
    "<本机的mingw64根目录>",
    "User"
)
```

还需要把下面这个目录加入本机用户 `Path`：

```text
%MINGW64_ROOT%\bin
```

设置完成后，关闭所有 VS Code 窗口，再重新打开。

### 4. 验证开发环境

在新打开的 PowerShell 中执行：

```powershell
$env:MINGW64_ROOT
where.exe g++
where.exe gdb
where.exe mingw32-make
g++ --version
gdb --version
```

这些命令都能找到程序后，环境配置才算完成。

## 编译和运行

1. 使用 VS Code 打开整个仓库文件夹，不要只打开单个 `.cpp`。
2. 打开 `code/` 下需要运行的 `.cpp`，确保它是当前活动文件。
3. 按 `F5` 编译并调试，或者按 `Ctrl+Shift+B` 只编译。

编译产物会生成到：

```text
bin/<当前cpp文件名>.exe
```

每次重新编译前，VS Code 会调用 `kill_last.bat`，只结束与当前文件同名的旧程序，避免 Windows 因为 `.exe` 正在运行而无法覆盖它。

`build.bat` 会编译当前活动文件，并自动加入同一目录下不含 `int main` 的 `.cpp` 实现文件。因此：

- 单文件练习必须包含 `int main()`；
- 新建独立练习文件不需要修改 `tasks.json`；
- 辅助实现文件可以没有 `main()`，但应避免把无关的辅助 `.cpp` 混放在同一目录。

## CMake 构建

`CMakeLists.txt` 会自动发现 `code/*.cpp`，为每个独立 `.cpp` 创建同名目标，并输出到 `bin/`。

VS Code 已配置以下任务：

- `CMake: 配置项目`
- `CMake: 增量编译`

CMake 使用：

```text
生成器：MinGW Makefiles
构建目录：build-mingw/
输出目录：bin/
C++标准：C++17
```

如果一个练习由多个 `.cpp` 共同组成，可能需要为它单独调整 `CMakeLists.txt`；日常运行当前活动文件时优先使用 `F5` 对应的 `build.bat`。

## 中文编码

项目统一使用 UTF-8：

| 环节 | 设置 |
|---|---|
| 源文件 | VS Code `files.encoding: utf8` |
| 编译输入 | `-finput-charset=UTF-8` |
| exe 字符串 | `-fexec-charset=UTF-8` |
| VS Code 终端 | 自动执行 `chcp 65001` |

如果在 VS Code 外单独打开的 PowerShell 或 CMD 中运行程序仍然乱码，先执行：

```powershell
chcp 65001
```

## Git 双电脑同步

仓库同步以下内容：

- `code/` 学习代码
- `head/` 自定义头文件
- `CMakeLists.txt`
- 已经被 Git 跟踪的 `.vscode` 配置
- `build.bat` 和 `kill_last.bat`
- 本 README

不同步以下本地产物：

- `bin/`
- `build/`
- `build-mingw/`
- `.exe`、`.o`、`.obj` 等编译文件
- 每台电脑自己的环境变量和 MinGW 安装路径

离开一台电脑前：

```bash
git status
git add .
git commit -m "说明本次学习或修改内容"
git push
```

换到另一台电脑后：

```bash
git pull
```

提交前应先查看 `git status`，避免把不需要的文件一起提交。

## 换电脑后发给 Codex 的指令

在另一台电脑拉取仓库后，可以把本 README 提供给 Codex，并发送下面这段指令：

```text
请先完整阅读项目根目录的 README.md，再检查当前项目和 Git 状态。

这是一个双电脑同步的 C++ 学习仓库，使用 Windows、VS Code、MinGW-w64、
C++17、g++ 和 gdb。仓库配置不得写死本机绝对路径；调试器必须通过本机
环境变量 MINGW64_ROOT 定位。编译产物输出到 bin，CMake 构建目录为
build-mingw。

请先只做只读检查：确认 MINGW64_ROOT、g++、gdb、mingw32-make、CMake、
.vscode/launch.json、.vscode/tasks.json、build.bat 和 CMakeLists.txt 是否匹配。
列出发现的问题和准备修改的文件。不要覆盖我的学习代码，不要删除已有修改，
不要修改与环境配置无关的 cpp 文件。需要修复配置时，使用可跨电脑的变量或
相对路径，不要写入这台电脑专属的 D:\... 或 C:\... 路径。修复后请编译并
运行当前活动的 cpp 文件进行验证。
```

## 目录说明

```text
code/          C++ 学习代码
head/          自定义头文件
bin/           编译产物，不上传 GitHub
build-mingw/   CMake 构建文件，不上传 GitHub
.vscode/       VS Code 编译、调试和 UTF-8 配置
build.bat      编译当前活动 cpp
kill_last.bat  编译前结束同名旧程序
```

## 常见问题

### F5 提示找不到 GDB

检查：

```powershell
$env:MINGW64_ROOT
Test-Path "$env:MINGW64_ROOT\bin\gdb.exe"
```

如果环境变量刚设置，必须完全重启 VS Code。

### 编译提示找不到 `g++`

确认 `%MINGW64_ROOT%\bin` 已加入 `Path`，然后重新打开终端。

### 链接器提示找不到 `main`、`WinMain`

确认当前活动的独立练习文件中存在：

```cpp
int main() {
    return 0;
}
```

### 修改代码后无法重新生成 exe

通常是旧程序仍在运行。当前任务会自动结束同名程序；如果仍失败，可检查：

```powershell
Get-Process -Name "<cpp文件名>" -ErrorAction SilentlyContinue
```
