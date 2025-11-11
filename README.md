# C-Notebook-QA-

轻量的 C++20 项目模板与示例 — 本仓库包含用于学习与练习的 C++ 代码与 CMake 配置，便于在本地构建、测试与贡献。

[![CI](https://github.com/UDPTCB/C-Notebook-QA-/actions/workflows/ci.yml/badge.svg)](https://github.com/UDPTCB/C-Notebook-QA-/actions)

## 特性
- 使用现代 C++20
- 基于 CMake 的跨平台构建
- GitHub Actions CI（构建 + 测试）

## 先决条件
- CMake >= 3.16
- 支持 C++20 的编译器（g++ 10+/clang++ 10+/MSVC v19.28+）
- build-essential（或等效的工具链）

## 本地构建（推荐）
```bash
# 在仓库根目录下
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j
# 运行测试（如果有）
ctest --output-on-failure
```

在 Windows 上，可使用 "Visual Studio" 生成器或 Ninja：
```powershell
mkdir build; cd build
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
ctest --test-dir . --output-on-failure
```

## 代码风格 & 静态检查
建议使用 clang-format（.clang-format 未包含时可自行添加）和 clang-tidy 进行格式化与静态检查。

## 贡献
非常欢迎贡献！
- 提交 issue 以报告 bug 或建议新特性
- Fork 仓库并创建 PR：请确保所有新增代码附有测试（如适用）并通过 CI

## 许可证
本项目采用 MIT 许可证（详见 LICENSE 文件）。
