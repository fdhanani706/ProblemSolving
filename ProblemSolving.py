from collections import Counter

class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2 == 0:
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2
        else:
            return sorted_data[mid]

    def mode(self):
        freq = Counter(self.data)
        max_freq = max(freq.values())
        if max_freq == 1:
            return "No mode"
        modes = [k for k, v in freq.items() if v == max_freq]
        return modes

# Sample usage
data = [1, 3, 3, 6, 7, 8, 9]
stats = StatisticsCalculator(data)

print("Mean:", round(stats.mean(), 2))
print("Median:", round(stats.median(), 2))
print("Mode:", stats.mode())
