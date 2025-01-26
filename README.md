# 小球控制游戏

这个项目是一个基于 Qt 框架和 C++ 开发的小游戏，玩家通过控制平衡板上的小球，目标是让小球滚动到终点。游戏中包含了多种物品和算法，如碰撞、限速、传送门等，具有一定的物理和逻辑挑战性。

## 项目结构

### 1. 小球类 (`ball`)

- 该类控制小球的移动和绘制。
- 通过键盘事件（WASD键）或鼠标摇杆控制小球的加速度。
- 每个帧调用 `ballmove()` 更新小球的位置，使用 `paintEvent` 绘制小球。

### 2. 物品类

- **终点类 (`destination`)**: 用于判断小球是否到达终点，触发胜利事件。
- **陷阱类 (`trap`)**: 判断小球是否进入陷阱，触发失败事件。
- **挡板类 (`board`)**: 用于模拟非弹性碰撞，使小球与挡板接触时“贴壁”。
- **弹板类 (`bouncingboard`)**: 模拟弹性碰撞，弹回小球。
- **漩涡类 (`vortex`)**: 控制小球的限速机制，要求小球以一定速度通过漩涡，否则会被吸入。
- **传送门类 (`portal_a` 和 `portal_b`)**: 模拟传送门效果，控制小球从入口传送到出口。

### 3. 游戏算法

- **小球移动算法**: 每一帧根据当前加速度计算小球的位置。
- **物品定位算法**: 控制物品（如终点、陷阱、挡板等）的位置。
- **碰撞算法**: 模拟小球与物品或边界的碰撞（包括非弹性和弹性碰撞）。
- **限速算法**: 控制小球在漩涡中必须以一定速度通过，否则失败。
- **传送门算法**: 控制小球通过传送门时的速度和位置变化。

## 运行要求

- Qt 6.6.2（基于 C++）
- 必须使用 Qt Creator 或其他支持 Qt 的开发环境。

## 游戏玩法

1. **控制方式**: 使用键盘（WASD）或者鼠标来控制小球的加速度，使其滚动。
2. **游戏模式**: 游戏支持单人模式、双人模式和友尽模式，可以在帮助窗口选择。
3. **关卡设计**: 游戏包含多个关卡，其中有不同的物品、障碍和挑战。

## 安装与运行

1. 克隆或下载此项目：

	```bash
	git clone <project-url>
	```

2. 使用 Qt Creator 打开项目文件 (`.pro`)。

3. 编译并运行项目。

## 收获与反思

- 通过这个项目，学习了 Qt 框架的基础知识，掌握了类和对象、虚函数等概念。
- 实践了游戏开发中的物理算法、碰撞检测、限速、传送门等重要逻辑。
- 提高了自主学习能力和项目开发经验，制作了一个具有一定挑战性的小游戏。