import matplotlib.pyplot as plt

n_values = [10, 100, 1000, 10000, 100000]

bubble_opt = [0, 0, 0.001, 0.147, 13.65]
bubble_av = [0, 0, 0.004, 0.409, 47.656]
bubble_pes = [0, 0, 0.005, 0.419, 39.517]

bubble2_opt = [0, 0, 0, 0.001, 0.001]
bubble2_av = [0, 0, 0.004, 0.479, 46.373]
bubble2_pes = [0, 0, 0.005, 0.4, 39.102]

plt.figure(figsize=(12, 8))

plt.plot(n_values, bubble_opt, label="Bubble Sort - Optymistyczny", marker='o', color='green')
plt.plot(n_values, bubble_av, label="Bubble Sort - Średni", marker='s', color='blue')
plt.plot(n_values, bubble_pes, label="Bubble Sort - Pesymistyczny", marker='^', color='red')

plt.plot(n_values, bubble2_opt, label="Bubble Sort 2 - Optymistyczny", linestyle='--', marker='o', color='green')
plt.plot(n_values, bubble2_av, label="Bubble Sort 2 - Średni", linestyle='--', marker='s', color='blue')
plt.plot(n_values, bubble2_pes, label="Bubble Sort 2 - Pesymistyczny", linestyle='--', marker='^', color='red')

plt.xlabel("Rozmiar tablicy (n)")
plt.ylabel("Czas wykonania [s]]")
plt.title("Porównanie czasu wykonania Bubble Sort i Bubble Sort 2")
plt.ylim(0, 50)
plt.xscale('log')
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.show()