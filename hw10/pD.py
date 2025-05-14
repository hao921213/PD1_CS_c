import matplotlib.pyplot as plt
import numpy as np

# 調試：查看資料範圍與樣本
def debug_data(cycles, label):
    if cycles:
        print(f"{label} Cycles Range: {min(cycles)} - {max(cycles)}")
        print(f"Sample {label} Cycles:", cycles[:10])  # 查看前 10 筆資料
    else:
        print(f"{label} Cycles: No data available")

# 讀取數據
with open("operation_cycles.txt", "r") as f:
    lines = f.readlines()

insert_cycles = []
delete_cycles = []
search_cycles = []
mode = None

for line in lines:
    line = line.strip()
    if line == "Insert Cycles:":
        mode = "insert"
    elif line == "Delete Cycles:":
        mode = "delete"
    elif line == "Search Cycles:":
        mode = "search"
    elif line and mode:
        if mode == "insert":
            insert_cycles.append(int(line))
        elif mode == "delete":
            delete_cycles.append(int(line))
        elif mode == "search":
            search_cycles.append(int(line))

# 調試資料
debug_data(insert_cycles, "Insert")
debug_data(delete_cycles, "Delete")
debug_data(search_cycles, "Search")

# 自定義繪製函數，模仿目標圖表樣式
def plot_cycles(cycles, title):
    if not cycles:
        print(f"No data available for {title}")
        return

    # 計算頻率分佈
    bins = np.arange(0, max(cycles) + 50, 50)  # 每 50 個 cycle 一個區間
    hist, bin_edges = np.histogram(cycles, bins=bins)

    # 繪製圖表
    plt.figure(figsize=(8, 6))
    plt.plot(bin_edges[:-1], hist, marker='o', linestyle='-', color='blue')  # 點線連接
    plt.fill_between(bin_edges[:-1], hist, step="pre", alpha=0.3, color='blue')  # 填充

    # 設置背景和網格
    plt.gca().set_facecolor('#d3d3d3')  # 灰色背景
    plt.grid(axis='y', linestyle='--', alpha=0.7)

    # 添加標題與軸標籤
    plt.title(title, fontsize=16)
    plt.xlabel("Clock Cycles", fontsize=12)
    plt.ylabel("Frequency", fontsize=12)

    # 設置 X 軸和 Y 軸範圍
    plt.xlim(0, max(cycles) + 50)
    plt.ylim(0, max(hist) + 10)

    plt.show()

# 繪製每個操作的分佈圖
plot_cycles(insert_cycles, "Insert Cycles Distribution")
plot_cycles(delete_cycles, "Delete Cycles Distribution")
plot_cycles(search_cycles, "Search Cycles Distribution")
