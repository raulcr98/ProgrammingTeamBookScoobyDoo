def insertion_sort(self):
    lon = self.get_length()
    for i in range(1, lon):
        j = i
        while j > 0:
            if self.array[j] < self.array[j - 1]:
                self.swap(j, j - 1)
            else:
                break
            j -= 1