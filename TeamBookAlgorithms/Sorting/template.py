class Array:
    array = []
    maxim = 0

    def __init__(self, N):
        for i in range(N):
            self.array.append(0)

    def set_value(self, pos, value):
        self.array[pos] = value
        self.maxim = max(self.maxim, value)

    def append(self, value):
        self.maxim = max(self.maxim, value)
        self.array.append(value)

    def get_length(self):
        return len(self.array)
    
    def swap(self, pos1, pos2):
        a = self.array[pos1]
        self.array[pos1] = self.array[pos2]
        self.array[pos2] = a