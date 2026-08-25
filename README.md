# 黑马 C++ 学习仓库

## 换电脑必读（工位 / 宿舍 双机同步）

本仓库的所有配置都已做成"自动寻址"，`git pull` 之后**不需要改任何仓库内文件**。
每台电脑只需做一次以下环境配置：

1. 安装 MinGW-w64，把 `mingw64\bin` 加入 PATH
   （验证：终端里运行 `g++ --version` 有输出）
2. 设置用户环境变量 `MinGW_HOME`，指向 mingw64 根目录（F5 调试要用）：

   ```powershell
   [Environment]::SetEnvironmentVariable("MinGW_HOME", "<你的mingw64根目录>", "User")
   ```

   例：`D:\mingw\x86_64-16.1.0-release-posix-seh-ucrt-rt_v14-rev1\mingw64`
3. 重启 VS Code（让它读到新的环境变量）

## 中文不乱码的原理（全链路 UTF-8 约定）

| 环节 | 编码 | 由谁保证 |
|---|---|---|
| 源文件 | UTF-8 | 工作区设置 `files.encoding: utf8` |
| exe 内字符串 | UTF-8 | 编译参数 `-fexec-charset=UTF-8` |
| 集成终端显示 | UTF-8 (代码页 65001) | 终端 profile 自动 `chcp 65001` |
| F5 调试管道 | UTF-8 | VS Code 调试器天然按 UTF-8 解读 |

⚠️ 唯一例外：在 VS Code 之外单独开的 cmd/PowerShell 窗口仍是 GBK(936)，
直接跑会乱码，先执行 `chcp 65001` 即可。

## 构建 / 运行

- 打开 `code/` 下任意 `.cpp` → `Ctrl+Shift+B` 编译 → `F5` 调试运行
- 编译产物统一输出到 `bin/`（已被 .gitignore 忽略，不会上传）
- 新增 `.cpp` 文件无需改任何配置：同目录下不含 `main` 的文件会被自动链接进当前程序
- CMake 构建路径同样已配好编码参数（`CMakeLists.txt`）

## 目录结构

```
code/    学习代码（每个含 main 的 .cpp 是一个独立小程序）
head/    自定义头文件（构建时自动 -I 此目录）
bin/     编译产物（gitignore）
.vscode/ 工作区配置（自动寻址版，随 git 同步）
```
