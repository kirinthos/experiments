#!/usr/bin/env python

scan_output = []


def compute_coords(index, dim):
    """Computes x/y from an index"""
    return index / dim, index % dim 

    
def compute_index(x, y, dim):
    return (y * dim) + x


def fill(x, y, dim):
    global scan_output
    scan_output[compute_index(x, y, dim)] = 1    

    
def is_filled(scan_output, index):
    return scan_output[index]


def flood_fill(data, dim, x, y):
    open_nodes = []
    walk_order = [(0, -1), (1, 0), (0, 1), (-1, 0)]

    open_nodes.append((x, y))
    while open_nodes:
        next_node = open_nodes.pop()
        fill(x, y, dim)
        for next_step in walk_order:
            nx = x + next_step[0]
            ny = y + next_step[1]
            next_index = compute_index(nx, ny, dim)
            if (0 <= nx < dim) and (0 <= ny < dim) and not is_filled(scan_output, next_index):
                fill(nx, ny, dim)
                open_nodes.append((nx, ny))


def find_land_masses(data, dim):
    """Counts the number of land masses, returns number of land masses"""
    global scan_output
    scan_output = [0] * len(data)
    count = 0
    index = 0
    for element in data:
        if element and not scan_output[index]:
            count += 1
            x, y = compute_coords(index, dim)
            flood_fill(data, dim, x, y)
        index += 1
    
    return count
    
    
def main():
    data = [
        [ 0, 0, 0, 1, 1 ],
        [ 0, 0, 1, 0, 1 ],
        [ 0, 1, 0, 0, 0 ],
        [ 1, 1, 1, 0, 1 ],
        [ 1, 1, 1, 0, 1 ]
    ]
    print(find_land_masses([item for sublist in data for item in sublist], 5))

if __name__ == "__main__":
    main()
