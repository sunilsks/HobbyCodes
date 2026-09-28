// Ring buffer: Essential in embedded systems for DMA, serial communication, logging
struct CircularBuffer {
    uint8_t *buffer;
    uint16_t head;      // Write pointer
    uint16_t tail;      // Read pointer
    uint16_t size;
    uint16_t capacity;
};

void cb_init(struct CircularBuffer *cb, uint16_t capacity) {
    cb->buffer = (uint8_t*)malloc(capacity);
    cb->head = cb->tail = cb->size = 0;
    cb->capacity = capacity;
}

int cb_write(struct CircularBuffer *cb, uint8_t data) {
    if (cb->size >= cb->capacity) return -1;  // Full
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % cb->capacity;
    cb->size++;
    return 0;
}

int cb_read(struct CircularBuffer *cb, uint8_t *data) {
    if (cb->size == 0) return -1;  // Empty
    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->capacity;
    cb->size--;
    return 0;
}

// Useful macros
#define CB_IS_EMPTY(cb) ((cb)->size == 0)
#define CB_IS_FULL(cb) ((cb)->size == (cb)->capacity)
#define CB_AVAILABLE(cb) ((cb)->size)
#define CB_SPACE(cb) ((cb)->capacity - (cb)->size)