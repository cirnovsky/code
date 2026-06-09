TABLESIZE = 37
PRIME = 13
EMPTY = 0
USED = 1
DELETED = 2

class HashSlot:
    def __init__(self):
        self.key = 0
        self.indicator = EMPTY

def hash1(key):
    return key % TABLESIZE

def hash2(key):
    return (key % PRIME) + 1

def hhh(key, i):
    return (hash1(key) + i*hash2(key))%TABLESIZE
def hash_insert(key, hash_table):
    cnt = 0
    insert = None
    for i in range(TABLESIZE):
        H = hhh(key, i)
        entry = hash_table[H]
        if entry.indicator == EMPTY:
            if insert is None:
                insert = entry
            break
        elif entry.indicator == USED:
            cnt += 1
            if entry.key == key:
                return -1
        else:
            if insert is None:
                insert = entry
    if insert is None:
        return TABLESIZE
    insert.key = key
    insert.indicator = USED
    return cnt
#write your codes here

def hash_delete(key, hash_table):
    cnt = 0
    for i in range(TABLESIZE):
        H = hhh(key, i)
        entry = hash_table[H]
        if entry.indicator == USED:
            cnt += 1
            if entry.key == key:
                entry.indicator = DELETED
                return cnt
        elif entry.indicator == EMPTY:
            return -1
    return -1
#write your codes here


def print_menu():
    print("============= Hash Table ============")
    print("|1. Insert a key to the hash table  |")
    print("|2. Delete a key from the hash table|")
    print("|3. Print the hash table            |")
    print("|4. Quit                            |")
    print("=====================================")
    print("Enter selection: ", end="")
    
def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))

    hash_table = [HashSlot() for _ in range(TABLESIZE)]
    i = 0
    print_menu()
    while i < len(data):
        opt = data[i]
        i += 1

        if opt == 1:
            print("Enter a key to be inserted:")
            if i >= len(data):
                break
            key = data[i]
            i += 1
            comparison = hash_insert(key, hash_table)
            if comparison < 0:
                print("Duplicate key")
            elif comparison < TABLESIZE:
                print(f"Insert: {key} Key Comparisons: {comparison}")
            else:
                print(f"Key Comparisons: {comparison}. Table is full.")
            print("Enter selection: ", end="")
        elif opt == 2:
            print("Enter a key to be deleted:")
            if i >= len(data):
                break
            key = data[i]
            i += 1
            comparison = hash_delete(key, hash_table)
            if comparison < 0:
                print(f"{key} does not exist.")
            elif comparison <= TABLESIZE:
                print(f"Delete: {key} Key Comparisons: {comparison}")
            else:
                print("Error")
            print("Enter selection: ", end="")
        elif opt == 3:
            for j in range(TABLESIZE):
                marker = '*' if hash_table[j].indicator == DELETED else ' '
                print(f"{j}: {hash_table[j].key} {marker}")
            print("Enter selection: ", end="")
        elif opt == 4:
            break
        else:
            continue

if __name__ == "__main__":
    main()     # Writing output to STDOUT
