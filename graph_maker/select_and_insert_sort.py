import pandas as pd
import matplotlib.pyplot as plt

data = {
    "Wielkosc tablicy": [1000, 7500, 15000, 45000, 90000, 135000, 180000, 210000, 305000, 400000],
    "Select Sort - Optymistyczny": [0.001, 0.079, 0.282, 2.405, 8.61, 19.13, 33.813, 46.703, 97.405, 178.403],
    "Insert Sort - Optymistyczny": [0, 0, 0, 0, 0.001, 0.001, 0.001, 0.001, 0.001, 0.003],
    "Select Sort - Średni": [0.001, 0.065, 0.248, 2.29, 8.919, 20.262, 36.878, 52.051, 120.689, 216.132],
    "Insert Sort - Średni": [0.001, 0.038, 0.156, 1.308, 5.216, 12.115, 22.39, 31.59, 62.605, 132.199],
    "Select Sort - Pesymistyczny": [0.001, 0.071, 0.276, 2.516, 10.286, 23.192, 41.421, 56.8, 121.132, 208.841],
    "Insert Sort - Pesymistyczny": [0.003, 0.084, 0.337, 2.968, 12.246, 26.785, 47.834, 67.273, 140.919, 247.294],
}

df = pd.DataFrame(data)

plt.figure(figsize=(14, 8))

plt.plot(df["Wielkosc tablicy"], df["Select Sort - Optymistyczny"], label="Select Sort - Optymistyczny", marker='o', color='green')
plt.plot(df["Wielkosc tablicy"], df["Insert Sort - Optymistyczny"], label="Insert Sort - Optymistyczny", linestyle='--', marker='s', color='green')

plt.plot(df["Wielkosc tablicy"], df["Select Sort - Średni"], label="Select Sort - Średni",  marker='^', color='orange')
plt.plot(df["Wielkosc tablicy"], df["Insert Sort - Średni"], label="Insert Sort - Średni", linestyle='--', marker='D', color='orange')

plt.plot(df["Wielkosc tablicy"], df["Select Sort - Pesymistyczny"], label="Select Sort - Pesymistyczny",  marker='x', color='red')
plt.plot(df["Wielkosc tablicy"], df["Insert Sort - Pesymistyczny"], label="Insert Sort - Pesymistyczny", linestyle='--', marker='*', color='red')

plt.title("Porównanie czasów wykonania Select Sort i Insert Sort", fontsize=16)
plt.xlabel("Wielkość tablicy", fontsize=14)
plt.ylabel("Czas wykonania (s)", fontsize=14)
plt.legend(fontsize=12)
plt.grid(True)
plt.xscale("log")
plt.ylim(0, 250) 

plt.tight_layout()
plt.show()