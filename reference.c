public class MemoryAllocator {
    private byte[] memory;
    private boolean[] used;

    public MemoryAllocator(int size) {
        memory = new byte[size];   // simulate the memory pool
        used = new boolean[size];  // track used bytes
    }

    // Simulates malloc: returns starting index (pointer) of free block
    public int malloc(int size) {
        for (int i = 0; i <= memory.length - size; i++) {
            boolean blockFree = true;
            for (int j = 0; j < size; j++) {
                if (used[i + j]) {
                    blockFree = false;
                    break;
                }
            }
            if (blockFree) {
                // Mark block as used
                for (int j = 0; j < size; j++) {
                    used[i + j] = true;
                }
                return i; // return index as "pointer"
            }
        }
        throw new OutOfMemoryError("No sufficient memory block available");
    }

    public void free(int pointer, int size) {
        for (int i = 0; i < size; i++) {
            used[pointer + i] = false;
        }
    }

    public void write(int pointer, byte value) {
        memory[pointer] = value;
    }

    public byte read(int pointer) {
        return memory[pointer];
    }
}
