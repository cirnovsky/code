# 任务调度类算法题合集

> 配合 [training_plan.md] 的贪心训练使用。调度类问题是贪心 + DP + 优先队列的核心战场，刷透这一类对从 1600 冲 1900 帮助极大。

---

## 一、问题原型与算法

### 1.1 单机调度（Single Machine Scheduling）

| 原型 | 算法 | 关键贪心 |
|------|------|----------|
| 最小化总完成时间 ΣC_i | **SPT** (Shortest Processing Time) | 按处理时间升序 |
| 带截止时间最少迟到任务数 | **Moore–Hodgson** | 按 deadline 排序 + 优先队列反悔 |
| 带权迟到惩罚 ΣwT_i | DP / 反悔贪心 | 状压 / 优先队列 |
| 最大化按时完成任务的总价值 | **加权区间调度** | 按 deadline 排序 + 反悔堆 |
| 单位处理时间带截止的调度 | **拟阵 / 反悔贪心** | 按价值降序 + 并查集 |

### 1.2 两机 / 多机调度

| 原型 | 算法 |
|------|------|
| 两台机器顺序加工最小化总完工时间 | **Johnson 算法** |
| m 台机器最小化 makespan | **LPT 近似** / 二分答案 |
| 流水车间调度 | DP / Johnson 推广 |

### 1.3 区间调度（Interval Scheduling）

| 原型 | 算法 |
|------|------|
| 最多不重叠区间 | 按右端点排序贪心 |
| 区间全覆盖最少线段 | 按左端点排序 |
| 加权不重叠区间最大权 | DP + 二分 |
| 最少会议室 / 最大重叠数 | 差分 / 扫描线 / 小根堆 |
| 区间分组（每组不重叠） | 小根堆维护组末端 |

### 1.4 带冷却 / 间隔约束

| 原型 | 算法 |
|------|------|
| 相同任务间最少冷却 n | 桶 + 公式 / 优先队列 |
| 周期性约束 | 哈希 + 队列 |

### 1.5 反悔贪心（Regret Greedy）

最经典套路：按某维度排序，每步贪心选最优；若违反约束，从已选中弹出"最不值"的换掉。
- 用大根堆维护「已选中代价最大的」
- 用小根堆维护「已选中价值最小的」

---

## 二、CSES 经典（必刷，按顺序）

| 题号 | 题目 | 类型 | 难度 |
|------|------|------|------|
| 1629 | Movie Festival | 最多不重叠区间 | ⭐ |
| 1619 | Restaurant Customers | 扫描线 / 最大重叠 | ⭐ |
| 1084 | Apartments | 双指针匹配 | ⭐ |
| 1630 | Tasks and Deadlines | SPT + 排序 | ⭐⭐ |
| 1632 | Movie Festival II | k 人不重叠区间 (multiset) | ⭐⭐ |
| 1631 | Reading Books | 经典贪心思维题 | ⭐⭐ |
| 1620 | Factory Machines | 二分答案 | ⭐⭐ |
| 1141 | Book Shop | 加权调度 / 背包 | ⭐⭐ |

---

## 三、Codeforces 实战（按 rating 分层）

### 1300–1500（暖身）
- **545D — Queue** — SPT 经典，最多多少人不失望
- **731C — Socks** — 并查集 + 贪心
- **478B — Random Teams** — 极值分配
- **581B — Luxurious Houses** — 后缀贪心
- **1029C — Maximal Intersection** — 区间删一个
- **1132C — Painting the Fence** — 区间删两个
- **1029B — Creating the Contest** — 简单调度
- **1296C — Yet Another Walking Robot** — 区间最短

### 1500–1700（核心训练区）
- **1041C — Coffee Break** — 带冷却调度，set + 贪心 ⭐
- **555B — Case of Fugitive** — 区间匹配（实际 ~1900，但思路核心）
- **1140C — Playlist** — 反悔贪心 + 优先队列 ⭐
- **1132F — Clear the String** — 区间 DP（贪心失败案例）
- **1198B — Welfare State** — 离线 + 排序
- **1257D — Yet Another Monster Killing Problem** — 区间贪心 + 二分 ⭐
- **1296E1 — String Coloring (Easy)** — 等价于最少递减子序列
- **1296E2 — String Coloring (Hard)** — Patience Sorting
- **1538C — Number of Pairs** — 排序 + 二分
- **1271C — Shawarma Tent** — 网格贪心
- **1296D — Same GCDs** — 数学

### 1700–1900（目标区间）
- **1257E — The Contest** — 三段划分 DP
- **1141F2 — Same Sum Blocks (Hard)** — 区间最大不重叠数
- **1077F2 — Pictures with Kittens (Hard)** — 单调队列 DP ⭐
- **1132G — Greedy Subsequences** — 单调栈 + 线段树
- **1437E — Make It Increasing** — LIS 变形
- **1462E2 — Close Tuples (Hard)** — 组合 + 排序
- **1426E — Rock, Paper, Scissors** — 贪心匹配
- **1525D — Armchairs** — 经典 DP（也可看作匹配）⭐
- **1029F — Multicolored Markers** — 调度思想
- **1183H — Subsequences (Hard)** — DP，BFS 风格

### 1900+（拉伸题）
- **442B — Andrey and Problem** — 贪心 + 概率
- **865D — Buy Low Sell High** — 反悔贪心经典 ⭐⭐
- **730I — Olympiad in Programming and Sports** — 反悔贪心 + 三分
- **958E2 — Guard Duty (medium)** — 反悔贪心
- **436E — Cardboard Box** — 反悔贪心
- **1379F1/F2** — 复杂调度
- **1499F — Diameter Cuts and Gifts** — 树形 DP + 调度

---

## 四、LeetCode 调度题（适合速刷）

### 区间类
- **435. Non-overlapping Intervals** — 等价于 CSES Movie Festival
- **452. Minimum Number of Arrows** — 同上变形
- **253. Meeting Rooms II** — 最大重叠 / 最少房间
- **2402. Meeting Rooms III** — 优先队列模拟
- **1851. Minimum Interval to Include Each Query** — 离线 + 堆
- **1353. Maximum Number of Events That Can Be Attended** — 反悔贪心 ⭐
- **1751. Maximum Number of Events II** — 加权区间调度 DP
- **759. Employee Free Time** — 扫描线
- **1235. Maximum Profit in Job Scheduling** — 加权区间 DP ⭐

### 任务 / CPU 类
- **621. Task Scheduler** — 冷却调度经典 ⭐
- **1834. Single-Threaded CPU** — 优先队列模拟
- **1882. Process Tasks Using Servers** — 双堆模拟
- **2365. Task Scheduler II** — 哈希 + 贪心
- **2589. Minimum Time to Complete All Tasks** — 区间 + 贪心
- **2333. Minimum Sum of Squared Difference** — 反悔贪心
- **630. Course Schedule III** — 反悔贪心经典 ⭐⭐
- **502. IPO** — 双堆贪心 ⭐
- **2402. Meeting Rooms III** — 双堆模拟

---

## 五、经典原题（适合理解算法本身）

### Job Sequencing with Deadlines
- **GeeksforGeeks**: Job Sequencing Problem
- **HDU 1052**: Tian Ji The Horse Racing（田忌赛马）
- **POJ 2287**: Tian Ji The Horse Racing
- **POJ 1700**: Crossing River（过河贪心）
- **POJ 3190**: Stall Reservations（最少牛棚 = Meeting Rooms II）
- **POJ 1065**: Wooden Sticks（双关键字排序 + Dilworth）
- **POJ 1230**: Pass-Muraille（覆盖区间贪心）
- **UVA 10026**: Shoemaker's Problem（SPT 加权）
- **UVA 11627**: Slalom（Johnson 算法）

### 反悔贪心经典
- **NOI 2010 / Luogu P1484**: 种树（环上 + 反悔堆）⭐
- **Luogu P1792**: 种树（线性版本）
- **Luogu P4053 / JSOI 2007**: 建筑抢修（Moore-Hodgson）⭐⭐
- **Luogu P2949 / USACO**: Work Scheduling（加权 Moore-Hodgson）⭐⭐
- **Luogu P1080 / NOIP 2012**: 国王游戏（邻项交换 + 高精度）
- **Luogu P1842**: 奶牛玩杂技（邻项交换）
- **Luogu P2123**: 皇后游戏（邻项交换 Johnson 风格）
- **Luogu P4040 / AHOI 2014**: 宅男计划（贪心 + 三分）

---

## 六、按"训练阶段"推荐顺序

### 阶段 A：理解算法（第 1 周）
1. CSES 1629 Movie Festival
2. LeetCode 435 / 253
3. CF 545D Queue
4. CSES 1630 Tasks and Deadlines
5. CSES 1632 Movie Festival II

**学完应该掌握：** 区间排序贪心、扫描线、SPT

### 阶段 B：反悔贪心入门（第 2 周）
1. LeetCode 1353 ⭐
2. CF 1140C Playlist ⭐
3. Luogu P4053 建筑抢修 ⭐⭐
4. LeetCode 502 IPO
5. LeetCode 630 Course Schedule III

**学完应该掌握：** 优先队列反悔、双堆套路

### 阶段 C：变形与综合（第 3 周）
1. CF 1041C Coffee Break
2. CF 1257D Monster Killing
3. CF 1077F2 Pictures with Kittens
4. LeetCode 1235 Job Scheduling
5. LeetCode 1751 Events II

**学完应该掌握：** 调度 DP、单调队列优化

### 阶段 D：冲刺（第 4 周）
1. CF 865D Buy Low Sell High ⭐⭐
2. CF 436E Cardboard Box
3. CF 730I Olympiad
4. Luogu P2949 Work Scheduling
5. 任选 1 道 1900+ 调度类压轴

---

## 七、调度题三大套路速记

### 套路 1：邻项交换（Exchange Argument）
> "如果交换相邻两个任务结果更优，那当前顺序不是最优。"

用于推出排序的 key。常见 key：
- `a_i / b_i`（国王游戏）
- `a_i + b_i`（流水车间 Johnson：min(a_i, b_j) < min(a_j, b_i)）
- `deadline_i`

### 套路 2：反悔堆（Regret Heap）
> "先尽可能多接任务，超载时把已接的最差任务扔掉。"

- 按 deadline 升序遍历
- 当前任务先入堆
- 若总耗时 > deadline，弹出耗时最大的

### 套路 3：扫描线 + 事件点
> "把区间拆成 (start, +1) 和 (end, -1) 事件，按时间排序处理。"

- 求最大同时存在 → 最大前缀和
- 求最少机器 → 同上
- 求覆盖长度 → 经典扫描线

---

## 八、避坑提醒

1. **贪心的正确性必须证明** —— 不要"感觉对"就交，反例往往就在小数据。
2. **排序的 key 是关键** —— 错一个 key 整道题就废了。先想清楚 `cmp(a, b)` 的传递性。
3. **反悔贪心常被误判为 DP** —— 看见"选 k 个最优"先想堆，再想 DP。
4. **区间调度区分"端点重合算不算重叠"** —— 题目读清楚。
5. **多机调度的 makespan 一般要二分答案 + check**，不是直接贪心。
