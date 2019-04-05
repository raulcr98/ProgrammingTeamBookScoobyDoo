#extends template.py

def build(self, arr):
    self.array = arr
    self.heapSize = len(arr)

    i = self.heapSize / 2 - 1
    while i > 0:
        self.top_filter(i)
        i -= 1

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
    