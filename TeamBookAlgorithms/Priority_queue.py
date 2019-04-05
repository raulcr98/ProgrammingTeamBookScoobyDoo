class priority_queue:
    array = []
    heapSize = 0
    
    def __init__(self, arr):
        self.array = arr
        self.heapSize = len(arr)

        i = self.heapSize / 2 - 1
        while i > 0:
            self.top_filter(i)
            i -= 1

    def swap(self, i, j):
        aux = self.array[i]
        self.array[i] = self.array[j]
        self.array[j] = aux

    def push(self, e):
        if self.heapSize < len(self.array):
            self.array[self.heapSize] = e
            self.heapSize += 1
            self.top_filter(self.heapSize)

    def pop(self):
        response = self.array[0]
        self.array[0] = self.array[self.heapSize]
        self.heapSize -= 1
        self.down_filter(0)
        return response

    def top(self):
        response = self.array[0]
        return response

    def down_filter(self, pos):
        #heapify
        l = pos * 2 + 1
        r = pos * 2 + 2
        may = pos

        if l < self.heapSize and self.array[may] > self.array[l]:
            may = l
        if r < self.heapSize and self.array[may] > self.array[r]:
            may = r
        if may != pos:
            self.swap(pos, may)
            self.down_filter(may)

    def top_filter(self, pos):
        i = pos
        while i >= 0:
            padre = (i - 1) / 2

            if self.array[padre] > self.array[i]:
                self.swap(padre, i)
            else:
                break
            
            i = padre
        


