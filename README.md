# SysY 编译器前端

这是一个SysY语言的编译器前端实现，完成了词法分析、语法分析和AST构建功能。

## 项目结构

```
sysy_compiler/
├── include/          # 头文件目录
│   └── ast.h        # AST节点定义
├── src/             # 源代码目录
│   ├── ast.c        # AST节点实现
│   ├── lexer.l      # Flex词法分析器
│   └── parser.y     # Bison语法分析器
├── test/            # 测试用例目录
│   ├── test1.sy     # 简单函数测试
│   ├── test2.sy     # if-else测试
│   ├── test3.sy     # while循环测试
│   └── test4.sy     # 数组操作测试
├── Makefile         # 构建文件
└── README.md        # 本文件
```

## 功能特性

### 已实现功能

1. **词法分析（任务4.2）**
   - 关键字识别：int, float, void, const, if, else, while, break, continue, return
   - 运算符识别：+, -, *, /, %, ==, !=, <, <=, >, >=, &&, ||, !
   - 标识符和常量识别
   - 注释处理（单行和多行）

2. **语法分析（任务4.3）**
   - 函数定义和声明
   - 变量声明和初始化
   - 数组声明和访问
   - 表达式运算（算术、逻辑、关系运算）
   - 控制流语句（if-else, while）
   - return语句
   - 语句块

3. **AST构建**
   - 完整的抽象语法树节点定义
   - AST打印功能（用于调试）
   - 内存管理

## 编译和运行

### 前置要求

- GCC编译器
- Flex (词法分析器生成工具)
- Bison (语法分析器生成工具)
- Make工具

在macOS上安装：
```bash
brew install flex bison
```

在Ubuntu/Debian上安装：
```bash
sudo apt-get install flex bison build-essential
```

### 编译

```bash
cd sysy_compiler
make
```

### 运行

```bash
# 编译后的可执行文件在 bin/sysy_compiler
./bin/sysy_compiler test/test1.sy

# 或者从标准输入读取
./bin/sysy_compiler < test/test1.sy
```

### 清理

```bash
make clean
```

## 测试用例

项目包含了4个测试用例：

1. **test1.sy**: 简单的函数定义和基本运算
2. **test2.sy**: if-else条件语句
3. **test3.sy**: while循环语句
4. **test4.sy**: 数组声明和访问

运行测试：
```bash
make test
```

## SysY语言语法特性

### 数据类型
- `int`: 整数类型
- `float`: 浮点数类型
- `void`: 空类型（用于函数）

### 变量声明
```c
int a;
int b = 10;
const int c = 20;
```

### 数组声明
```c
int arr[10];
int arr2[5][10];
```

### 函数定义
```c
int add(int a, int b) {
    return a + b;
}

void print() {
    // ...
}
```

### 控制流
```c
if (condition) {
    // statements
} else {
    // statements
}

while (condition) {
    // statements
}
```

### 表达式
- 算术运算：+, -, *, /, %
- 关系运算：==, !=, <, <=, >, >=
- 逻辑运算：&&, ||, !

## 任务完成情况

- ✅ **任务4.1**: SysY语言的语法和语义规范理解
- ✅ **任务4.2**: 词法分析器设计与实现（使用Flex）
- ✅ **任务4.3**: 语法分析器设计与实现（使用Bison）
- ⏳ **任务4.4**: 语义分析（选做，未实现）

## 扩展建议

如需完成语义分析（任务4.4），可以添加：

1. **符号表管理**
   - 变量作用域管理
   - 函数符号表
   - 类型检查

2. **语义检查**
   - 变量未声明检查
   - 类型匹配检查
   - 函数参数检查
   - 数组越界检查（静态分析）

3. **代码生成**
   - 中间代码生成（如三地址码）
   - 目标代码生成

## 注意事项

- 当前实现主要关注语法分析，语义检查较为简单
- 错误处理可以进一步完善
- 支持的语言特性是SysY的一个子集

## 作者

编译器课程作业 - 项目4

## 许可证

本项目仅用于教学目的。

