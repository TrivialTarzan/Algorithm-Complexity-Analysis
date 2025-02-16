import matplotlib.pyplot as plt


sizes = [ 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 1000000000]

binary_iter = {
    "optymistyczny": [400, 700, 700, 600, 600, 1100, 1300, 1300, 1800, 1400],
    "sredni": [500, 600, 600, 800, 600, 1300, 1600, 1300, 1000, 1400],
    "pesymistyczny": [400, 800, 1100, 900, 21300, 1900, 4200, 1500, 1300, 1900],
}

binary_rec = {
    "optymistyczny": [500, 900, 1400, 1100, 1500, 1500, 2300, 2000, 2000, 1400],
    "sredni": [500, 700, 800, 1000, 3600, 1500, 2100, 2200, 1500, 1900],
    "pesymistyczny": [300, 800, 800, 1500, 1900, 2200, 2800, 2500, 2100, 1600],
}

jump_search = {
    "optymistyczny": [5000, 800, 700, 900, 900, 800, 1200, 1400, 1000, 2700],
    "sredni": [2600, 11700, 32400, 21000, 26600, 159400, 187000, 507600, 626500, 1711700],
    "pesymistyczny": [22100, 11000, 18500, 53100, 958600, 276200, 479200, 1554600, 782000, 4081200],
}

def plot_search_times(sizes, times, title, ylabel):
    plt.figure(figsize=(12, 6))
    for key, values in times.items():
        plt.plot(sizes, values, label=key.capitalize())

    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Rozmiar tablicy")
    plt.ylabel(ylabel)
    plt.title(title)
    plt.legend()
    plt.grid(which="both", linestyle="--", linewidth=0.5)
    plt.show()

plot_search_times(sizes, binary_iter, "Binary Search Iteracyjny - Czasy wyszukiwania", "Czas (nanosekundy)")
plot_search_times(sizes, binary_rec, "Binary Search Rekurencyjny - Czasy wyszukiwania", "Czas (nanosekundy)")
plot_search_times(sizes, jump_search, "Jump Search - Czasy wyszukiwania", "Czas (nanosekundy)")

avg_case = {
    "Binary Search Iter": binary_iter["sredni"],
    "Binary Search Rek": binary_rec["sredni"],
    "Jump Search": jump_search["sredni"],
}
plot_search_times(sizes, avg_case, "Średni przypadek - Porównanie algorytmów", "Czas (nanosekundy)")