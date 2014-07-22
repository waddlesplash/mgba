#ifndef CIRCLE_BUFFER_H
#define CIRCLE_BUFFER_H

#include "common.h"

struct CircleBuffer {
	void* data;
	size_t capacity;
	size_t size;
	void* readPtr;
	void* writePtr;
};

void CircleBufferInit(struct CircleBuffer* buffer, unsigned capacity);
void CircleBufferDeinit(struct CircleBuffer* buffer);
size_t CircleBufferSize(const struct CircleBuffer* buffer);
size_t CircleBufferCapacity(const struct CircleBuffer* buffer);
void CircleBufferClear(struct CircleBuffer* buffer);
int CircleBufferWrite8(struct CircleBuffer* buffer, int8_t value);
int CircleBufferWrite32(struct CircleBuffer* buffer, int32_t value);
int CircleBufferRead8(struct CircleBuffer* buffer, int8_t* value);
int CircleBufferRead32(struct CircleBuffer* buffer, int32_t* value);
size_t CircleBufferRead(struct CircleBuffer* buffer, void* output, size_t length);
size_t CircleBufferDump(const struct CircleBuffer* buffer, void* output, size_t length);

#endif
