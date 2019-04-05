def burbuja_sort(self):
    lon = self.get_length()
    for i in range(lon):
        for j in range(1, lon):
            if self.array[j - 1] > self.array[j]:
                self.swap(j, j - 1)