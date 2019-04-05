def selection_sort(self):
    new_array = []
    lon = self.get_length()

    for i in range(lon):
        minim_array = self.maxim
        position = -1
        for j in range(lon):
            if self.array[j] != -1 and self.array[j] < minim_array:
                position = j
                minim_array = self.array[j]
        
        new_array.append(minim_array)
        self.array[position] = -1
    
    self.array = new_array