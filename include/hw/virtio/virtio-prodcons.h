#ifndef QEMU_VIRTIO_PRODCONS_H
#define QEMU_VIRTIO_PRODCONS_H

#include "hw/virtio/virtio.h"

#define TYPE_VIRTIO_PRODCONS "virtio-prodcons-device"
#define VIRTIO_PRODCONS(obj) \
        OBJECT_CHECK(VirtIOProdcons, (obj), TYPE_VIRTIO_PRODCONS)

typedef struct virtio_pc_conf
{
    int32_t     wc;
    uint32_t    l;
} virtio_pc_conf;

typedef struct VirtIOProdcons {
    VirtIODevice parent_obj;
    struct {
        uint32_t    items;
        uint32_t    kicks;
        uint32_t    interrupts;
        uint64_t    next_dump;
        uint64_t    last_dump;
    } stats;
    int32_t wc;
    VirtQueue *dvq;
    QEMUBH *bh;
    int dvq_pending;
    virtio_pc_conf conf;
    DeviceState *qdev;
} VirtIOProdcons;

#endif
